#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// I can write all in here, but why tho
#include "stack.h"
#include "fileUtils.h"

#ifndef MAX_MEM_SIZE
#define MAX_MEM_SIZE 1024
#endif//MAX_MEM_SIZE

#define VALUE_OUT_OF_BOUNDS  -1
#define MEMORY_OUT_OF_BOUNDS -2

// i'm lazy
typedef unsigned int uint;

int interpretCode(char* code);
int interpretInstruction(char* instruction, unsigned char* ptr, uint index);


int interpretCode (char* code)
{
	// uint  index = 0;

	// set the memory stuff
	unsigned char* memory = malloc(MAX_MEM_SIZE);
	// set all elements in the array to 0
	// NOTE: this is equal to memory = memset(memory, 0, MAX_MEM_SIZE)
	// but I think it looks cleaner
	for (uint i = 0; i < MAX_MEM_SIZE; i++)
		memory[i] = 0;
	uint index = 0;
	while (*code != 0) {
		int res = interpretInstruction(code, memory, index);
		if (res != 0) {
			free(memory);
			return -1;
		}
		code++;
	}
	free(memory);
	putchar('\n');
	return 0;
}

int interpretInstruction (char* instruction, unsigned char* ptr, uint index)
{
	// instead of using some operator junk like (*index)++ or something like that
	// i just prefer to store the value in a variable and then just store it there
	int value = *ptr;
	switch (*instruction)
	{
	case '+':
		// check that the instruction isn't going above tha max value of uchar
		if (value >= 255)
			return VALUE_OUT_OF_BOUNDS;
		*ptr = value + 1;
		break;
	case '-':
		// check that the instruction isn't going below zero
        if (value <= 0) 
			return VALUE_OUT_OF_BOUNDS;
		*ptr = value - 1;
		break;
	case '<':
		// check that the pointer is not going below ptr[0]
		if (index <= 0) 
			return MEMORY_OUT_OF_BOUNDS;
		ptr--;
		index--;
		break;
	case '>':
		// check that the pointer is not going above ptr[MAX_MEM_SIZE]
		if (index >= MAX_MEM_SIZE - 1) 
			return MEMORY_OUT_OF_BOUNDS;
		ptr++;
		index++;
		break;
	case '.': 
		//print to screen
		putchar(*ptr);
		break;
	case ',':
		//get user input
        *ptr = getchar();
		break;
	case '[':
		break;
	case ']':
		break;
	default:
		break;
	}

	return 0;
}


int main(int argc, char** argv)
{
	if (argc == 1) {
		printf("Usage: bfi path\\to\\file\n");
		return 0;
	}
	// open file
	FILE* fp = fopen(argv[1], "r");

	char* code;
	int res = readAll(&code, fp);

	if (res != READALL_OK) exit(res);
	
	interpretCode(code);

	free(code);
	return 0;
}   
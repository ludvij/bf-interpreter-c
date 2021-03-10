#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// I can write all in here, but why tho
#include "fileUtils.h"

#ifndef MAX_MEM_SIZE
#define MAX_MEM_SIZE 1024
#endif//MAX_MEM_SIZE

#define VALUE_OUT_OF_BOUNDS  -1
#define MEMORY_OUT_OF_BOUNDS -2

// i'm lazy
typedef unsigned int uint;


int executeCode(char* code);
int interpretCode(char* code, int offset, unsigned char* memory, int index);

int interpretCode (char* code, int offset, unsigned char* memory, int index)
{
	int origOffset = offset;
	// uint  index = 0;
	while (code[offset] != 0) {
		int value = memory[index];
		switch (code[offset])
		{
			case '+':
				// check that the instruction isn't going above tha max value of uchar
				if (value >= 255)
					return VALUE_OUT_OF_BOUNDS;
				memory[index] = value + 1;
				break;
			case '-':
				// check that the instruction isn't going below zero
				if (value <= 0) 
					return VALUE_OUT_OF_BOUNDS;
				memory[index] = value - 1;
				break;
			case '<':
				// check that the pointer is not going below ptr[0]
				if (index <= 0) 
					return MEMORY_OUT_OF_BOUNDS;
				index--;
				break;
			case '>':
				// check that the pointer is not going above ptr[MAX_MEM_SIZE]
				if (index >= MAX_MEM_SIZE - 1) 
					return MEMORY_OUT_OF_BOUNDS;
				index++;
				break;
			case '.': 
				//print to screen
				putchar(memory[index]);
				int ch;
				break;
			case ',':
				//get user input
				memory[index] = getchar();
				// celan the input stream
				while ((ch = getchar()) != '\n' && ch !=EOF );
				break;
			case '[':
				//? I need to debug this
				if (memory[index] == 0)
					while ((code[offset]) != ']')
						offset++;
				else 
					// offset + 1 to make the loop start at the next index of the loop
					offset = interpretCode(code, offset + 1, memory, index);
				break;
			case ']':
				// not needed to check the loop condition since they will be checked by the start loop
				return origOffset - 2;	
				break;
			default:
				break;
		}
		// if something bad happens this basically sais f**k you
		// in recursion also works since you are coming out of the switch directly
		// to this
		if (offset < 0) {
			return -1;
		}
		offset++;
	}
	return offset;
	
}

int executeCode(char* code)
{
	// set the memory stuff
	unsigned char* memory = malloc(MAX_MEM_SIZE);
	// set all elements in the array to 0
	// NOTE: this is almost equal to memory = memset(memory, 0, MAX_MEM_SIZE)
	// but I think it looks cleaner
	for (uint i = 0; i < MAX_MEM_SIZE; i++)
		memory[i] = 0;

	int res = interpretCode(code, 0, memory, 0);
	if (res < 0){
		free(memory);
		if (res == VALUE_OUT_OF_BOUNDS)
			printf("[ERROR]: some error occured in the increment of decrement of a value\n");
		else if (res == MEMORY_OUT_OF_BOUNDS)
			printf("[ERROR]: some error ocured in the position of the memory pointer\n");
		return -1;
	}
	// add a new line to make the terminal thing start in its own line
	putchar('\n');
	// celanup stuff
	free(memory);
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
	
	executeCode(code);

	free(code);
	return 0;
}   
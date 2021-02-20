#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// I can write all in here, but why tho
#include "stack.h"
#include "fileUtils.h"

#ifndef MAX_MEM_SIZE
#define MAX_MEM_SIZE 1024
#endif//MAX_MEM_SIZE
// i'm lazy
typedef unsigned int uint;

int interpretCode(char* code);
int interpretInstruction(char* instruction, unsigned char* index);


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
    while (*code != 0) {
        interpretInstruction(code, memory);
        code++;
    }
    free(memory);
    return 0;
}

int interpretInstruction (char* instruction, unsigned char* index)
{
    switch (*instruction)
    {
    case '+':
        break;
    case '-':
        break;
    case '<':
        break;
    case '>':
        break;
    case '.':
        break;
    case ',':
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
    
    printf("%s\n", code);

    interpretCode(code);

    free(code);
}   
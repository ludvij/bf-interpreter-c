#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "stack.h"
#include "fileUtils.h"

#ifndef MAX_MEM_SIZE
#define MAX_MEM_SIZE 1024
#endif//MAX_MEM_SIZE

int interpretCode(const char* filePath);
int interpretInstruction(unsigned char instruction, uint32_t index);


int interpretCode (const char* code)
{
    uint32_t  index = 0;
    while (*code != 0) {
        index = interpretInstruction(*code, index);
        code++;
    }
    putchar('\n');
    return 0;
}

int interpretInstruction (unsigned char instruction, uint32_t  index)
{
    switch (instruction)
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
    return index++;
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
    readAll(&code, fp);
    printf("%s\n", code);

    interpretCode(code);

    free(code);
}   
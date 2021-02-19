#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stack.h"

#ifndef MAX_MEM_SIZE
#define MAX_MEM_SIZE 1024
#endif//MAX_MEM_SIZE

int readAll(char** dataPtr, FILE* fp);
int interpretCode(const char* filePath);
int interpretInstruction(unsigned char instruction, uint32_t index);

// quick and dirty readAll method, not posix especific
int readAll(char** dataPtr, FILE* fp)
{
    if (dataPtr == NULL || fp == NULL) {
        perror("Error: ");
        exit(EXIT_SUCCESS);
    }
    // if is there a file error already
    char* data = NULL;
    if (ferror(fp)) {
        exit(EXIT_SUCCESS);
    }
    
    // get file size
    fseek(fp, 0, SEEK_END);
    size_t fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    // get file contents, + 1 to add null terminator at the end
    data = (char*)realloc(data, fsize + 1);

    if (data == NULL) { //check that there aro no errors allocationg memory
        free(data);
        perror("Error: ");
        exit(EXIT_SUCCESS);
    }
    
    fread(data, 1, fsize, fp);
    if (data == NULL) { //check that there aro no errors allocationg memory
        free(data);
        perror("Error: ");
        exit(EXIT_SUCCESS);
    }
    data[fsize] = 0;
    *dataPtr = data;
    // closing operations
    fclose(fp);
    return 0;
}

int interpretCode(const char* code)
{
    uint32_t  index = 0;
    while (*code != 0) {
        interpretInstruction(*code, index);
        code++;
        index++;
    }
    putchar('\n');
    return 0;
}

int interpretInstruction(unsigned char instruction, uint32_t  index)
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
    return 0;
}


int main(int argc, char** argv)
{
    if (argc == 1) {
        printf("Usage: bfi path\\to\\file\n");
        return 0;
    }
    FILE* fp = fopen(argv[1], "r");

    char* code;
    readAll(&code, fp);
    printf("%s\n", code);

    interpretCode(code);

    free(code);
}   
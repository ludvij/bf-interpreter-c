#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// quick and dirty readAll method, not posix especific
// ? should I make this posix especific?
char* readAll(const char* filePath)
{
    FILE* fp = fopen(filePath, "r");
    if (fp == NULL){ //check that there are no errors opening file
        perror("Error: ");
        exit(EXIT_SUCCESS);
    }
    // get file size
    fseek(fp, 0, SEEK_END);
    size_t fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    // get file contents, + 1 to add null terminator at the end
    char* fcontents = (char*)malloc(fsize + 1);
    if (fcontents == NULL) { //check that there aro no errors allocationg memory
        perror("Error: ");
        exit(EXIT_SUCCESS);
    }
    fread(fcontents, 1, fsize, fp);
    fcontents[fsize] = 0;
    // closing operations
    fclose(fp);
    return fcontents;
}


int main(int argc, char** argv)
{
    if (argc == 1) {
        printf("Usage: bfi path\\to\\file\n");
        return 0;
    }
    char* code = readAll(argv[1]);
    printf("%s\n", code);
    free(code);
}   
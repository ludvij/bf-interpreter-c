#include "fileUtils.h"

// quick and dirty readAll method, not posix especific
int readAll (char** dataPtr, FILE* fp)
{
	if (dataPtr == NULL || fp == NULL) {
		perror("Error: ");
		return READALL_INVALID;
	}
	// if is there a file error already
	char* data = NULL;
	if (ferror(fp)) return READALL_ERROR;
	
	// get file size
	fseek(fp, 0, SEEK_END);
	size_t fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	// get file contents, + 1 to add null terminator at the end
	data = (char*)realloc(data, fsize + 1);
	//check that there are no errors allocationg memory
	if (data == NULL) { 
		free(data);
		perror("Error: ");
		return READALL_NOMEM;
	}
	
	fread(data, 1, fsize, fp);
	// check if there are no error in the file
	if (ferror(fp)) {
		free(data);
		return READALL_ERROR;
	}

	data[fsize] = 0;
	*dataPtr = data;
	// closing operations
	fclose(fp);
	return READALL_OK;
}
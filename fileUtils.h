#ifndef FILE_UTIL
#define FILE_UTILS
#include <stdio.h>
#include <stdlib.h>

#define READALL_OK          0 /* Success            */
#define READALL_INVALID    -1 /* Invalid parameters */ 
#define READALL_ERROR      -2 /* Stream error       */
#define READALL_TOOMUCH    -3 /* Too much input     */ // Not used, LOL
#define READALL_NOMEM      -4 /* Out of memory      */

int readAll (char** dataPtr, FILE* fp);

#endif//FILE_UTILS
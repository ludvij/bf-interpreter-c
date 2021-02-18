// stack implementation using a linked list
// original purpose was handling nested loops in bf
// but maybe I can use this later
#ifndef STACK_LL
#define STACK_LL

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_EMPTY INT_MIN
#define FAILED 0
#define SUCCESS 1

// Node struct defintion, I have no idea what I'm doing
typedef struct node node;
typedef node* stack;

int push(stack* st, int value);
int pop(stack* st);
int peek(stack* st);



#endif
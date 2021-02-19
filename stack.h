// stack implementation using a linked list
// original purpose was handling nested loops in bf
// but maybe I can use this later
#ifndef STACK
#define STACK

#include <limits.h>
#include <stdlib.h>

// if you try to pop an empty stack it will return this
#define STACK_EMPTY INT_MIN
// if malloc fails when pushing something to the stack it will return this
#define PUSH_FAILURE 0
// if it succeeds it will return this
#define PUSH_SUCCESS 1

typedef struct node node;
typedef node* stack;

int push(stack* st, int value);
int pop(stack* st);
int peek(stack* st);
void destroysStack(stack* st);


#endif//STACK
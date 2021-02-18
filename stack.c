#include "stack.h"

typedef struct node {
    int value;
    struct node* next;
} node;

int push(stack* st, int value)
{
    node* newnode = malloc(sizeof(node));
    if (newnode == NULL) return FAILED;

    newnode->value = value;
    newnode->next = *st;
    *st = newnode;
    return SUCCESS;
}

int pop(stack* st)
{
    if (*st == NULL) return STACK_EMPTY;

    int res = (*st)->value;
    node* tmp = *st;
    *st = (*st)->next;
    free(tmp);

    return res;
}
int peek(stack* st)
{
    return (*st == NULL) ? STACK_EMPTY : (*st)->value;
}


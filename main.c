#include <stdio.h>
#include "stack.h"


int main()
{
    stack st = NULL;
    for (int i = 0; i < 100; i++)
        push(&st, i);

    int res, i = 0;
    while ((res = pop(&st)) != STACK_EMPTY)
        printf("iteration %d: res = %d\n", i++, res);
}
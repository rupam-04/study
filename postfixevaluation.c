#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

struct stack
{
    int top;
    char items[MAX];
};

void push(struct stack *ps, int x)
{
    if (ps->top == MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    else
    {
        ps->items[++(ps->top)] = x;
    }
}

char peek(struct stack *ps)
{
    if (ps->top == -1)
    {
        return '\0';
    }
    else
    {
        return ps->items[ps->top];
    }
}

char pop

int main()
{
    
    return 0;
}
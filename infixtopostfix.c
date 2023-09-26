#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct stack
{
    char top;
    int a[MAX];
} stack;
void createstack(stack* s)
{
    s->top = -1;
}
void push(stack* s, char c)
{
    s->top++;
    s->a[s->top] = c;
}
void pop(stack* s)
{
    s->top--;
}
int isempty(stack* s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
char peek(stack* s)
{
    return s->a[s->top];
}
int getpriority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
}
void infixtopostfix(char* in, char* po)
{
    stack s;
    createstack(&s);
    while (*in != '\0')
    {
        if (*in == '(')
        {
            push(&s, '('); 
        }
        else if (isalpha(*in))
        {
            *po = *in;
            po++;
        }
        else if (*in == ')')
        {
            while (peek(&s) != '(')
            {
                *po = peek(&s);
                po++;
                pop(&s);
            }
            pop(&s);
        }
        else if (*in == '+' || *in == '-' || *in == '*' || *in == '/')
        {
            while (!isempty(&s) && getpriority(peek(&s)) >= getpriority(*in))
            {
                *po = peek(&s);
                po++;
                pop(&s);
            }
            push(&s, *in);
        }
        in++;
    }
    while (!isempty(&s))
    {
        *po = peek(&s);
        po++;
        pop(&s);
    }
}

int main()
{
    char infix[100], postfix[100];
    printf("Enter infix expression\n");
    scanf("%s", infix);
    infixtopostfix(infix, postfix);
    printf("Postfix expression is %s\n", postfix);
    return 0;
}
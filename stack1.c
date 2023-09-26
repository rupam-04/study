#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct stk
{
    int arr[MAX];
    int top;
} stack;
void init(stack *s)
{
    s->top = -1;
}
int isEmpty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int isFull(stack *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}
void push(stack *s, int x)
{
    if (isFull(s))
    {
        printf("Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = x;
}
void pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Underflow\n");
    }
    else
    {
        int x = s->arr[s->top];
        s->top--;
        printf("Popped value is %d\n", x);
    }
}
void display(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
int main()
{
    int choice;
    stack *s = (stack *)malloc(sizeof(stack));
    init(s);
    do
    {
        printf("Enter 1 to push, 2 to pop, 3 to display, 4 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to push\n");
            int x;
            scanf("%d", &x);
            push(s, x);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            display(s);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 4);
    return 0;
}
#include <stdio.h>
#define MAX 100
void pop(int *top, int *stk)
{
    if (*top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Popped value is %d\n", stk[*top]);
    (*top)--;
    return;
}
void push(int *top, int *stk, int val)
{
    if (*top == MAX - 1)
    {
        printf("Stack is full\n");
        return;
    }
    (*top)++;
    stk[*top] = val;
    return;
}

int main()
{
    int stk[MAX];
    int top = -1;
    printf("Enter 1 to push, 2 to pop, 3 to exit\n");
    int choice;
    scanf("%d", &choice);
    while (choice != 3)
    {
        if (choice == 1)
        {
            int val;
            printf("Enter value to push\n");
            scanf("%d", &val);
            push(&top, stk, val);
        }
        else if (choice == 2)
        {
            pop(&top, stk);
        }
        else
        {
            printf("Invalid choice\n");
        }
        printf("Enter 1 to push, 2 to pop, 3 to exit\n");
        scanf("%d", &choice);
    }
    return 0;
}
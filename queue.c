#include <stdio.h>

void enqueue(int *front, int *rear, int *queue, int val)
{
    if (*rear == 99)
    {
        printf("Queue is full\n");
        return;
    }
    (*rear)++;
    queue[*rear] = val;
    if (*front == -1)
    {
        *front = 0;
    }
    return;
}

void dequeue(int *front, int *rear, int *queue)
{
    if (*front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued value is %d\n", queue[*front]);
    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        (*front)++;
    }
    return;
}

int main()
{
    int queue[100];
    int front = -1, rear = -1;
    printf("Enter 1 to enqueue, 2 to dequeue, 3 to exit\n");
    return 0;
}
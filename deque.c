#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct deque
{
    int arr[MAX];
    int front;
    int rear;
} deque;

void init(deque *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(deque *q)
{
    if (q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

int isFull(deque *q)
{
    if ((q->rear + 1) % MAX == q->front)
        return 1;
    else
        return 0;
}

void enqueueRear(deque *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    else if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
    }
    q->arr[q->rear] = data;
}

void enqueueFront(deque *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    else if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->front = (q->front - 1 + MAX) % MAX;
    }
    q->arr[q->front] = data;
}

void dequeueFront(deque *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    else if (q->front == q->rear)
    {
        printf("Dequeued %d\n", q->arr[q->front]);
        q->front = q->rear = -1;
    }
    else
    {
        printf("Dequeued %d\n", q->arr[q->front]);
        q->front = (q->front + 1) % MAX;
    }
}

void dequeueRear(deque *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    else if (q->front == q->rear)
    {
        printf("Dequeued %d\n", q->arr[q->front]);
        q->front = q->rear = -1;
    }
    else
    {
        printf("Dequeued %d\n", q->arr[q->rear]);
        q->rear = (q->rear - 1 + MAX) % MAX;
    }
}

void display(deque *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        int i = q->front;
        while (i != q->rear)
        {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", q->arr[i]);
    }
}

int main()
{
    deque q;
    init(&q);
    int ch, data;
    while (1)
    {
        printf("1. EnqueueRear\n");
        printf("2. EnqueueFront\n");
        printf("3. DequeueFront\n");
        printf("4. DequeueRear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueueRear(&q, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueueFront(&q, data);
                break;
            case 3:
                dequeueFront(&q);
                break;
            case 4:
                dequeueRear(&q);
                break;
            case 5:
                display(&q);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
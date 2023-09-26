#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct queue
{
    int arr[MAX];
    int front;
    int rear;
} queue;

void init(queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(queue *q)
{
    if (q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

int isFull(queue *q)
{
    if ((q->rear + 1) % MAX == q->front)
        return 1;
    else
        return 0;
}

void enqueue(queue *q, int data)
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

void dequeue(queue *q)
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

void display(queue *q)
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
            printf("%d, ", q->arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", q->arr[i]);
    }
}

int main()
{
    int ch, data;
    queue q;
    init(&q);
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
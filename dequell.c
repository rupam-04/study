#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
} node;

typedef struct deque
{
    node *front, *rear;
} deque;

void init(deque *d)
{
    d->front = d->rear = NULL;
}

void enqueueR(deque *d, int x)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    p->prev = d->rear;
    if (d->rear)
        d->rear->next = p;
    else
        d->front = p;
    d->rear = p;
}

void enqueueF(deque *d, int x)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = x;
    p->prev = NULL;
    p->next = d->front;
    if (d->front)
        d->front->prev = p;
    else
        d->rear = p;
    d->front = p;
}

int dequeueF(deque *d)
{
    int x = d->front->data;
    node *p = d->front;
    d->front = d->front->next;
    if (d->front)
        d->front->prev = NULL;
    else
        d->rear = NULL;
    free(p);
    return x;
}

int dequeueR(deque *d)
{
    int x = d->rear->data;
    node *p = d->rear;
    d->rear = d->rear->prev;
    if (d->rear)
        d->rear->next = NULL;
    else
        d->front = NULL;
    free(p);
    return x;
}

void print(deque *d)
{
    node *p = d->front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int ch, x;
    deque d;
    init(&d);
    while (1)
    {
        printf("1. EnqueueR\n2. EnqueueF\n3. DequeueF\n4. DequeueR\n5. Print\n6. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            enqueueR(&d, x);
            break;
        case 2:
            printf("Enter element: ");
            scanf("%d", &x);
            enqueueF(&d, x);
            break;
        case 3:
            if (d.front)
                printf("Dequeued: %d\n", dequeueF(&d));
            else
                printf("Queue is empty\n");
            break;
        case 4:
            if (d.front)
                printf("Dequeued: %d\n", dequeueR(&d));
            else
                printf("Queue is empty\n");
            break;
        case 5:
            print(&d);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
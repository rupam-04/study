#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue *queue)
{
    return (queue->front == NULL);
}

void insert(struct Queue *queue, int data)
{
    struct Node *node = newNode(data);
    if (isEmpty(queue))
    {
        queue->front = node;
    }
    else
    {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->rear->next = queue->front;
    printf("%d inserted into the queue\n", data);
}

void delete(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
    }
    else
    {
        int data = queue->front->data;
        struct Node *temp = queue->front;
        if (queue->front == queue->rear)
        {
            queue->front = NULL;
            queue->rear = NULL;
        }
        else
        {
            queue->front = queue->front->next;
            queue->rear->next = queue->front;
        }
        free(temp);
        printf("Dequeued %d\n", data);
    }
}

void print(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct Node *temp = queue->front;
        printf("Elements in the queue are: ");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != queue->front);
        printf("\n");
    }
}

int main()
{
    struct Queue *queue = createQueue();
    int choice, data;
    do
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &data);
            insert(queue, data);
            break;
        case 2:
            delete(queue);
            break;
        case 3:
            print(queue);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}

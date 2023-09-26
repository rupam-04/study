#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} ll;

ll *createNode(int data)
{
    ll *newNode = (ll *)malloc(sizeof(ll));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtTail(ll **head, int data)
{
    ll *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    ll *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void reverse(ll **head)
{
    ll *prev = NULL;
    ll *curr = *head;
    ll *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    *head = prev;
}

void display(ll *head)
{
    ll *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    ll *head = NULL;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);
        insertAtTail(&head, data);
    }
    printf("The linked list is: ");
    display(head);
    printf("\n");
    reverse(&head);
    printf("The reversed linked list is: ");
    display(head);
    printf("\n");
    return 0;
}
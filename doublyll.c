#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
} node;
void insertFront(node** head, int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = *head;
    newnode->prev = NULL;
    if (*head != NULL)
        (*head)->prev = newnode;
    *head = newnode;
}
void insertEnd(node** head, int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    node* temp = *head;
    if (*head == NULL)
    {
        newnode->prev = NULL;
        *head = newnode;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}
void insertAtPos(node** head, int data, int pos)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    node* temp = *head;
    if (pos == 1)
    {
        insertFront(head, data);
        return;
    }
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Invalid position\n");
            return;
        }
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}
void deleteFront(node** head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}
void deleteEnd(node** head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node* temp = *head;
    if (temp->next == NULL)
    {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}
void deleteAtPos(node** head, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node* temp = *head;
    if (pos == 1)
    {
        deleteFront(head);
        return;
    }
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Invalid position\n");
            return;
        }
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}
void display(node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int count(node* head)
{
    int c = 0;
    while (head != NULL)
    {
        c++;
        head = head->next;
    }
    return c;
}

int main()
{
    int ch, data, pos;
    node* head = NULL;
    while (1)
    {
        printf("1. Insert at front\n2. Insert at end\n3. Insert at position\n4. Delete from front\n5. Delete from end\n6. Delete from position\n7. Display\n8. Count\n9. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data\n");
            scanf("%d", &data);
            insertFront(&head, data);
            break;
        case 2:
            printf("Enter data\n");
            scanf("%d", &data);
            insertEnd(&head, data);
            break;
        case 3:
            printf("Enter data\n");
            scanf("%d", &data);
            printf("Enter position\n");
            scanf("%d", &pos);
            insertAtPos(&head, data, pos);
            break;
        case 4:
            deleteFront(&head);
            break;
        case 5:
            deleteEnd(&head);
            break;
        case 6:
            printf("Enter position\n");
            scanf("%d", &pos);
            deleteAtPos(&head, pos);
            break;
        case 7:
            display(head);
            break;
        case 8:
            printf("Number of nodes = %d\n", count(head));
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
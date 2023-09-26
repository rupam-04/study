#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} cll;

void create(cll** head)
{
    *head = NULL;
}

void insertAtPos(cll** head, int data, int pos)
{
    cll* new_node = (cll*)malloc(sizeof(cll));
    new_node->data = data;
    if (*head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
        return;
    }
    cll* curr = *head;
    if (pos == 1)
    {
        while (curr->next != *head)
        {
            curr = curr->next;
        }
        curr->next = new_node;
        new_node->next = *head;
        *head = new_node;
        return;
    }
    for (int i = 1; i < pos-1; i++)
    {
        curr = curr->next;
        if (curr == *head)
        {
            printf("Invalid position\n");
            return;
        }
    }
    new_node->next = curr->next;
    curr->next = new_node;
}

void deleteAtPos(cll** head, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    cll* curr = *head;
    if (pos == 1)
    {
        while (curr->next != *head)
        {
            curr = curr->next;
        }
        if (curr == *head)
        {
            *head = NULL;
        }
        else
        {
            curr->next = (*head)->next;
            *head = (*head)->next;
        }
        free(curr);
        return;
    }
    cll* prev = NULL;
    for (int i = 1; i < pos; i++)
    {
        prev = curr;
        curr = curr->next;
        if (curr == *head)
        {
            printf("Invalid position\n");
            return;
        }
    }
    prev->next = curr->next;
    free(curr);
}

void printList(cll* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    cll* curr = head;
    do
    {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}

int main()
{
    cll* head = NULL;
    int choice, data, pos;
    do
    {
        printf("1. Create the list\n");
        printf("2. Insert an element in any position\n");
        printf("3. Delete an element from any position\n");
        printf("4. Print the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                create(&head);
                printf("List created\n");
                break;
            case 2:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position to insert the data: ");
                scanf("%d", &pos);
                insertAtPos(&head, data, pos);
                break;
            case 3:
                printf("Enter the position to delete the data: ");
                scanf("%d", &pos);
                deleteAtPos(&head, pos);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}
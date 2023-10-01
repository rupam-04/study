#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
} ll;

void create(ll** head)
{
    *head = NULL;
}
void display(ll* head)
{
    if (head==NULL)
    {
        printf("Empty\n");
        return;
    }
    ll* p = head;
    while (p!=NULL)
    {
        printf("%d, ", p->data);
        p = p->next;
    }
    printf("\n");
}
int count(ll* head)
{
    if (head==NULL)
    {
        return 0;
    }
    int cnt = 1; 
    ll* p = head;
    while (p->next!=NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}
void insertFront(ll** head, int data)
{
    ll* newnode = (ll*)malloc(sizeof(ll));
    newnode->data = data;
    if (*head == NULL)
    {
        newnode->next = NULL;
        *head = newnode;
        return;
    }
    newnode->next = *head;
    *head = newnode;
}
void insertEnd(ll** head, int data)
{
    ll* newnode = (ll*)malloc(sizeof(ll));
    if (*head==NULL)
    {
        insertFront(head, data);
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    ll* p = *head;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    p->next = newnode;
}
void insertAtPos(ll** head, int data, int pos)
{
    if (pos<1 || pos>count(*head)+1)
    {
        printf("Not valid\n");
        return;
    }
    ll* newnode = (ll*)malloc(sizeof(ll));
    if (*head==NULL || pos==1)
    {
        insertFront(head, data);
        return;
    }
    if (pos==count(*head)+1)
    {
        insertEnd(head, data);
        return;
    }
    ll* p = *head;
    for (int i = 1; i < pos-1; i++)
    {
        p = p->next;
    }
    newnode->next = p->next;
    newnode->data = data;
    p->next = newnode;
}
void deleteFront(ll** head)
{
    if (*head==NULL)
    {
        printf("Empty\n");
        return;
    }
    ll* p = *head;
    *head = p->next;
    free(p);
}
void deleteEnd(ll** head) 
{
    if (*head==NULL)
    {
        printf("Empty\n");
        return;
    }
    if (count(*head)==1)
    {
        deleteFront(head);
        return;
    }
    ll* prev = *head;
    ll* curr = prev->next;
    while (curr->next!=NULL)
    {
        curr = curr->next;
        prev = prev->next;
    }
    prev->next = NULL;
    free(curr);
}
void deleteAtPos(ll** head, int pos)
{
    if (pos<1 || pos>count(*head))
    {
        printf("Invalid\n");
        return;
    }
    if (*head==NULL)
    {
        printf("Empty\n");
        return;
    }
    if (count(*head)==1)
    {
        deleteFront(head);
        return;
    }
    if (count(*head)==pos)
    {
        deleteEnd(head);
        return;
    }
    ll* prev = *head;
    ll* curr = prev->next;
    for (int i = 1; i < pos-1; i++)
    {
        curr = curr->next;
        prev = prev->next;
    }
    prev->next = curr->next;
    free(curr);
}
int main()
{
    ll* head = (ll*)malloc(sizeof(ll));
    create(&head);
    int ch;
    do
    {
        printf("1. Insert Front\n2. Insert End\n3. Insert at position\n4. Delete Front\n5. Delete End\n6. Delete at position\n7. Display\n8. Exit\n9. Count\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data: ");
            int data;
            scanf("%d", &data);
            insertFront(&head, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertEnd(&head, data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            int pos;
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
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtPos(&head, pos);
            break;
        case 7:
            display(head);
            break;
        case 8:
            break;
        case 9:
            printf("%d\n", count(head));
            break;
        default:
            printf("Invalid\n");
            break;
        }
    } while (ch!=8);
    return 0;
}
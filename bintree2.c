#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

typedef struct stack
{
    int top;
    node* arr[100];
} stack;

void createstk(stack *s)
{
    s->top = -1;
}

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert(node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    node *temp = root;
    while (1)
    {
        if (data < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = createNode(data);
                return root;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = createNode(data);
                return root;
            }
            temp = temp->right;
        }
    }
}

void inorder(node *root, stack *s)
{
    if (root == NULL)
        return;
    node *current = root;
    while (current != NULL || s->top != -1)
    {
        while (current != NULL)
        {
            s->arr[++s->top] = current;
            current = current->left;
        }
        current = s->arr[s->top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorder(node *root, stack *s)
{
    if (root == NULL)
        return;
    node *current = root;
    while (current != NULL || s->top != -1)
    {
        while (current != NULL)
        {
            printf("%d ", current->data);
            s->arr[++s->top] = current;
            current = current->left;
        }
        current = s->arr[s->top--];
        current = current->right;
    }
}

void postorder(node *root, stack *s1, stack *s2)
{
    if (root == NULL)
        return;
    s1->arr[++s1->top] = root;
    while (s1->top != -1)
    {
        node *temp = s1->arr[s1->top--];
        s2->arr[++s2->top] = temp;
        if (temp->left)
            s1->arr[++s1->top] = temp->left;
        if (temp->right)
            s1->arr[++s1->top] = temp->right;
    }
    while (s2->top != -1)
    {
        node *temp = s2->arr[s2->top--];
        printf("%d ", temp->data);
    }
}

int main()
{
    stack s1, s2, s3, s4;
    createstk(&s1);
    createstk(&s2);
    createstk(&s3);
    createstk(&s4);
    int ch, data;
    node *root = NULL;
    while (1)
    {
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            inorder(root, &s1);
            break;
        case 3:
            preorder(root, &s2);
            break;
        case 4:
            postorder(root, &s3, &s4);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
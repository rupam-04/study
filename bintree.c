#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void insert(node **root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
        return;
    }
    node *temp = *root;
    while (1)
    {
        if (data < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = createNode(data);
                break;
            }
            else
            {
                temp = temp->left;
            }
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = createNode(data);
                break;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
}

int height(node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main()
{
    int ch, data;
    node *root = NULL;
    while (1)
    {
        printf("1. Insert\n2. Stop\nEnter choice: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter data: ");
            scanf("%d", &data);
            if (root == NULL)
            {
                root = createNode(data);
            }
            else
            {
                insert(&root, data);
            }
        }
        else
        {
            break;
        }
    }
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nHeight: %d\n", height(root));
    return 0;
}
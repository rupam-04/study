#include <stdio.h>
void product(int a[], int b[], int c[], int n1, int n2)
{
    for (int i = 0; i < n1+n2+1; i++)
    {
        c[i] = 0;
    }
    for (int i = 0; i < n1+1; i++)
    {
        for (int j = 0; j < n2+1; j++)
        {
            c[i+j] += a[i]*b[j];
        }
    }
}
int main()
{
    int n1, n2;
    printf("Enter max power in poly 1:\n");
    scanf("%d", &n1);
    printf("Enter max power in poly 2:\n");
    scanf("%d", &n2);
    int a[n1+1], b[n2+1], c[n1+n2];
    printf("Polynomial 1:\n");
    for (int i = 0; i < n1+1; i++)
    {
        printf("Enter coefficient of exponent %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Polynomial 2:\n");
    for (int i = 0; i < n2+1; i++)
    {
        printf("Enter coefficient of exponent %d: ", i);
        scanf("%d", &b[i]);
    }
    product(a, b, c, n1, n2);
    printf("Product is: ");
    for (int i = 0; i < n1+n2+1; i++)
    {
        printf("%dx^%d + ", c[i], i);
    }
}
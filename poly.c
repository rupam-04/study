#include <stdio.h>
#include <stdlib.h>

typedef struct poly
{
    int coeff;
    int exp;
} poly;

int main()
{
    int n1, n2, n3;
    printf("Enter number of terms in polynomial 1 and 2\n");
    scanf("%d%d", &n1, &n2);
    n3 = n1 + n2;
    poly* p1 = (poly*)malloc(n1*sizeof(poly));
    poly* p2 = (poly*)malloc(n2*sizeof(poly));
    poly* p3 = (poly*)malloc(n3*sizeof(poly));
    printf("Enter coefficients and exponents of polynomial 1\n");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d%d", &p1[i].coeff, &p1[i].exp);
    }
    printf("Enter coefficients and exponents of polynomial 2\n");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d%d", &p2[i].coeff, &p2[i].exp);
    }
    int i = 0, j = 0, k = 0;
    while (i<n1 && j<n2)
    {
        if (p1[i].exp > p2[j].exp)
        {
            p3[k] = p1[i];
            i++;
            k++;
        }
        else if (p1[i].exp < p2[j].exp)
        {
            p3[k].coeff = p2[j].coeff;
            p3[k].exp = p2[j].exp;
            j++;
            k++;
        }
        else
        {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            j++;
            k++;
        }
    }
    while (i<n1)
    {
        p3[k].coeff = p1[i].coeff;
        p3[k].exp = p1[i].exp;
        i++;
        k++;
    }
    while (j<n2)
    {
        p3[k].coeff = p2[j].coeff;
        p3[k].exp = p2[j].exp;
        j++;
        k++;
    }
    printf("Resultant polynomial\n");
    for (int i = 0; i < n3; i++)
    {
        printf("%dx^%d + ", p3[i].coeff, p3[i].exp);
    }
    return 0;
}
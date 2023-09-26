#include <stdio.h>
#include <stdlib.h>

void scan(int** m, int nz)
{
    printf("Enter row, column and value\n");
    for (int i = 0; i < nz; i++)
    {
        scanf("%d%d%d", &m[0][i], &m[1][i], &m[2][i]);
    }
}
int** creatematrix(int r, int c)
{
    int** m = (int**)malloc(r*sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        m[i] = (int*)malloc(c*sizeof(int));
    }
    return m;
}

int main()
{
    int** m1, ** m2, ** m3;
    int r, c, nz1, nz2;
    printf("Enter number of rows and columns\n");
    scanf("%d%d", &r, &c);
    m3 = creatematrix(r, c);
    printf("Enter number of non-zero elements in matrix 1 and 2\n");
    scanf("%d%d", &nz1, &nz2);
    m1 = creatematrix(3, nz1);
    m2 = creatematrix(3, nz2);
    printf("1st matrix\n");
    scan(m1, nz1);
    printf("2nd matrix\n");
    scan(m2, nz2);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            m3[i][j] = 0;
        }
    }
    int i = 0, j = 0;
    while (i<nz1 && j<nz2)
    {
        m3[m1[0][i]][m1[1][i]] += m1[2][i];
        m3[m2[0][j]][m2[1][j]] += m2[2][j];
        i++;
        j++;
    }
    while (i<nz1)
    {
        m3[m1[0][i]][m1[1][i]] += m1[2][i];
        i++;
    }
    while (j<nz2)
    {
        m3[m2[0][j]][m2[1][j]] += m2[2][j];
        j++;
    }
    printf("Resultant matrix\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) 
        {
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }
    return 0;
}
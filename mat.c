#include <stdio.h>
#include <stdlib.h>

void print(int** m, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c;j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
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

int** normal_to_sparse(int** m, int r, int c)
{
    int nz = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (m[i][j] != 0)
                nz++;
        }
    }
    int** s = creatematrix(3, nz);
    int k = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (m[i][j] != 0)
            {
                s[0][k] = i;
                s[1][k] = j;
                s[2][k] = m[i][j];
                k++;
            }
        }
    }
    return s;
}

int** transpose(int** m, int nz)
{
    int** mt = creatematrix(3, nz);
    for (int i = 0; i < nz; i++)
    {
        mt[0][i] = m[1][i];
        mt[1][i] = m[0][i];
        mt[2][i] = m[2][i];
    }
    return mt;
}

int main()
{
    int r, c, nz = 0;
    printf("Enter number of rows and columns\n");
    scanf("%d%d", &r, &c);
    int** m = creatematrix(r, c);
    int** ans = creatematrix(c, r);
    printf("Enter matrix\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c;j++)
        {
            scanf("%d", &m[i][j]);
            if (m[i][j] != 0)
            {
                nz++;
            }
        }
    }
    int** s = normal_to_sparse(m, r, c);
    printf("Sparse matrix\n");
    print(s, 3, nz);
    int** mt = transpose(s, nz);
    printf("Transpose of sparse matrix\n");
    print(mt, 3, nz);
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r;j++)
        {
            ans[i][j] = 0;
        }
    }
    int i = 0;
    while (i<nz)
    {
        ans[mt[0][i]][mt[1][i]] = mt[2][i];
        i++;
    }
    print(ans, c, r);
    return 0;
}
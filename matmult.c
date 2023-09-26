#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int** createmat(int r, int c);
void printmat(int **mat, int r, int c);
void multiply(int **mat1, int **mat2, int **res, int r1, int c1, int r2, int c2);
void initmat(int **mat, int r, int c);

int main()
{
    int r1, c1, r2, c2;
    printf("Enter number of rows and columns in first matrix\n");
    scanf("%d%d", &r1, &c1);
    printf("Enter number of rows and columns in second matrix\n");
    scanf("%d%d", &r2, &c2);
    if (c1 != r2)
    {
        printf("Invalid matrices\n");
        return 0;
    }
    int **mat1 = createmat(r1, c1);
    int **mat2 = createmat(r2, c2);
    int **res = createmat(r1, c2);
    initmat(mat1, r1, c1);
    initmat(mat2, r2, c2);
    printmat(mat1, r1, c1);
    printmat(mat2, r2, c2);
    multiply(mat1, mat2, res, r1, c1, r2, c2);
    printmat(res, r1, c2);
    return 0;
}

int** createmat(int r, int c)
{
    int **mat = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        mat[i] = (int *)malloc(c * sizeof(int));
    }
    return mat;
}
void printmat(int **mat, int r, int c)
{
    printf("Matrix is:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return;
}
void multiply(int **mat1, int **mat2, int **res, int r1, int c1, int r2, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return;
}
void initmat(int **mat, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mat[i][j] = rand() % 100;
        }
    }
    return;
}
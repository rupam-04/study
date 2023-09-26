#include <stdio.h>
#include <stdlib.h>

int** createmat(int r, int c)
{
    int **mat = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
        mat[i] = (int *)malloc(c * sizeof(int));
    return mat;
}

int isUpper(int **mat, int r, int c)
{
    for (int i = 1; i < r; i++)
        for (int j = 0; j < i; j++)
            if (mat[i][j] != 0)
                return 0;
    return 1;
}


int isLower(int **mat, int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = i+1; j < c; j++)
            if (mat[i][j] != 0)
                return 0;
    return 1;
}

int main()
{
    int r, c;

    
    printf("Enter number of rows and columns in matrix\n");
    scanf("%d%d", &r, &c);

    
    int **mat = createmat(r, c);

    printf("Enter matrix elements\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);

    if (isUpper(mat, r, c))
        printf("The matrix is upper triangular\n");
    else if (isLower(mat, r, c))
        printf("The matrix is lower triangular\n");
    else
        printf("The matrix is neither upper nor lower triangular\n");

    return 0;
}
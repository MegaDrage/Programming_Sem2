#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void _1task();
void _2task();
void matrix_print(int** matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        printf("Row %i: ", i+1);
        for (int j = 0; j < column; j++)
        {
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}

void in_rand_m(int** matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            matrix[i][j] = 1 + rand()%10;
        }
    }
}
int main ()
{
    srand(time(NULL));
    int key = 0;
    printf("Enter key: ");
    scanf("%i", &key);
    switch (key)
    {
    case 1:
        _1task();
        break;
    case 2:
        _2task();
        break;
        break;
    default:
        break;
    }
    return 0;   
}

void _1task()
{
    int m = 0;
    int n = 5;
    printf("Enter m: ");
    scanf("%i", &m);
    int** B = (int **) malloc(m * sizeof(int));
    int max = -10000000; int r_indx = 0; int c_indx = 0;
    for (int i = 0; i < m; i++)
    {
        B[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            B[i][j] = 1 + rand()%100;
            if (B[i][j] > max)
            {
                max = B[i][j];
                r_indx = j;
                c_indx = i;
            }
        }
    }
    //Delete
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[i * (i != c_indx)][r_indx] = 0;
            if (i == c_indx)
            {
                B[i][j] = 0;
            }
        }
    }
    //C introduce
    int** C = malloc((m - 1) * sizeof(int));
    for (int i = 0; i < m - 1; i++)
    {
        C[i] = malloc((n - 1) * sizeof(int));
    }
    r_indx = 0; c_indx = 0;
    printf("%i %i\n", r_indx, c_indx);
    for (int i = 0; i < m; i++)
    {
        c_indx = 0;
        for (int j = 0; j < n; j++)
        {
            C[r_indx][c_indx] = B[i][j] * (B[i][j] != 0);
            c_indx += (B[i][j] != 0);
        }
        r_indx += (c_indx != 0);
    }
    matrix_print(B, m, n);
    for (int i = 0; i < m; i++)
    {
        free(B[i]);
    }
    free(B);
    printf("C: \n");
    matrix_print(C, m-1, n-1);
    for (int i = 0; i < m - 1; i++)
    {
        free(C[i]);
    }
    free(C);
    return;
}

void _2task()
{
    int m, n;
    printf("Enter m: "); scanf("%i", &m);
    printf("Enter n: "); scanf("%i", &n);
    int** A = malloc(m * sizeof(int));
    for (int i = 0; i< m; i++)
    {
        A[i] = malloc(n * sizeof(int));
    }
    in_rand_m(A, m, n);
    int* sum_row;
    int* sum_col;
    sum_row = malloc(m * sizeof(int));
    sum_col = malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        sum_col[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        sum_row[i] = 0;
        for (int j = 0; j < n; j++)
        {
            sum_row[i] += A[i][j];
            sum_col[j] += A[i][j];
        }
    }
    sum_col[n] = 0;
    matrix_print(A, m, n);
    int** D = malloc((m + 1) * sizeof(int));
    for (int i = 0; i < m + 1; i++)
    {
        D[i] = malloc((n + 1) * sizeof(int));
    }
    int sum_ind = 0; int sum_ind2 = 0; int sum = 0;
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i != m && j != n)
            {
                D[i][j] = A[i][j];
                sum += A[i][j];
            }
            else if (j == n && i != m)
            {
                D[i][j] = sum_row[sum_ind];
                sum += sum_row[sum_ind];
                sum_ind++;
            }
            else
            {
                D[i][j] = sum_col[sum_ind2];
                sum += sum_col[sum_ind2];
                sum_ind2++;
            }
        }
    }
    D[m][n] = sum;
    matrix_print(D, m + 1, n + 1);
    for (int i = 0; i < m + 1; i++)
    {
        free(A[i]);
    }
    for (int i = 0; i < m + 1; i++)
    {
        free(D[i]);
    }
    free(A);
    free(sum_row);
    free(sum_col);
    free(D);
    return;
}
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>


void printmas(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i ", A[i]);
    }
    printf("\n");
}

void fillrand(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = 1 + rand()%15;
    }
}

void print2d(int** A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < A[i][0]; j++)
        {
            printf("%i\t", A[i][j]);
        }
        printf("\n");
    }
}
void fillrand2d(int** A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < A[i][0] - 1; j++)
        {
            A[i][j + 1] = 1 + rand()%10;
        }
    }
}

void HeapMake(int* A, int n, int left)
{
    int x = A[left];
    int i = left;
    while(1)
    {
        int j = 2*i;
        if (j > n)
        {
            break;
        }

        if ((j < n - 1) && A[j + 1] <= A[j])
        {
            j++;
        }

        if (x <= A[j])
        {
            break;
        }
        A[i] = A[j];
        i = j;
    }
    A[i] = x;
}
int BinSearch(int* A, int n, int key)
{
    int L = 0;
    int c = 0;
    int R = n - 1;
    while(L < R)
    {
        int m = (L + R) / 2;
        c++;
        if (A[m] > key)
        {
            L = m + 1;
        }
        else
        {
            R = m;
        }
    }
    if (A[R] == key)
    {
        printf("FOUND: %i\n", A[R]);
    }
    else
    {
        printf("NOT\n");
    }
    printf("C: %i\n", c);
}

void findnum(int* A, int n, int key)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        c++;
        if(A[i] == key)
        {
            printf("Found: %i\n", A[i]);
            printf("C: %i\n", c);
            break;
        }
    }
}

using namespace std;
void _1task(int* A, int n);
void _2task(int** A, int n, int* sum);
void _3task(int* A, int n);
int main()
{
    srand(time(NULL));
    int n = 50; int Arr[n];
    printf("|||_1task|||\n");
    fillrand(Arr, n);
    _1task(Arr, n);
    printf("|||_2task|||\n");
    n = 5;
    int** _2DARR = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        int rn = (2 + rand()%9);
        _2DARR[i] = (int*)malloc(rn * sizeof(int)); _2DARR[i][0] = rn;
    }
    fillrand2d(_2DARR, n);
    int sum[n];
    _2task(_2DARR, n, sum);
    print2d(_2DARR, n);
    printmas(sum, n);
    for (int i = 0; i < n; i++)
    {
        free(_2DARR[i]);
    }
    free(_2DARR);
    printf("|||_3task|||\n");
    int A1[100];
    int A2[1000];
    fillrand(A1, 100);
    fillrand(A2, 1000);
    _3task(A1, 100);
    _3task(A2, 1000);
    BinSearch(A1, 100, 10);
    BinSearch(A2, 1000, 10);
    findnum(A1, 100, 10);
    findnum(A1, 1000, 10);
    return 0;
}

void _1task(int* A, int n)
{
    int min = A[0];
    int predmin = A[0];
    //find min and min2;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < min)
        {
            predmin = min;
            min = A[i];
        }
        else if (A[i] < predmin)
        {
            predmin = A[i];
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (A[i - 1] == min)
        {
            if (A[i + 1] == predmin)
            {
                A[i] = 0;
            }
        }
        if (A[i - 1] == predmin)
        {
            if (A[i + 1] == min)
            {
                A[i] = 0;
            }
        }
    }
    printf("MIN: %i\nPREDMIN:%i\n", min, predmin);
    printmas(A, n);
    return;
}

void _2task(int** A, int n, int* sum)
{
    for (int i = 0; i < n; i++)
    {
        sum[i] = 0;
        for (int j = 0; j < A[i][0]; j++)
        {
            sum[i] += A[i][j];
        }
    }
    return;
}

void _3task(int* A, int n)
{
    int L = n / 2;
    while (L >= 0)
    {
        HeapMake(A, n, L);
        L--;
    }
    int R = n - 1;
    while (R > 1)
    {
        swap(A[0], A[R]);
        R--;
        HeapMake(A, R, 0); 
    }
    return;
}
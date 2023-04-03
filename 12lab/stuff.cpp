#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int med(int* A, long long L, long long R)
{
    if (A[L] > A[(L + R) / 2])
    {
        if (A[R] > A[L])
        {
            return A[L];
        }
        return (A[(L + R)/ 2] > A[R]) ? A[(L + R) / 2] : A[R];
    }
    if (A[R] > A[(L + R) / 2])
    {
        return A[(L + R) / 2];
    }
    return (A[L] > A[R]) ? A[L] : A[R]; 

}

double medf(double* A, long long L, long long R)
{
    if (A[L] > A[(L + R) / 2])
    {
        if (A[R] > A[L])
        {
            return A[L];
        }
        return (A[(L + R)/ 2] > A[R]) ? A[(L + R) / 2] : A[R];
    }
    if (A[R] > A[(L + R) / 2])
    {
        return A[(L + R) / 2];
    }
    return (A[L] > A[R]) ? A[L] : A[R]; 

}

void swapArrElem(int* A, int* B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

void swapArrElemd(double* A, double* B)
{
    double temp = *A;
    *A = *B;
    *B = temp;
}
void fillinc(auto* A, long long n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = i+1; 
    }
}
void filldec(auto* A, long long n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = n - 1 - i+1;
    }
}

void fillrandint(int* A, long long n)
{
    srand(time(NULL));
    for (long long i = 0; i < n; i++)
    {
        A[i] = rand()%100;
    }
}

void fillrandfloat(double* A, long long n)
{
    srand(time(NULL));
    for (long long i = 0; i < n; i++)
    {
        A[i] = rand()%100/15;
    }
}
int checksum(auto* A, long long n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    return sum;
}
int runnumber(auto* A, long long n)
{
    int seria = 0;
    int lenght = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i+1])
        {
            seria++;
        }
 
    }
    return seria+1;
}
void printmas(auto* A, long long n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i ", A[i]);
    }
    printf("\n");
}

double timer(long long (*f)(int* , long long), int* A, long long n)
{
    fillrandint(A, n);
    long long spent_time = f(A, n);
    return spent_time/1000.;
}

double timer(long long (*f)(int* , long long, long long), int* A, long long n)
{
    fillrandint(A, n);
    long long spent_time = f(A, 0, n);
    return spent_time/1000.;
}

double timer(long long (*f)(double* , long long, long long), double* A, long long n)
{
    fillrandfloat(A, n);
    long long spent_time = f(A, 0, n);
    return spent_time/1000.;
}

double timer(long long (*f)(double* , long long), double* A, long long n)
{
    fillrandfloat(A, n);
    long long spent_time = f(A, 0);
    return spent_time/1000.;
}
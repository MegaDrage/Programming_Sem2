#include <time.h>
#include "stuff.h"
#include <math.h>

long long QuickSort(int* A, long long L, long long R)
{
    long long start_time = clock();
    while (L < R)
    {
        int x = med(A, L, R);
        long i = L;
        long j = R;
        while (i <= j)
        {
            while (A[i] < x)
            {
                i++;
            }
            while (A[j] > x)
            {
                j--;
            }
            if (i <= j)
            {
                swapArrElem(&A[i], &A[j]);
                i++;
                j--;
            }
        }
        if (j - L > R - i)
        {
            QuickSort(A, L, j);
            L = i;
        }
        else
        {
            QuickSort(A, i, R);
            R = j;
        }
    }
    long long end_time = clock();
    return end_time - start_time;
}

long long QuickSort(double* A, long long L, long long R)
{
    long long start_time = clock();
    while (L < R)
    {
        int x = medf(A, L, R);
        long i = L;
        long j = R;
        while (i <= j)
        {
            while (A[i] < x)
            {
                i++;
            }
            while (A[j] > x)
            {
                j--;
            }
            if (i <= j)
            {
                swapArrElemd(&A[i], &A[j]);
                i++;
                j--;
            }
        }
        if (j - L > R - i)
        {
            QuickSort(A, L, j);
            L = i;
        }
        else
        {
            QuickSort(A, i, R);
            R = j;
        }
    }
    long long end_time = clock();
    return end_time - start_time;
}

long long SelectSort(int* A, long long size)
{
    int k = 0;
    long i = 0;
    long j = 0;
    long long start_time = clock();
    for (i = 0; i < size; i++)
    {
        k = i;
        for (j = i+1; j < size; j++)
        {
            if (A[k] > A[j])
            {
                k = j;
            }
        }
        if (i != k)
        {
	        swapArrElem(&A[i], &A[k]);
    	}
    }
    long long end_time = clock();
    return end_time - start_time;
}

long long SelectSort(double* A, long long size)
{
    int k = 0;
    long i = 0;
    long j = 0;
    long long start_time = clock();
    for (i = 0; i < size; i++)
    {
        k = i;
        for (j = i+1; j < size; j++)
        {
            if (A[k] > A[j])
            {
                k = j;
            }
        }
        if (i != k)
        {
	        swapArrElemd(&A[i], &A[k]);
    	}
    }
    long long end_time = clock();
    return end_time - start_time;
}

long long BubbleSort(int* A, long long size)
{
    long long start_time = clock();
    for (long i = 0; i < size; i++)
    {
        for (long j = size - 1; j > 0; j--)
        {
            if(A[j] < A[j - 1])
            {
                swapArrElem(&A[j], &A[j - 1]);
            }
        }
    }
    long long end_time = clock();
    return end_time - start_time;
}

long long BubbleSort(double* A, long long size)
{
    long long start_time = clock();
    for (long i = 0; i < size; i++)
    {
        for (long j = size - 1; j > 0; j--)
        {
            if(A[j] < A[j - 1])
            {
                swapArrElemd(&A[j], &A[j - 1]);
            }
        }
    }
    long long end_time = clock();
    return end_time - start_time;
}
long long ShakerSort(int* A, long long size)
{
    long long start_time = clock();
    long L = 0;
    long R = size - 1;
    long k = size - 1;
    do
    {
        for (int j = R; j > L; j--)
        {
            if (A[j] < A[j - 1])
            {
                swapArrElem(&A[j], &A[j - 1]);
                k = j;
            }
        }
        L = k;
        for (int j = L; j < R; j++)
        {
            if (A[j] > A[j + 1])
            {
                swapArrElem(&A[j], &A[j + 1]);
                k = j;   
            }
        }
        R = k;
    } while(L < R);
    long long end_time = clock();
    return end_time - start_time;
}

long long ShakerSort(double* A, long long size)
{
    long long start_time = clock();
    long L = 0;
    long R = size - 1;
    long k = size - 1;
    do
    {
        for (int j = R; j > L; j--)
        {
            if (A[j] < A[j - 1])
            {
                swapArrElemd(&A[j], &A[j - 1]);
                k = j;
            }
        }
        L = k;
        for (int j = L; j < R; j++)
        {
            if (A[j] > A[j + 1])
            {
                swapArrElemd(&A[j], &A[j + 1]);
                k = j;   
            }
        }
        R = k;
    } while(L < R);
    long long end_time = clock();
    return end_time - start_time;
}

long long InsertSort(int* A, long long size)
{
    long long start_time = clock();
    for (long i = 0; i < size; i++)
    {
        int t = A[i];
        long j = i - 1;
        while (j > 0 && t < A[j])
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = t;
    }
    long long end_time = clock();
    return end_time - start_time;
}

long long InsertSort(double* A, long long size)
{
    long long start_time = clock();
    for (long i = 0; i < size; i++)
    {
        int t = A[i];
        long j = i - 1;
        while (j > 0 && t < A[j])
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = t;
    }
    long long end_time = clock();
    return end_time - start_time;
}

long long ShellSort(int* A, long long size)
{
    long long t, j;
    long k = 1;
    long long start_time = clock();
    for (int i = 1; i < log(size) - 1; i++) {
		k = 2 * k + 1;
	}
    for (k; k > 0; k = (k - 1) / 2)
    {
        for (int i = k; i < size; i++)
        {
            t = A[i];
            for (j = i; j >= k && A[j - k] > t; j -= k)
            {
                A[j] = A[j - k];
            }
            A[j] = t;
        }
    }
    long long end_time = clock();
    return end_time - start_time;
}

long long ShellSort(double* A, long long size)
{
    long long t, j;
    long k = 1;
    long long start_time = clock();
    for (int i = 1; i < log(size) - 1; i++) {
		k = 2 * k + 1;
	}
    for (k; k > 0; k = (k - 1) / 2)
    {
        for (int i = k; i < size; i++)
        {
            t = A[i];
            for (j = i; j >= k && A[j - k] > t; j -= k)
            {
                A[j] = A[j - k];
            }
            A[j] = t;
        }
    }
    long long end_time = clock();
    return end_time - start_time;
}

void HeapMake(int* A, long long n, long long left)
{
    int x = A[left];
    long i = left;
    while(1)
    {
        int j = 2 * i;
        if (j > n)
        {
            break;
        }
        if ((j < n - 1) && (A[j + 1] >= A[j]))
        {
            j++;
        }
        if (x >= A[j])
        {
            break;
        }
        A[i] = A[j];
        i = j;
    }
    A[i] = x;
    return;
}

void HeapMaked(double* A, long long n, long long left)
{
    int x = A[left];
    long i = left;
    while(1)
    {
        int j = 2 * i;
        if (j > n)
        {
            break;
        }
        if ((j < n - 1) && (A[j + 1] >= A[j]))
        {
            j++;
        }
        if (x >= A[j])
        {
            break;
        }
        A[i] = A[j];
        i = j;
    }
    A[i] = x;
    return;
}

long long HeapSort(int* A, long long n)
{
    long long start_time = clock();
    long long L = floor(n / 2);
    while (L >= 0)
    {
        HeapMake(A, n, L);
        L--;
    }
    int R = n - 1;
    while(R > 1)
    {
        swapArrElem(&A[0], &A[R]);
        R--;
        HeapMake(A, R, 0);
    }
    long long end_time = clock();
    return end_time - start_time;
}

long long HeapSort(double* A, long long n)
{
    long long start_time = clock();
    long long L = floor(n / 2);
    while (L >= 0)
    {
        HeapMaked(A, n, L);
        L--;
    }
    int R = n - 1;
    while(R > 1)
    {
        swapArrElemd(&A[0], &A[R]);
        R--;
        HeapMaked(A, R, 0);
    }
    long long end_time = clock();
    return end_time - start_time;
}

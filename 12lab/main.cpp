#include <iostream>
#include <time.h>
#include "sorts.h"
#include "stuff.h"

int main()
{
    long long n = 100000;
    int* B = (int*)malloc(n * sizeof(int));
    double* A = (double*)malloc(n * sizeof(double));
    double time = timer(QuickSort, A, n);
    printf("Time: %fs\n", time);    
    time = timer(HeapSort, B, n);
    printf("Time: %fs", time);    
    free(B);
    free(A);
    return 0;
}
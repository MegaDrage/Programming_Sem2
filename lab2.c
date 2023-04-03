#include <stdio.h>
#include <stdlib.h>

int _1task(int n);
int _2task(int* A, int arraysize, int mv);
int _3task(int num);
int main(void)
{
    int key = 0;
    int n = 3;
    int A[] = {-1,2,-3,4,-5,6};
    int i = 0;
    int flag = 0;
    int size_ofA = 6;
    int number = 1028;
    int order = 1;
    int rn = 0;
    printf("Enter key: ");
    scanf("%i", &key);
    switch (key)
    {
    case 1:
        _1task(n);
        break;
    case 2:
        _2task(A, size_ofA, i);
        break;
    case 3:
        _3task(number);
        break;
    default:
        break;
    }
}

int _1task(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        scanf("%i", &n);
        _1task(n);
    }

    if (n > 0)
    {
        printf("Num: %i\n", n);
    }
}

int _2task(int* A, int arraysize, int mv)
{
    if (arraysize == 0)
    {
        return 0;
    }
    
    else if (A[mv] < 0)
    {
        printf("A neg: %i\n", A[mv]);
        _2task(A, arraysize - 1, mv + 1);
    }

    else
    {
        _2task(A, arraysize - 1, mv + 1);
    }

    if (A[mv] > 0)
    {
        printf("A pos: %i\n", A[mv]);
    }
    

}

int _3task(int num)
{
    if (num <= 0)
    {
        return 0;
    }
    else
    {
        _3task(num / 2);
    }
    printf("%i", num%2);
}
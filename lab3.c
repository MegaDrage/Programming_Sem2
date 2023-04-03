#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void _1task();
void _2task();
void _3task();
void swap (double** A, double** B)
{
    double* temp = *A;
    *A = *B;
    *B = temp;
}
void SelectSort (double** asc, int n)
{
    int min_idx = 0;
    for (int i = 0; i < n; i++)
    {
        min_idx = i;
        for (int j = i+1; j < n; j++)
        {
            if (*asc[min_idx] > *asc[j])
            {
                min_idx = j;
            }
        }
        if (i != min_idx)
        {
            swap(&asc[i], &asc[min_idx]);
        }
    }
}
int main (void)
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
    case 3:
        _3task();
        break;
    default:
        break;
    }
    return 0;   
}

void _1task ()
{
    int n = 0;
    printf("Enter your size of array: ");
    scanf("%i", &n);
    int* b; int* c; int* d;
    b = (int *) malloc(n * sizeof(int));
    if (b == NULL)
    {
        printf("Cannot give memory\n");
        return;
    }
    int m = 0; int k = 0;
    for (int i = 0; i < n; i++)
    {
        b[i] = -50 + rand()%100;
        m += (b[i] > 0);
        k += (b[i] < 0);
    }
    c = (int *) malloc(m * sizeof(int));

    if (c == NULL)
    {
        printf("Cannot give memory\n");
        return;
    }
    d = (int *) malloc(k * sizeof(int));

    if (d == NULL)
    {
        printf("Cannot give memory\n");
        return;
    }
    int j = 0;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        c[j] = b[i] * (b[i] > 0);
        j += 1 * (b[i] > 0);
        d[l] = b[i] * (b[i] < 0);
        l += 1 * (b[i] < 0);
    }
    for (j = 0; j < m; j++)
    {
        printf("Positive: %i ", c[j]);
    }
    printf("\n");
    for (l = 0; l < k; l++)
    {
        printf("Negative: %i ", d[l]);
    }
    free(b);
    free(d);
    free(c);
    return;
}

void _2task ()
{
    double* a;
    int n = 0;
    printf("Enter your size of array: ");
    scanf("%i", &n);
    double* b[n];
    a = (double *) malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        a[i] = 1/2. + rand()%10;
        b[i] = &a[i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%f\n", a[i]);
    }
    SelectSort(b, n);
    printf("sorted\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f\n", *b[i]);
    }
    free(a);
    return;
}

void _3task ()
{
    int n = 0;
    printf("Enter your size of array: ");
    scanf("%i", &n);
    int num = 0;
    int* dyn_er = (int* ) malloc((n + 1) * sizeof(int));
    char* dyn_bool = (char*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n + 1; i++)
    {
        dyn_er[i] = i;
        dyn_bool[i] = 1;
    }
    dyn_bool[0] = dyn_bool[1] = 0;
    int p = 2;
    int j = 0;
    int zeros = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (dyn_bool[i])
        {
            if (i * 1ll * i <= n)
            {
                for (j = i * i; j <= n; j+= i)
                {
                    dyn_bool[j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        zeros+= (dyn_bool[i] == 0);
    }
    int buffersize = n + 1 - zeros;
    int k = 0;
    int* buffer = (int* ) malloc(buffersize * sizeof(int));
    for (int i = 0; i < n + 1; i++)
    {
        buffer[k] = dyn_er[i] * (dyn_bool[i] != 0);
        k += (dyn_bool[i] != 0);
    }
    for (int i = 0; i < buffersize; i++)
    {
        printf("Numberzbuff: %i\n", buffer[i]);
    }
    free(dyn_er);
    free(buffer);
    return;
}
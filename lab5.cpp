#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void _1task();
void _2task();
void printArr(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Arr : " << A[i];
    }
}
void printMatrix_(int** A, int row)
{
    int col = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << A[i][j] << " ";
        }
        col++;
        cout << "\n";
    }
}
int main()
{
    int key = -1;
    while (key != 0)
    {
        cout << "Enter Key ";
        cin >> key;
        switch (key)
        {
        case 1:
            _1task();
            break;
        case 2:
            _2task();
        default:
            break;
        }
    }
}

void _1task()
{
    return;
}

void _2task()
{
    int** A = (int** ) malloc(9 * sizeof(int));
    int k = 1;
    for (int i = 0; i < 9; i++)
    {
        A[i] = (int* )malloc((k)* sizeof(int));
        A[i][0] = k;
        for (int j = 1; j < k; j++)
        {
            A[i][j] = A[i][0] * A[j][0];
        }
        k++;
    }
    printMatrix_(A, 9);
    return;
}
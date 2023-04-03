#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
void _1task();
void _2task();
int main()
{
    int key = -1;
    while (key != 0)
    {
        cout << "Enter Key: ";
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
int triangle(int a, int b, int c, int* perimetr, double* square)
{
    char flag = 0;
    if (a + b > c)
    {
        flag++;
    }
    if (a + c > b)
    {
        flag++;
    }
    if (b + c > a)
    {
        flag++;
    }
    double p = (a+b+c)/2;
    *square = sqrt((p-a)*(p-b)*(p-c));
    *perimetr = a + b + c;
    if (flag < 3)
    {
        return 0;
    } 
    if (flag == 3)
    {
        return 1;
    }
}

int fact(int size)
{
    if (size == 0)
    {
        return 1;
    }
    return size * fact(size - 1); 
}

int soch(int& n, int& m)
{
    return fact(n)/(fact(m) * fact(n - m));
}

double pd(int& n, int& m, float& p, float& q)
{
    double _pd = soch(n, m) * pow(p, m) * pow(q, n - m);
    return _pd;
}

double pm(int& n, int& m, float& p, float& q)
{
    double _pm = soch(n, m) * pow(q, m) * pow(p, n - m);
    return _pm;
}
void _1task()
{
    int x = 10;
    int y = 20;
    int z = 15;
    int perim;
    double square;
    printf("%i\n", triangle(x,y,z, &perim, &square));
    printf("%i\n", perim);
    printf("%f\n", square);
    return;
}

void _2task()
{
    int n = 5;
    int m = 3;
    float p = 0.45;
    float q = 1 - p;
    printf("Devochki: %f\n", pd(n, m, p, q));
    printf("Malchiki: %f\n", pm(n, m, p, q));
    return;
}
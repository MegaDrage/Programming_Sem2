#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void _1task();
float _2task(int n, float x);
float _3task(int x);

int main(void)
{
    int key = 0;
    int n = -10;
    int x = 2;
    float y = 0;
    float cos_ = 0;
    printf("Enter key: ");
    scanf("%i", &key);
    switch (key)
    {
    case 1:
        _1task();
        break;
    case 2:
        y = _2task(n, x);
        printf("Y: %f\n", y);
        break;
    case 3:
        x = 1;
        cos_ = _3task(x);
        printf("cos: %f ", cos_);
        printf("cos: %f", cos(x));
        break;
    default:
        break;
    }

    return 0;
}

int gauss(int year)
{
    int a,b,c,d,e,f;
    a = year%19;
    b = year%4;
    c = year%7;
    d = (19*a + 15)%30;
    e = (2*b + 4*c + 6*d + 6)%7;
    f = d + e;
    (f > 26)? printf("%i May\n",26): printf("%i April\n",4 + f);

}
void _1task()
{
    int year_ofpascha = 2000;
    gauss(year_ofpascha);
    return;
}

float _2task(int n, float x)
{
    float result = 1;
    for (int i = 0; i < abs(n); i++)
    {
        result *= x * (n >= 0) + (1/x) * (n < 0);
    }
    return result;
}
float fact(int n)
{
    float factor = 1;
    for (int i = n; i > 0; i--)
    {
        factor*= i;
    }
    return factor;
}
float _3task(int x)
{
    float eps = 0.0001; // (-1^n)*(x^2n)/2n!;
    int n = 0;
    float step = ((_2task(n,-1))*(_2task(2*n,x)))/(fact(2*n));
    printf("%f\n", step);
    float result = step;
    while(fabs(step) >= eps)
    {
        n++;
        step = (_2task(n,-1.))*((_2task(2*n,x))/(fact(2*n)));
        printf("step: %f\n", fabs(step));
        result += step; 
    }
    return result;
}
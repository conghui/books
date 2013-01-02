#include <stdio.h>
#include <assert.h>

static inline double f(double x);
static double trap(double a, double b, double n, double h);

int main(void)
{
    double integral;   /* store result in integral      */
    double a;          /* left end point                */
    double b;          /* right end point               */
    double h;          /* hight of each small trapezoid */
    int    n;          /* # of trapezoids               */

    printf("Enter a, b, and n: ");
    assert(scanf("%lf%lf%d", &a, &b, &n) == 3);

    h        = (b - a) / n;
    integral = trap(a, b, n, h);

    printf("With n = %d trapezoids, our estimate "
           "of the integral from %f to %f = %f\n",
           n, a, b, integral);

    return 0;
}

static inline double f(double x)
{
    return x * x;
}

static double trap(
    double a,
    double b,
    double n,
    double h)
{
    double integral; /* store result in integral */
    double x;
    int i;

    integral = (f(a) + f(b)) / 2.0;
    x        = a;

    for (i = 1; i <= n - 1; i++) {
        x        += h;
        integral += f(x);
    }

    integral *= h;
    return integral;
}

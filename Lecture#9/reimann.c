#include <stdio.h>

float f(float x);
float Reimann(int n, float a, float b);

int main()
{
    printf("%f\n", Reimann(100, -1.0f, 1.0f)); 

    return 0;
}

/* f(x) = x*x+2x+3 */
float f(float x)
{
    return (x * x + 2 * x + 3);
}

/* compute integral of f(x) = x*x+2x+3 on [a,b] */
float Reimann(int n, float a, float b)
{
    float s = 0.0f;            /* computed integral value */
    int i;                     /* loop counter */
    float x, y;                /* x and y=f(x) */
    float dx = (b - a) / n;    /* width of rectangles */

    for (i = 0; i < n; i++)
    {
        x = a + dx * i;
        y = f(x);
        s += y * dx;
    }

    return s;
}

/* solution of the quadratic equation ax^2+bx+c=0 */

#include <stdio.h>       /* needed for printf and scanf */
#include <math.h>        /* needed for sqrtf */

int main()
{
    float a, b, c;   /* quadratic equation coefficients */
    float D;         /* determinant */
    float x1, x2;    /* solution(s) */

    /* get equation coefficients */
    printf("Enter a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("Solving equation %fx^2+%fx+%f=0\n", a, b, c);

    /* compute solution */
    D = b * b - 4 * a * c;       /* compute determinant */

    if (D > 0)                   /* two real roots exist */
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
    }
    else if (D == 0)             /* only one root exists */
        x1 = -b / (2 * a);

    /* print results */
    if (D > 0)
        printf("x1=%f, x2=%f\n", x1, x2);
    else if (D == 0)
        printf("x=%f\n", x1);
    else
        printf("No real roots exist\n");

    return 0;
}

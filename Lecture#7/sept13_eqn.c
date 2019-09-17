/* solution of the quadratic equation ax^2+bx+c=0
 Adapted from V. Kindratenko’s notes on 30 August 2016.
*/
#include <stdio.h> /* needed for printf and scanf */
#include <math.h> /* needed for sqrtf */
int main()
{
	float a, b, c; /* quadratic equation coefficients */
	float D; /* discriminant */
	float x1, x2; /* solution(s) */
	/* Get equation coefficients. */
	 printf ("Enter a, b, and c: ");
	if (3 != scanf ("%f %f %f", &a, &b, &c)) {
	 printf ("Three real coefficients are required.\n");
	return 3; /* Program failed. */
	 }
	 printf ("Solving equation %fx^2+%fx+%f=0.\n", a, b, c);
	/* Compute discriminant. */
	 D = b * b - 4 * a * c;
	/* Compute solution. */
	if (0 < D) { /* Two real roots exist. */
	 x1 = (-b + sqrtf (D)) / (2 * a);
	 x2 = (-b - sqrtf (D)) / (2 * a);
	 printf ("x1=%f, x2=%f\n", x1, x2);
	 } else if (0 == D) { /* Only one root exists. */
	 x1 = -b / (2 * a);
	 printf ("x=%f\n", x1);
	 } else {
	 printf ("No real roots exist\n");
	 }
/* End program successfully. */
return 0;
}
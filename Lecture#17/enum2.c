#include <stdio.h>

enum month{JAN=7, FEB, MAR, APR, MAY, JUN=2, JUL, AUG, SEP, OCT, NOV, DEC};

int main()
{
	enum month current;
	current = MAR;
	printf("cur_month is %d\n", current);

	return 0;
}

#include <stdio.h>

enum month{JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

int main()
{
	enum month current;
	current = MAR;
	printf("cur_month is %d\n", current);

	return 0;
}

// Lower to Upper case conversion 

#include <stdio.h>

char Lower2Upper (char inchar);

int main ()
{
	char echo = 'A';
	char upcase;
	
	printf("Input Character : ");
	while(echo != '\n')
	{
		scanf("%c",&echo);
		upcase=Lower2Upper(echo);
		printf("%c",upcase);
	}
	
	return 0;
}

char Lower2Upper(char inchar)
{
	char outchar;
		
	 if ('a' <= inchar && inchar <= 'z')
		outchar=inchar - ('a'-'A');
	else
		outchar=inchar; 
		
	return outchar;
}

// DO we really need the if else?

	/* int diff = 0X5F;
	outchar= (inchar & diff); */
		
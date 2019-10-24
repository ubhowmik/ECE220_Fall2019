#include<stdio.h>
int main()
{
	char name[10];
	int month, day, year;
	double gpa;
	printf("Enter: Lastname Birthday and GPA\n");
	
	// if you do not follow the format specifier synax
	// Bob 04 19 1983 3.34
	
	scanf("%s %d/%d/%d %lf",name,&month, &day, &year,&gpa);
	
	printf("\n");
	printf("Name : %s\n",name);
	printf("Birthday : %d/%d/%d\n", month, day, year);
	printf("GPA : %f\n",gpa);
	
	//subsequent read of the buffer
	char a,b,c;
	a=getchar();
	b=getchar();
	c=getchar();
	
	printf("%c %c %c",a,b,c);
	
	return 0;
}
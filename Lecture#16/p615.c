#include<stdio.h>
int main()
{
	char name[10];
	int month, day, year;
	double gpa;
	printf("Enter: Lastname Birthday and GPA\n");
	scanf("%s %d/%d/%d %lf",name,&month, &day, &year,&gpa);
	//printf("\n");
	printf("Name : %s\n",name);
	printf("Birthday : %d/%d/%d\n", month, day, year);
	printf("GPA : %f\n",gpa);
	return 0;
	
}
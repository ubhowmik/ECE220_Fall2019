#include <stdio.h>
#include <string.h>

	
typedef struct studentStruct	
{		
	char Name[100];
	int UIN;		
	float GPA;	
}student;


void higher_GPA(student s1, student s2)
{
	if(s1.GPA > s2.GPA)
		printf("Student with higher GPA is: %s\n", s1.Name);
	else
		printf("Student with higher GPA is: %s\n", s2.Name);

}

int main()
{
	student s1 = {"John Doe", 123456789, 3.89};
	student s2 = {"Jane Doe", 130000000, 3.98};
	higher_GPA(s1, s2);

student s3;
//s3.Name[]= "John Smith";
s3.Name[0]= 'J';

	return 0;
}

/*
student s3;
s3.Name= "John Smith";
*/

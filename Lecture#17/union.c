#include <stdio.h>

typedef struct studentStruct
{
	char Name[100];
	int UIN;
	float GPA;
}studentS;


typedef union studentUnion
{
        char Name[100];
        int UIN;
        float GPA;
}studentU;

int main()
{
	printf("Size of studentS is %ld\n", sizeof(studentS));
	printf("Size of studentU is %ld\n", sizeof(studentU));

	studentU s1;
	s1.UIN = 123456789;
	s1.GPA = 3.89;

	printf("Student record: Name = %s, UIN = %d, GPA = %f\n", s1.Name, s1.UIN, s1.GPA);
//--------------------------------------------------	
	studentS s2;
	s2.UIN = 123456789;
	s2.GPA = 3.89;
printf("Student record: Name = %s, UIN = %d, GPA = %f\n", s2.Name, s2.UIN, s2.GPA);
	return 0;
}

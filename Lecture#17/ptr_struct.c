#include <stdio.h>
#include <string.h>
       

typedef struct StudentName
{
	char First[30];
	char Middle[30];
	char Last[40];
}name; 
typedef struct
{
	name Name;
	int UIN;
	float GPA;
}student;


int main()
{
	student ece220[200];
	student *ptr;

	ptr = ece220;//same as &ece220[0]
	printf("pointer is at %p\n", (long)ptr);

	ptr++;

	printf("pointer is at %p\n", (long)ptr);

	strncpy(ptr->Name.Last, "Doe", sizeof(ptr->Name.Last));
        strncpy(ptr->Name.First, "John", sizeof(ptr->Name.First));
	ptr->UIN = 123456789;
	printf("ece220[1]: Name = %s %s, UIN = %d\n", ece220[1].Name.First, ece220[1].Name.Last, ece220[1].UIN);

	return 0;
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct studentStruct
{
	char *NAME;
	int UIN;
	float GPA;
}student;

int main()
{
	student *student_list = (student *)malloc(200*sizeof(student));
	int i;
	for(i=0;i<200;i++)
	{
		//(student_list+i)->NAME = (char *)malloc(100*sizeof(char));
		student_list[i].NAME = (char *)malloc(100*sizeof(char));
		strcpy(student_list[i].NAME, "To be set");
		//(student_list+i)->UIN = -1;
		student_list[i].UIN = -1;
		student_list[i].GPA = 0.0;
	}
	printf("student_list pointer %p\n",student_list);
	
	student *new_student_list = realloc(student_list, 400*sizeof(student));
	for(i=200;i<400;i++)
        {
                new_student_list[i].NAME = (char *)malloc(100*sizeof(char));
				strcpy(new_student_list[i].NAME, "To be set");
                new_student_list[i].UIN = -1;
				new_student_list[i].GPA = 0.0;
        }
	printf("new_student_list pointer %p\n", new_student_list);
	
	// print 
	for (i=195;i<205;i++)
	{
	printf("\nStudent[%d] Name: %s",i,new_student_list[i].NAME);
		printf("\nStudent[%d] UIN: %d",i,new_student_list[i].UIN);
		printf("\nStudent[%d] GPA: %f",i,new_student_list[i].GPA);
		printf("\n");
	}
	
	for(i=0;i<400;i++)
        {
                //free((new_student_list+i)->NAME);
				free(new_student_list[i].NAME);
        }

	free(new_student_list);

	return 0;
}
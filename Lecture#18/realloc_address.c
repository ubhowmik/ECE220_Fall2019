#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *p1;
    int m1, m2;
    m1 = 10;
    m2 = 20; // change the size to 20000 and check the address
    p1 = (char*)malloc(m1);
	printf("%p\n",p1);
    strcpy(p1, "Codesdope");
	p1 = (char*)realloc(p1, m2);
	printf("%p\n",p1);
    strcat(p1, "Practice");
    printf("%s\n", p1);
	free(p1);
    return 0;
}

//it is always recommended that when using realloc use a new pointer
//otherwise, you may have memory leakage
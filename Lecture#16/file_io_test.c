#include <stdio.h>

int main()
{
    FILE *myfile;
    myfile = fopen("test.txt", "w");
    if(myfile == NULL)
    {
        printf("Cannot open the file \n");
        return -1;
    }
    int i;
    for(i=48;i<=57;i++)
    {
        fputc(i, myfile);
    }
    fclose(myfile);

   
    myfile = fopen("test.txt", "r");
    i = fgetc(myfile);
    while(i!=EOF)
    {
        printf("%c",i);
        i = fgetc(myfile);
    }
    fclose(myfile);
    return 0;
}

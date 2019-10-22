#include <stdio.h>

int main()
{
	FILE *file;
	char buffer[100];

	//open a file to write to
	file = fopen("intro.txt", "w");

	//use fgets to get input from user
	printf("Write a self introduction using less than 100 characters: ");
	fgets(buffer, 100, stdin);
	
	//use fputs to save user input from buffer to file
	fputs("Your self introduction: ", file);
	fputs(buffer, file);

	fclose(file);

	//use fputs to display string in buffer
	fputs(buffer, stdout);

	return 0;
}

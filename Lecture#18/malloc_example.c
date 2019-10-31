#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char name[20];
   char *address;

   strcpy(name, "Harry Lee");
   address = (char*)malloc( 50 * sizeof(char) );  
/* malloc allocating memory dynamically -typecast char */
   strcpy( address, "Lee Fort, 11-B Sans Street");

   printf("Name = %s\n", name );
   printf("Address: %s\n", address );
   free(address);
   return 0;
}


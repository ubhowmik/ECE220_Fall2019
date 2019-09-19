//https://stackoverflow.com/questions/20208628/c-switch-with-multiple-case-numbers
#include <stdio.h>
#include <math.h>
int main()
{
      int x;
      char ch1;
      printf("Enter a number: ");
      scanf("%d",&x);
      int y=ceil(x/30.0);
      switch(y)
      {

                 case 1:
                      printf("The number you entered is >= 1 and <= 30");
                      printf("\nTake Briefcase Number 1");
                      break;         

                 case 2:
                      printf("The number you entered is >= 31 and <= 60");
                      printf("\nTake Briefcase Number 2");
                      break;                 

                 case 3:
                      printf("The number you entered is >= 61 and <= 90");
                      printf("\nTake Briefcase Number 3");
                      break;                 

                 case 4:
                      printf("The number you entered is >= 91 and <= 100");
                      printf("\nTake Briefcase Number 4");
                      break;      
                 default:
                     printf("Not in the number range");
                     break;

                 }
      	  return 0;
      }
	  
	 
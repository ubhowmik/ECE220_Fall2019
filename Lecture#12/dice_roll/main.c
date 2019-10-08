#include<stdio.h>
#include "functions.h"

int main()
{
char rnd_char[3]; //Random characters
char guess_char[3];//Guessed Character
int trial; //No. of Trials

/*Call the roll_a_dice function to generate -
three random numbers to be used to 
pick 3 random charaters from an array
of charaters */

int rnd_number[3];
roll_a_dice(&rnd_number[0],&rnd_number[1],&rnd_number[2]);

/* Call pick_charaters function to pick three characters from an array of characters using
using number[x] as an index; */

pick_characters(rnd_number,&rnd_char[0],&rnd_char[1],&rnd_char[2]);
/* call comp_charaters function to 
check how many guessed characters matched 
with the three rnd_characters; you are allowed to
use three trials*/ 

char buf[20];
for (trial = 1; 3>= trial; trial++)
{
printf("Trial Number %d\n",trial);
do{
printf ("Enter your guess (three characters): ");
	    if (NULL == fgets (buf, 20, stdin)) {
		printf ("\nProgram terminated.\n");
		return 3;
	    }
} while (!comp_characters(buf,rnd_char,&guess_char[0],&guess_char[1],&guess_char[2]));

//If your guess is correct, we are done
	if (guess_char[0] == rnd_char[0] && guess_char[1] == rnd_char[1] && guess_char[2] == rnd_char[2]) {
	    printf ("Your guess is perfectly matched\n");
	    return 0;
	}
    }
    //User has lost, print solution
    puts ("\nYou failed to guess correctly in three trials.\n");
	
    printf ("The solution was %c %c %c.\n", rnd_char[0], rnd_char[1], rnd_char[2]);

    return 0;
}

 


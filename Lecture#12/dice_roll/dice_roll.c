/* dice_roll.c -contains all the functions
used in the main function */

#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

static int trial_number=1;

void roll_a_dice (int* one, int* two, int* three)
{
srand(time(0)); 
 int  roll1 = (rand () % 6) + 1;
 int  roll2 = (rand () % 6) + 1;
 int  roll3 = (rand () % 6) + 1;
    
    *one   = roll1;
    *two   = roll2;
    *three = roll3;  
}

void pick_characters(int rnd_number[],char *first, char *second, char *third)
{
	char alphabet[7] = { '0','a', 'b', 'c', 'd', 'e', 'f'}; 
	*first = alphabet[(rnd_number[0])];
	*second = alphabet[(rnd_number[1])];
	*third = alphabet[(rnd_number[2])];
}

static void compare(char r1,char r2, char r3, char g1, char g2, char g3)
{
int n_matched=0;
 if (g1 == r1) {
	g1 = r1 = 0;
	n_matched++;
    }
    if (g2 == r2) {
        g2 = r2 = 0;
	n_matched++;
    }
    if (g3 == r3) {
        g3 = r3 = 0;
	n_matched++;
    } 
if (g1) {
        if (g1 == r2) {
	    r2 = 0;
	    n_matched++;
	} else if (g1 == r3) {
	    r3 = 0;
	    n_matched++;
	} 
    }
    if (g2) {
        if (g2 == r1) {
	    r1 = 0;
	    n_matched++;
	} else if (g2 == r3) {
	    r3 = 0;
	    n_matched++;
	} 
    }
    if (g3) {
        if (g3 == r1) {
	    r1 = 0;
	    n_matched++;
	} else if (g3 == r2) {
	    r2 = 0;
	    n_matched++;
	} 
    }	
	
	printf ("With trial %d, you got %d matches.\n", trial_number++, n_matched);

}

int comp_characters(const char guess_str[],char rnd_char[],char *first, char *second, char *third)
{
	if (3 != sscanf (guess_str, "%c%c%c", first,second,third) ||
        'a' > *first || 'f' < *first || 'a' > *second || 'f' < *second || 'a' > *third || 'f' < *third) 
		{
	printf ("make_guess: invalid guess\n");
	return 0;
    }
	compare(rnd_char[0],rnd_char[1],rnd_char[2],*first, *second, *third);
return 1;
}
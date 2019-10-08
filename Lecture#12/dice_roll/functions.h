/*									
 * functions.h - header file 
 */

#if !defined(GUESS_GAME)
#define GUESS_GAME

void roll_a_dice (int* one, int* two, int* three);

void pick_characters(int rnd_number[],char *first, char *second, char *third);

int comp_characters(const char guess_str[],char rnd_char[],char *first, char *second, char *third);

#endif /* GUESS_GAME */



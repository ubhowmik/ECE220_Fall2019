/* Lecture#7 Exercise#1 */
#include <stdio.h>
int main(){
/* declare integer variables x, y and z */

int x,y,z;
						
/* set x to 5, set y to 3 */

x=5;
y=3;

/* increment x by 4 */

x=x+4;

/* left shift x by y and then store the result to z */

z=x<<y;

/* print x, y, and z */

printf("x = %d\n y = %d\n  z = %d\n",x,y,z);

return 0;
}
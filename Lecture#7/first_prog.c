#include <stdio.h> 
/*Header file- some inbuilt functions allow user to perform some specfic tasks
using the operating system's resources* "stdio.h for input output operations*/

int main()   /* Every C program starts with the main function. This is the program executed first*/
{
int course_no = 120; /*declaring and initializing a variable*/

printf("The course number is ECE%d\n", course_no); /*printing the string on the Monitor*/

float gpa = 3.5;
printf("The grade point average is =%f\n",gpa);

double avgdr=6.023E23;
printf("The avogadro number =%lf\n",avgdr);

double e_mass=9.013E-31;
printf("The mass of Electron is =%f kg\n",e_mass);

char a='2';
char b='3';
int sum;
sum=a+b;
printf("the Sume is = %c\n",sum);
printf("the Sume is = %X\n",sum);
printf("the Sume is = %d\n",sum);

int hex_val=0X00FF;
printf("the decimal value of the Hex %X is %d\n", hex_val, hex_val);

int x1=0XFFFFFFFF;
unsigned int x2=0XFFFFFFFF;
printf("The values of x1 in decimal=%d and x2=%u\n",x1,x2);

/*-----------------------------*/
int A=120;
int B=42;
int add,sub,mul,div,mod;
add=A+B;sub=A-B;mul=A*B;div=A/B;mod=A%B;
printf("sum=%d\n subtract=%d\n Mul=%d\n Div=%d\n Mod=%d\n", add,sub,mul,div,mod);

int AND,OR,NOT, EX_OR;

AND=A&B;
OR=A|B;
NOT=~A;
EX_OR=A^B;
printf("Bitwise operations");
printf("AND=%X\n OR=%X\n NOT=%X\n EX_OR=%X\n", AND,OR,NOT,EX_OR);
B=B<<1;
printf("Every left shifting double the number. B=%d\n", B);

B=B>>1;
printf("Every right shifting divide the number by 2. B=%d\n", B);

int C=-42;
C=C>>1;
printf("Every right shifting divide the number by 2. C=%d\n", C);

int score=88;
if (score >= 80 && score<90)
	printf("the Grade is B\n");
	else 
		printf("grade is not B\n");
/*	
	
int radius;
scanf("%d",&radius);
if (radius >0)	
{float cirC;
cirC=2*radius*3.14;
printf("the circumference is = %f\n",cirC);
}	
else
	printf("the radius is not valid");

int A1, B1;
scanf("%d<>%d", &A1, &B1);
printf ("A1=%d, B1=%d\n",A1,B1);
*/
int number;
for (number =0; number <=10; number=number+1) /*number++ can also used for number = number+1 */
{
	if (number == 5)
		continue;
	printf("The number is = %d\n",number);
}

int num=0;
while(num<=10)
{printf("the num is =%d\n",num);
num=num+1;
}

return 0;
}
#include <stdio.h>
#include <math.h>

//Example: a vector struct in C, which has 2 members: angle and length
typedef struct VectorStruct vector;

struct VectorStruct {
 	double angle;
 	double length;
 };

//function scaleVector to scale the length of a vector
void scaleVector(vector *v, double alpha) {
 	v->length *= alpha;
 }

//function addVectors to add two vectors and return the result
vector addVectors(vector a, vector b) {
	vector c;
	double ax = a.length*cos(a.angle);
	double bx = b.length*cos(b.angle);
	double ay = a.length*sin(a.angle);
	double by = b.length*sin(b.angle);
	double cx = ax+bx;
	double cy = ay+by;
	c.length = sqrt(cx*cx+cy*cy);
	c.angle = acos( cx/c.length );

	return c;
}

int main(){
	vector a = {1.5,2}, b={2.6,3},c;
	printf("c's length is %f, c's angle is %f\n", c.length, c.angle);

	c = addVectors(a,b); 
	printf("c's length is %f, c's angle is %f\n", c.length, c.angle);

	return 0;
}
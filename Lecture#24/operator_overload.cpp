#include <iostream>     // used for IO
#include <cmath>

using namespace std;    // creates textual container for variables and functions

class vector {          // class is generalization of struct
  public:          // public identifies the 'public exposure' of this class to the 'outside'
  // functions that build instances, so-called 'constructors'
  vector(double a, double l) { angle = a; length = l; }

  vector() { angle =0.0; length = 0.0; }   // notice "overloading" of function name

 // functions tied to variables of this class
 
   double getAngle() { return angle; }

   double getLength() { return length; }

   void scale(double a) { length *= a; }   // extend or contract vector

   vector operator +(vector b) {             // produce new vector by adding argument to variable
	vector c;
	double ax = length*cos(angle);
	double bx = b.length*cos(b.angle);
	double ay = length*sin(angle);
	double by = b.length*sin(b.angle);
	double cx = ax+bx;
	double cy = ay+by;
	c.length = sqrt(cx*cx+cy*cy);
	c.angle = acos( cx/c.length );

	return c;
   }

   private:  // default access specifier, compile throws error if direct access is attempted
   double angle, length;

};

 
int main() {

 vector c(1.5,2);
 vector d(2.6,3);
 vector e = c+d;

 cout << "e's length is " << e.getLength() << " and e's angle is " << e.getAngle() << endl;

 return 0;
}
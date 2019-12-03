#include <iostream>     // used for IO
#include<cmath>

using namespace std;    // creates textual container for
                        // variables and functions

class vector     // class is generalization of struct
{               // class constructors, do initialization
  public:      // public identifies the 'public exposure' 
               // of this class to the 'outside' functions
          // that build instances, so-called 'constructors'
  vector(double a, double l) { angle = a; length = l; }
  vector() { angle =0.0; length = 0.0; }   // notice 
                        // "overloading" of function name

  // functions tied to variables of this class
   double getAngle() { return angle; }
   double getLength() { return length; }
   void scale(double a) { length *= a; } // scale vector
   vector add(vector b);  // produce new vector by adding 
                          // argument to variable
  protected: // compile throws error if direct access is 
             // attempted
   double angle, length;
};

vector vector::add(vector b) { // produce new vector by 
                            // adding argument to variable
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

class orthovector: public vector 
 {
	public:
	 orthovector(int dir, double l) {  // dir is 0,1,2,3 
                         // indicating right, up, left, down
	   const double halfPI = 1.507963268;
	   d = dir;
	   angle = d*halfPI;
	   length = l;
	 }

	 orthovector() { d = 0; angle = 0.0; length = 0.0; }

	 double hypotenuse(orthovector b);

	 protected:
	   int d;
};

 double orthovector::hypotenuse(orthovector b) {
 	if( (d+b.d)%2 == 0 ) return length+b.length;
 	return (sqrt( length*length + b.length*b.length ) );
 }

  

int main()
{
 orthovector c(0,0);
 orthovector d(1,4);
 vector e = c.add(d); //add returns a vector type

 double f = c.hypotenuse(d);

 cout << "e length is " << e.getLength() << " and e angle is " << e.getAngle() << "\n";
 cout << "f hypotenuse is " << f << "\n";
}

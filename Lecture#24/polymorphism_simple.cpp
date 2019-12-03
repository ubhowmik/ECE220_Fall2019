#include <iostream> 
using namespace std;
 
class Shape {
   protected:
      double width, height;
      
   public:
   
	Shape() {width = 1; height = 1;}

    Shape(double a, double b) { width = a; height = b; }
	//double area() { cout << "Base class area unknown" << endl; 
					//return 0; }
					
	 virtual double area() { cout << "Base class area unknown" << endl; 
					return 0; } 
};

class Rectangle: public Shape {
   public:
	//Rectangle(double a, double b) : Shape(a,b){}
	Rectangle(double a, double b) {width = a; height = b; }

    double area () { 
         cout << "Rectangle class area :";
         return (width * height); 
      }
};

class Triangle: public Shape {
   public:
      Triangle( double a, double b):Shape(a, b) { }
      
      double area () { 
         cout << "Triangle class area :" ;
         return (width * height / 2); 
      }
};

// Main function for the program
int main() {
   Shape *ptr;
   Rectangle rec(10,7);
   Triangle  tri(10,5);

   // store the address of Rectangle
   ptr = &rec;
   
   // call rectangle area.
  int print_r = ptr->area();
  cout << print_r <<endl;
   // store the address of Triangle
   ptr = &tri;
   
   // call triangle area.
  double print_t = ptr->area();
   cout << print_t <<endl;
   return 0;
}
#include <iostream>

using namespace std;

//Rectangle class
class Rectangle{
   //default access is private
   int width, height;

   public:
	//constructors
	Rectangle();
	Rectangle(int, int);
	//destructor
	~Rectangle() {cout << "Destructor is called." << endl;};
	int area() {return width*height;}
};
Rectangle::Rectangle(){//set both width and height to 1
	width = 1;
	height = 1;
}

Rectangle::Rectangle(int a, int b){
	width = a;
	height = b;
}

/* // First part of Class notes Exercise
int main(){
	Rectangle rect1(3,4);
	Rectangle rect2;

	//print rect1’s area
	cout << "rect1’s area = "<< rect1.area() << endl;

	//print rect2’s area
   cout << "rect2’s area = "<< rect2.area() << endl;

	return 0;
} */

// Second Part of Classnotes exercise

int main(){
	Rectangle rect1(3,4);
	Rectangle *rect_ptr = &rect1;
	cout << "rect1's area is: " << rect_ptr->area() << endl;

	Rectangle *r_ptr2, *r_ptr3;
	r_ptr2 = new Rectangle(5,6);
	cout << "area of rectangle pointed to by r_ptr2 is: " << r_ptr2->area() << endl;

	r_ptr3 = new Rectangle[2]{Rectangle(),Rectangle(2,4)};
	cout << "area of rectangle [0] in array is: " << r_ptr3[0].area() << endl;
	//cout << "area of rectangle [0] in array is: " << r_ptr3->area() << endl;

	//cout << "area of rectangle [1] in array is: " << r_ptr3[1].area() << endl;
	cout << "area of rectangle [1] in array is: " << (r_ptr3+1)->area() << endl;

		
	delete r_ptr2; //deallocate heap
	delete [] r_ptr3;

	return 0;
}
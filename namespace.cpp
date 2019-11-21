#include <iostream> 
using namespace std; 

// Variable created inside namespace 
namespace first 
{ 
	int val = 500; 
} 

// Global variable 
int val = 100; 

int main() 
{ 
	// Local variable 
	int val = 200; 

	// These variables can be accessed from 
	// outside the namespace using the scope 
	// operator :: 
	cout << first::val << '\n'; 

	return 0; 
}
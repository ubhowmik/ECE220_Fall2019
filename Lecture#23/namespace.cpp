#include <iostream> 

using namespace std; 

// Variable created inside namespace 
namespace first 
{ 
	int val = 500; 
} 

namespace second
{ 
	int val = 2500; 
} 

int main() 
{ 
	// Local variable 
	int val = 200; 

	/* std::cout << first::val << std::endl; 
	std::cout << second::val << std::endl;
	std::cout << val << std::endl; */
	
	// operator :: 
	cout << first::val << '\n'; 
	cout << second::val << '\n';
	cout << val << '\n';

	return 0; 
}
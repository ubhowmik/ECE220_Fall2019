#include <iostream> 
using namespace std; 

template <class T1, class T2> 
void Print(T1 x, T2 y){
cout<<x<<endl; 
cout<<y<<endl;
}
int main(){
Print('H',256.55);
return 0;
}

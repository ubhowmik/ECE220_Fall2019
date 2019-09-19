#include <stdio.h>

#define DEBUG0

int main(){
	#ifdef DEBUG
		printf("Debug is ON\n");
		printf("Hi friends!\n");
	#else
		printf("Debug is OFF\n");
	#endif
	return 0;
}

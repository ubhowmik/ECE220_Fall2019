 #include <stdio.h>

void call_by_reference(int *y) {
	printf("Inside call_by_reference y = %d before adding 10.\n", *y);
	(*y) += 10;
	printf("Inside call_by_reference y = %d after adding 10.\n", *y);
}

int main() {
	int b=10;
	
	printf("b = %d before function call_by_reference.\n", b);
	call_by_reference(&b);
	printf("b = %d after function call_by_reference.\n", b);
	
	return 0;
}
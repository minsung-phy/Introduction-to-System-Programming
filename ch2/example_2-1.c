#include <stdio.h>

int main() {
	int i;
	float sum = 0.0F;
		
	for (i = 0; i < 100; i++) 
		sum = sum + 0.1F;
		
	printf("The sum is %f\n");
	return 0;
}
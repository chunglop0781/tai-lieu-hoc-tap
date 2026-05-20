#include <stdio.h>
#include <math.h>

int main () {
	float r, cv, dt;
	printf("\n Ban kinh r = ");
	scanf("%f", &r);
	cv = 2 * 3.14159 * r;
	dt = 3.14159 * r * r;
	printf("\n");
	printf("Chu vi = %0.2f\n", cv);
	printf("Dien tich = %0.2f\n", dt);
	getchar();
}
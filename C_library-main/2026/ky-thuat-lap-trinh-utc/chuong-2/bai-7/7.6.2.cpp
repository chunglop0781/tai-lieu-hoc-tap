#include <stdio.h>

int main () {
	int a, b = 20;
	int c, d = 40;
	float e = -35.11;
	float x = 23, y, z, t = 36.1;
	a = c = 10;
	y = z = a + b + c + d;
	{
		float y, z;
		y =  z = e + x + t;
		printf("y trong = %0.2f\n", y);
		printf("z trong = %0.2f\n", z);
	}
		printf("y ngoai = %0.2f\n", y);
		printf("z ngoai = %0.2f\n", z);
		getchar();
}
#include <stdio.h>
#include <math.h>

int main () {
	double x, y, z;
	printf("Vao x va y: ");
	scanf("%lf", &x);
	scanf("%lf", &y);
	z = pow(x, y);
	printf("x = %0.2lf\n", x);
	printf("y = %0.2lf\n", y);
	printf("z = %0.2lf\n", z);
	getchar();
}
#include <stdio.h>

int main () {
	int a=5, b=2;
	{
		int a=4;
		b=a+b;
		printf("a = %3d, b = %3d\n", a, b);
	}
		printf("a = %3d, b = %3d", a, b);
		getchar();
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double f(double x){
	return pow(3, x) + 2 * sin(x) - 10;
}

double chiaDoi(double a, double b, double ss){
    double c;
    int dem;
    while (fabs(b - a) > ss) {
        c = (a + b) / 2;
        if (f(c) == 0) {
            return c;
        }
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        dem++;
    }
    c = (a + b) / 2;
    printf("Nghiem c tim duoc la: %lf\n", c);
	printf("So buoc lap = %d\n", dem);
    return c;
}

int main(){
	double a, b, ss;
	printf("Nhap vao khoang [a,b]: "); scanf("%lf %lf", &a, &b);
	printf("Nhap sai so ss: "); scanf("%lf", &ss);
	chiaDoi(a, b, ss);
	return 0;
}
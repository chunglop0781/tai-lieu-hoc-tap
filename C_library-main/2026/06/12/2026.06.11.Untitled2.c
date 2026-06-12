#include<stdio.h>
#include<stdlib.h>
#include<math.h>

///* Day cung *///
double F(double x){
	return pow(x,4) - 3 * pow(x,2) - (-75 * x + 10000);
}


int main(){
	double a, b, ss;
	double x0, Fu, x1;
	int dem = 0;
	printf("Nhap khoang cach [a, b]:\n");
	printf("a = "); scanf("%lf", &a);
	printf("b = "); scanf("%lf", &b);
	printf("Nhap sai so (ss): "); scanf("%lf", &ss);
	if (F(a) > 0){
		x0 = b;
		Fu = a;
	} else {
        x0 = a;
        Fu = b;
    }
    do {
    	x1 = x0 - (F(x0) / (F(Fu) - F(x0))) * (Fu - x0);
    	if(fabs(x1 - x0) < ss){
    		break;
		} else {
			x0 = x1;
		}
		dem++;
	} while (dem < 100000);
	printf("\nGiao diem cua f(x) va g(x) la: x1 = %.7lf\n", x1);
	printf("So buoc lap = %d\n", dem);
}



///* Chia doi *///
//double f(double x){
//	return pow(x,2) - 4;
//}
//
//int main(){
//	double a, b, ss;
//	printf("Nhap vao khoang [a,b]: ");
//	scanf("%lf %lf", &a, &b);
//	printf("Nhap sai so ss: ");
//	scanf("%lf", &ss);
//	double c;
//	c = (a + b) / 2;
//	if (f(c) == 0) {
//		break;
//	}
//	if (f(a) * f(c) < 0) {
//		b = c;
//	} else {
//		a = c;
//	}
//	if (b - a < ss) {
//		c = (a + b) / 2;
//		break;
//	}
//	printf("Nghiem c tim duoc la: %lf\n", c);
//	return 0;
//}

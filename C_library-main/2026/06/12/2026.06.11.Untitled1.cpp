#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double P(double a[], int n, double x){
	double ketQua = 0.0;
	for(int i = 0; i <= n; i++){
		ketQua += a[i] * pow(x, i);
	}
	return ketQua;
}

double Q(double b[], int n, double x){
	double ketQua = 0.0;
	for(int i = 0; i <= n; i++){
		ketQua += b[i] * pow(x, i);
	}
	return ketQua;
}

int main(){
	int n; 
	printf("Nhap he so n: "); scanf("%d", &n);
	///* P(x) *///
	printf("Nhap he so a[0] -> a[n]:\n");
	double a[n + 1];
	for(int i = 0; i <= n; i++){
		printf("a[%d] = ", i);
		scanf("%lf", &a[i]);
	}
	printf("P(x) = %.2f", a[0]);
	for(int i = 1; i <= n; i++){
		if(a[i] >= 0){
			printf(" + %.2f * x^%d ", a[i], i);
		} else {
			printf(" %.2f * x^%d ", a[i], i);
		}
	}
	printf("\n");
	///* Q(x) *///
	printf("Nhap he so b[0] -> b[n]:\n");
	double b[n + 1];
	for(int i = 0; i <= n; i++){
		printf("b[%d] = ", i);
		scanf("%lf", &b[i]);
	}
	printf("P(x) = %.2f", b[0]);
	for(int i = 1; i <= n; i++){
		if(b[i] >= 0){
			printf(" + %.2f * x^%d ", b[i], i);
		} else {
			printf(" %.2f * x^%d ", b[i], i);
		}
	}
	/// S = sqrt(P(y[1])-Q(y[2])) - 2015 ///
	double y[3];
	printf("Nhap gia tri cho y[i]:\n");
	for(int i = 1; i <= 2; i++){
		printf("y[%d] = ", i); scanf("%lf", &y[i]);
	}
	double x = y[1];
	double ket_qua_1 = P(a, n, x);
	printf("Gia tri cua da thuc P(%.2f) = %.2f\n", x, ket_qua_1);
	x = y[2];
	double ket_qua_2 = Q(b, n, x);
	printf("Gia tri cua da thuc Q(%.2f) = %.2f\n", x, ket_qua_2);
	
	if(ket_qua_1 >= ket_qua_2){
		double S = (double)sqrt(ket_qua_1-ket_qua_2) - 2015;
		printf("S = %.3f", S);
	} else if(ket_qua_1 < ket_qua_2){
		printf("Loi S!\n");
	}
}
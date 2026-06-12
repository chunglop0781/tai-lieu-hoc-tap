#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
	double a[100];
	double b[100];
	double atrub[100];
	int n;
} DaThuc;

double P(DaThuc dt, double x){
	double ketQua = 0.0;
	for(int i = 0; i <= dt.n; i++){
		ketQua += dt.a[i] * pow(x, i);
	}
	return ketQua;
}

double Q(DaThuc dt, double x){
	double ketQua = 0.0;
	for(int i = 0; i <= dt.n; i++){
		ketQua += dt.b[i] * pow(x, i);
	}
	return ketQua;
}

int main(){
	DaThuc dt;
	printf("Nhap he so n: "); scanf("%d", &dt.n);
	///* P(x) *///
	printf("Nhap he so a[0] -> a[n]:\n");
	for(int i = 0; i <= dt.n; i++){
		printf("a[%d] = ", i);
		scanf("%lf", &dt.a[i]);
	}
	printf("P(x) = %.2f", dt.a[0]);
	for(int i = 1; i <= dt.n; i++){
		if(dt.a[i] >= 0){
			printf(" + %.2f * x^%d ", dt.a[i], i);
		} else {
			printf(" %.2f * x^%d ", dt.a[i], i);
		}
	}
	printf("\n");
	///* Q(x) *///
	printf("Nhap he so b[0] -> b[n]:\n");
	for(int i = 0; i <= dt.n; i++){
		printf("b[%d] = ", i);
		scanf("%lf", &dt.b[i]);
	}
	printf("Q(x) = %.2f", dt.b[0]);
	for(int i = 1; i <= dt.n; i++){
		if(dt.b[i] >= 0){
			printf(" + %.2f * x^%d ", dt.b[i], i);
		} else {
			printf(" %.2f * x^%d ", dt.b[i], i);
		}
	}
	printf("\n");
	/// S = sqrt(P(y[1])-Q(y[2])) - 2015///
	double y[3];
	printf("Nhap gia tri cho y[i]:\n");
	for(int i = 1; i <= 2; i++){
		printf("y[%d] = ", i); scanf("%lf", &y[i]);
	}
	double x = y[1];
	double ket_qua_1 = P(dt, x);
	printf("Gia tri cua da thuc P(%.2f) = %.2f\n", x, ket_qua_1);
	x = y[2];
	double ket_qua_2 = Q(dt, x);
	printf("Gia tri cua da thuc Q(%.2f) = %.2f\n", x, ket_qua_2);
	if(ket_qua_1 >= ket_qua_2){
		double S = (double)sqrt(ket_qua_1-ket_qua_2) - 2015;
		printf("S = %.3f\n", S);
	} else if(ket_qua_1 < ket_qua_2){
		printf("Loi S!\n");
	}
	for(int i = 0; i <= dt.n; i++){
		dt.atrub[i] = dt.a[i] - dt.b[i];
	}
	printf("=> P(x) - Q(x) = %.2f", dt.atrub[0]);
	for(int i = 1; i <= dt.n; i++){
		if(dt.atrub[i] >= 0){
			printf(" + %.2f * x^%d ", dt.atrub[i], i);
		} else {
			printf(" %.2f * x^%d ", dt.atrub[i], i);
		}
	}
	return 0;
}
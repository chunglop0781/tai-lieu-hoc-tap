#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void In(double x[], double y[], int n){
	for(int i = 0; i < n; i++){
		printf("(%.2lf, %.2lf)", x[i], y[i]);
	}
	printf("\n");
}

void Lagrange(double x[], double y[], int n){
	double x0, P = 0;
	printf("Nhap x* = "); scanf("%lf", &x0);
	for(int i = 0; i < n; i++){
		double L = 1;
		for(int j = 0; j < n; j++){
			if(i != j){
				L *= (x0-x[j])/(x[i]-x[j]);
			}
		}
		P += y[i] * L;
	}
	printf("f(*x) = %.6lf\n", P);
}

int main(){
	double x[100], y[100];
	int n;
	printf("Nhap n = "); scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("x[%d] = ", i); scanf("%lf", &x[i]);
		printf("y[%d] = ", i); scanf("%lf", &y[i]);
	}
	printf("=> Cac diem vua nhap: ");
	In(x, y, n);
	Lagrange(x, y, n);
	return 0;
}

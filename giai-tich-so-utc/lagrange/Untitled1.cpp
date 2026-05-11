#include <stdio.h>

void nhandathuc (double a[], int *degA, double b[], int degB){
	double temp[100] = {0};
	for(int i = 0; i <= *degA; i++){
		for(int j = 0; j <= degB; j++){
			temp [i+j] += a[i] * b[j];
		}
	}
	*degA = *degA + degB;
	for(int i = 0; i <= *degA; i++){
		a[i] = temp[i];
	}
}

void lagrangedathuc (double x[], double y[], int n){
		double P[100] = {0};
		for(int i = 0; i < n; i++){
			double Li[100] = {0};
			Li[0] = 1;
			int degLi = 0;
			double mau = 1;
			for(int j = 0; j < n; j++){
				if(j != i){
					double temp[2];
					temp[0] = -x[j];
					temp[1] = 1;
					nhandathuc(Li, &degLi, temp, 1);
					mau *= (x[i] - x[j]);
				}
			}
			printf("\nDa thuc noi suy:\nP(x) = ");
			for(int i = 0; i < n; i++){
				printf("%.4lf", P[i]);
				if(i>0) printf("x^%d", i);
				if(i != n-1 && P[i+1]>=0) printf(" + ", i);
				else if(i != n-1) printf(" ", i);
			}
			printf("\n");
		}
	}

int main() {
	int n;
	printf("Nhap so diem: ");
	scanf("%d", &n);
	double x[100], y[100]; //
	for (int i = 0; i<n; i++){
		printf("Nhap x[%d] = ", i);
		scanf("%lf", &x[i]);
		printf("Nhap y[%d] = ", i);
		scanf("%lf", &y[i]);
	}
	lagrangedathuc (x,y,n);
	return 0;
}
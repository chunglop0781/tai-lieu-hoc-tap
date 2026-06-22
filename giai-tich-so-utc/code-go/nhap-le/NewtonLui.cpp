#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void NewtonLui(int n, double x[], double y[]){
    double xCanTinh;
    printf("Nhap xCanTinh = "); scanf("%lf", &xCanTinh);
    double h = x[1] - x[0];
    double D[100];
    for(int i = 0; i <= n - 1; i++){
        D[i] = y[i+1] - y[i];
    }
    double t = (xCanTinh - x[n])/h;
    double k = t;
    double ketQua = y[n] + t * D[n-1];
    for(int j = 2; j <= n; j++){
        for(int i = 0; i <= n - j; i++){
            D[i] = D[i + 1] - D[i];
        }
        k = k * (t+j-1)/j;
        ketQua = ketQua + k * D[n - j];
    }
    printf("\nKet qua = %lf\n", ketQua);
}

int main(){
	int n; double x[100], y[100];
	printf("Nhap bac cua da thuc n = "); scanf("%d", &n);
	printf("Nhap cac gia tri cua x:\n");
	for(int i = 0; i <= n; i++){
		printf("x[%d] = ", i); scanf("%lf", &x[i]);
	}
	printf("Nhap cac gia tri cua y:\n");
	for(int i = 0; i <= n; i++){
		printf("y[%d] = ", i); scanf("%lf", &y[i]);
	}
	NewtonLui(n, x, y);
	return 0;
}
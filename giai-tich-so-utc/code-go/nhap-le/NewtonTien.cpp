#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void noiSuyNewtonTien(int n, double x0, double x, double h, double D[]){
	double y0 = D[0];
	double t = (x-x0)/h;
    double k = t;
    double ketQua;
    for(int i = 0; i < n; i++){
        D[i] = D[i + 1] - D[i];
    }
    ketQua = y0 + t * D[0];
    for(int j = 2; j <= n; j++){
        for(int i = 0; i <= n - j; i++){
            D[i] = D[i + 1] - D[i];
        }
        k = k * (t-j+1)/j;
        ketQua = ketQua + k * D[0];
    }
    printf("\nKet qua = %lf\n", ketQua);
}

int main(){
	int n; double x0, x, h, D[100];
	printf("Nhap n = "); scanf("%d", &n);
	printf("Nhap x0 = "); scanf("%lf", &x0);
	printf("Nhap x_can_tinh = "); scanf("%lf", &x);
	printf("Nhap h = "); scanf("%lf", &h);
	printf("Nhap cac gia tri y:\n");
	for(int i = 0; i <= n; i++){
		printf("y[%d] = ", i); scanf("%lf", &D[i]);
	}
	noiSuyNewtonTien(n, x0, x, h, D);
	return 0;
}

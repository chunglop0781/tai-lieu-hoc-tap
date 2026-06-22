#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void NoiSuyNewtonTrenLuoiKhongDeu(int n, double x[], double y[]){
    double xCanTinh;
    printf("Nhap xCanTinh = "); scanf("%lf", &xCanTinh);
    double F[100];
    double ketQua = y[0];
    double tich = xCanTinh - x[0];
    for (int i = 0; i < n; i++){
        F[i] = (y[i + 1] - y[i])/(x[i+1]-x[i]);
    }
    ketQua = ketQua + F[0] * tich;
    for(int j = 2; j <= n; j++){
        for(int i = 0; i <= n - j; i++){
            F[i] = (F[i + 1] - F[i])/(x[i+j]-x[i]);
        }
        tich = tich * (xCanTinh - x[j-1]);
        ketQua = ketQua + F[0] * tich;
    }
    printf("\nKet qua = %lf\n", ketQua);
}

int main(){
    int n;
    double x[100], y[100];
    printf("Nhap bac cua da thuc n = "); scanf("%d", &n);
    printf("Nhap cac gia tri cua x:\n");
    for(int i = 0; i <= n; i++){
       printf("x[%d] = ", i); scanf("%lf", &x[i]);
    }
    printf("Nhap cac gia tri cua y:\n");
	for(int i = 0; i <= n; i++){
        printf("y[%d] = ", i); scanf("%lf", &y[i]);
    }
    NoiSuyNewtonTrenLuoiKhongDeu(n, x, y);
}
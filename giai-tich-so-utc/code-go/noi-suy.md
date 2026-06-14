# Lagrange
```
#include <stdio.h>
#include <math.h>

void Nhap(float x[], float y[], int *n){
    int i;
    printf("Nhap n = ");
    scanf("%d", n);
    printf("Nhap cac bo gia tri (x,y): \n");
    for(i = 0; i <= *n; i++){
        printf("Nhap x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("Nhap y[%d] = ", i);
        scanf("%f", &y[i]);
    }
}

void In(float x[], float y[], int n){
    int i;
    printf("Cac bo gia tri vua nhap la: \n");
    for(i = 0; i <= n; i++){
        printf("(%.2f, %.2f) ", x[i], y[i]);
    }
}

void lagrange(float x[], float y[], int n){
    float P = 0, L, x0;
    printf("Nhap x* = "); scanf("%f", &x0);
    for(int i = 0; i <= n; i++){
        L = 1;
        for(int j = 0; j <= n; j++){
            if(i != j){
                L *= (x0 - x[j])/(x[i]-x[j]);
            }
        }
        P += L * y[i];
    }
    printf("Gia tri gan dung cua ham so f(x) tai x* la: %.6f\n", P);
}

int main(){
    int n;
    float x[50], y[50];
    Nhap(x, y, &n);
    In(x, y, n);
    lagrange(x, y, n);
    return 0;
}
```
# NewtonTien
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhap(int n, float y[]){
    printf("Vui long nhap y[i]:\n");
    for(int i = 0; i < n; i++){
        printf("y[%d] = ", i); scanf("%f", &y[i]);
    }
}

void saiPhanCap1(int n, float y[], float D[]){
    for(int i = 0; i < n - 1; i++){
        D[i] = y[i+1] - y[i];
    }
}

void saiPhanCapCao(int n, float D[], int j){
    for(int i = 0; i < n - 1; i++){
        D[i] = D[i+1] - D[i];
    }
}

float newton(int n, float x0, float input_x, float h, float y[], float D[]){
    float t = (input_x - x0)/h;
    float k = t;
    saiPhanCap1(n, y, D);
    float input_y = y[0] + t * D[0];
    for(int j = 2; j < n; j++){
        saiPhanCapCao(n, D, j);
        k *= (t-j+1)/j;
        input_y += k * D[0];
    }
    return input_y;
}

void xuat(float input_y){
    printf("\ny = %.4f\n", input_y);
}

int main(){
    float x0, input_x, h; int n;
    printf("Vui long nhap x[0], x, h, n: ");
    scanf("%f %f %f %d", &x0, &input_x, &h, &n);
    float y[n], x[n], D[n];
    nhap(n, y);
    float result = newton(n, x0, input_x, h, y, D);
    xuat(result);
    return 0;
}
```
# NoiSuyNewtonTrenLuoiKhongDeu
```
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void noiSuyNewtonTrenLuoiKhongDeu(int n, double x, double xi[], double yi[], double *y_out){
    double y = yi[0];
    if(n = 1){
        *y_out = y;
        return;
    }
    double t = x - xi[0];
    double F[n-1];
    for(int i = 0; i <= n - 1; i++){
        F[i] = (yi[i+1]-yi[i])/(xi[i+1]-xi[i]);
    }
    y += F[0] * t;
    for(int j = 2; j <= n; j++){
        for(int i = 0; i <= n-j; i++){
            F[i] = (F[i+1]-F[i])/(xi[i+j]-xi[i]);
        }
        t *= (x-xi[j-1]);
        y += F[0] * t;
    }
    *y_out = y;
}

int main(){
    int n;
    printf("So diem du lieu n = "); scanf("%d", &n);
    if(n<2){
        return 1;
    }
    double xi[n], yi[n];
    printf("\nNhap %d gia tri yi:\n", n);
    for(int i = 0; i < n; i++){
        printf("xi[%d] = ", i); scanf("%lf", &xi[i]);
        printf("yi[%d] = ", i); scanf("%lf", &yi[i]);
    }
    int k;
    printf("\nSo diem can noi suy = "); scanf("%d", &k);
    double tich = 1.0;
    for(int i = 0; i < k; i++){
        double x; double y;
        printf("\nx[%d] = ", i); scanf("%lf", &x);
        noiSuyNewtonTrenLuoiKhongDeu(n, x, xi, yi, &y);
        printf("f(%.3f) = %.10lf\n", x, y);
        tich *= y;
    }
    printf("\nTich cac gia tri noi suy = %.10lf\n", tich);
}
```

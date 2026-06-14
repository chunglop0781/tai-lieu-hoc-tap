# Lagrange
```
#include <stdio.h>
#include <math.h>

void Nhap(float x[], float y[], int *n){
    printf("Nhap n = ");
    scanf("%d", n);
    printf("Nhap cac bo gia tri (x,y):\n");
    for(int i = 0; i < *n; i++){
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }
}

void In(float x[], float y[], int n){
    printf("Cac diem vua nhap:\n");
    for(int i = 0; i < n; i++){
        printf("(%.2f, %.2f) ", x[i], y[i]);
    }
    printf("\n");
}

void Lagrange(float x[], float y[], int n){
    float x0, P = 0;
    printf("Nhap x* = ");
    scanf("%f", &x0);
    for(int i = 0; i < n; i++){
        float L = 1;
        for(int j = 0; j < n; j++){
            if(i != j){
                L *= (x0 - x[j]) / (x[i] - x[j]);
            }
        }
        P += L * y[i];
    }

    printf("f(x*) = %.6f\n", P);
}

int main(){
    float x[50], y[50];
    int n;
    Nhap(x, y, &n);
    In(x, y, n);
    Lagrange(x, y, n);
    return 0;
}
```
# NewtonTien
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhap(int n, float y[]){
    for(int i = 0; i < n; i++){
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }
}

void saiPhan(float y[], float D[][50], int n){
    for(int i = 0; i < n; i++){
        D[i][0] = y[i];
    }
    for(int j = 1; j < n; j++){
        for(int i = 0; i < n - j; i++){
            D[i][j] = D[i+1][j-1] - D[i][j-1];
        }
    }
}

float NewtonTien(int n, float x0, float x, float h, float y[]){
    float D[50][50];
    saiPhan(y, D, n);
    float t = (x - x0) / h;
    float P = D[0][0];
    float k = 1;
    for(int j = 1; j < n; j++){
        k *= (t - (j - 1)) / j;
        P += k * D[0][j];
    }
    return P;
}

int main(){
    int n;
    float x0, x, h;
    printf("Nhap x0, x, h, n: ");
    scanf("%f %f %f %d", &x0, &x, &h, &n);
    float y[50];
    nhap(n, y);
    float kq = NewtonTien(n, x0, x, h, y);
    printf("f(x) = %.6f\n", kq);
    return 0;
}
```
# NoiSuyNewtonTrenLuoiKhongDeu
```
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void NewtonKhongDeu(int n, double x, double xi[], double yi[], double *y_out){
    double F[50][50];
    for(int i = 0; i < n; i++){
        F[i][0] = yi[i];
    }
    for(int j = 1; j < n; j++){
        for(int i = 0; i < n - j; i++){
            F[i][j] = (F[i+1][j-1] - F[i][j-1]) /
                      (xi[i+j] - xi[i]);
        }
    }
    double result = F[0][0];
    double k = 1;
    for(int j = 1; j < n; j++){
        k *= (x - xi[j-1]);
        result += k * F[0][j];
    }
    *y_out = result;
}

int main(){
    int n;
    printf("n = ");
    scanf("%d", &n);
    double xi[50], yi[50];
    for(int i = 0; i < n; i++){
        printf("x[%d] = ", i);
        scanf("%lf", &xi[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &yi[i]);
    }
    int k;
    printf("So diem can noi suy: ");
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        double x, y;
        printf("x = ");
        scanf("%lf", &x);
        NewtonKhongDeu(n, x, xi, yi, &y);
        printf("f(%.5f) = %.10lf\n", x, y);
    }
    return 0;
}
```

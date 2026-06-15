# Lagrange
```
#include <stdio.h>
#include <math.h>

void Nhap(float x[], float y[], int *n){
    printf("Nhap n = ");
    scanf("%d", n);
    for(int i = 0; i < *n; i++){
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }
}

void In(float x[], float y[], int n){
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
        P += y[i] * L;
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
// test f(x)=x^2+1
// n = 4
// x[0] = 0
// y[0] = 1
// x[1] = 1
// y[1] = 2
// x[2] = 2
// y[2] = 9
// x[3] = 3
// y[3] = 28
// x* = 1.5
// f(1.5) = 4.375
}
```
# NewtonTien
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhapDuLieu(int *n, double *x0, double *x, double *h, double D[]) {
    int i;
    printf("Nhap n: ");
    scanf("%d", n);
    printf("Nhap x0: ");
    scanf("%lf", x0);
    printf("Nhap x can tinh: ");
    scanf("%lf", x);
    printf("Nhap h: ");
    scanf("%lf", h);
    printf("Nhap cac gia tri y:\n");
    for (i = 0; i <= *n; i++) {
        printf("y[%d] = ", i);
        scanf("%lf", &D[i]);
    }
}

void noiSuyNewton(int n, double x0, double x, double h, double D[]) {
    int i, j;
    double y0 = D[0];
    double t = (x - x0) / h;
    double k = t;
    double ketQua;
    for (i = 0; i < n; i++) {
        D[i] = D[i + 1] - D[i];
    }
    ketQua = y0 + t * D[0];
    for (j = 2; j <= n; j++) {
        for (i = 0; i <= n - j; i++) {
            D[i] = D[i + 1] - D[i];
        }
        k = k * (t - j + 1) / j;
        ketQua = ketQua + k * D[0];
    }
    printf("\nKet qua = %lf\n", ketQua);
}

int main() {
    int n;
    double x0, x, h;
    double *D = (double *)malloc(100 * sizeof(double));
    nhapDuLieu(&n, &x0, &x, &h, D);
    noiSuyNewton(n, x0, x, h, D);
    free(D);
    return 0;
// test f(x)=x^2+1
// n = 3
// x0 = 0
// x can tinh = 1.5
// h = 1
// y[0] = 1
// y[1] = 2
// y[2] = 9
// y[3] = 28
// Ket qua = 4.375000
}
```
# NewtonLui
```
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void NhapDuLieu(int *n, double x[], double y[]) {
    printf("Nhap bac cua da thuc n = ");
    scanf("%d", n);
    printf("Nhap cac gia tri x:\n");
    for (int i = 0; i <= *n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
    }
    printf("Nhap cac gia tri y:\n");
    for (int i = 0; i <= *n; i++) {
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }
}

void NewtonLui(int n, double x[], double y[]) {
    double xCanTinh;
    printf("Nhap x can tinh: ");
    scanf("%lf", &xCanTinh);
    double h = x[1] - x[0];
    double *D = (double *)malloc((n + 1) * sizeof(double));
    for (int i = 0; i <= n - 1; i++) {
        D[i] = y[i + 1] - y[i];
    }
    double t = (xCanTinh - x[n]) / h;
    double k = t;
    double ketQua = y[n] + t * D[n - 1];
    for (int j = 2; j <= n; j++) {
        for (int i = 0; i <= n - j; i++) {
            D[i] = D[i + 1] - D[i];
        }
        k = k * (t + j - 1) / j;
        ketQua = ketQua + k * D[n - j];
    }
    printf("\nKet qua = %.6lf\n", ketQua);
    free(D);
}

int main() {
    int n;
    double *x = (double *)malloc(100 * sizeof(double));
    double *y = (double *)malloc(100 * sizeof(double));
    NhapDuLieu(&n, x, y);
    NewtonLui(n, x, y);
    free(x);
    free(y);
    return 0;
// test f(x)=x^2+1
// n = 3
// x[0] = 0
// x[1] = 1
// x[2] = 2
// x[3] = 3
// y[0] = 1
// y[1] = 2
// y[2] = 9
// y[3] = 28
// x can tinh = 2.5
// Ket qua = 16.625000
}
```
# NoiSuyNewtonTrenLuoiKhongDeu
```
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void NhapDuLieu(int *n, double x[], double y[]) {
    printf("Nhap bac cua da thuc n = ");
    scanf("%d", n);
    printf("Nhap cac diem (x, y):\n");
    for (int i = 0; i <= *n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }
}

void NewtonChiaSaiPhan(int n, double x[], double y[]) {
    double xCanTinh;
    printf("Nhap gia tri x can tinh: ");
    scanf("%lf", &xCanTinh);
    double F[100];
    double ketQua = y[0];
    double tich = xCanTinh - x[0];
    for (int i = 0; i < n; i++) {
        F[i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
    }
    ketQua = ketQua + F[0] * tich;
    for (int j = 2; j <= n; j++) {
        for (int i = 0; i <= n - j; i++) {
            F[i] = (F[i + 1] - F[i]) / (x[i + j] - x[i]);
        }
        tich = tich * (xCanTinh - x[j - 1]);
        ketQua = ketQua + F[0] * tich;
    }
    printf("\nKet qua = %.6lf\n", ketQua);
}

int main() {
    int n;
    double x[100];
    double y[100];
    NhapDuLieu(&n, x, y);
    NewtonChiaSaiPhan(n, x, y);
    return 0;
// test f(x)=x^2+1
// n = 3
// x[0] = 0
// y[0] = 1
// x[1] = 1
// y[1] = 2
// x[2] = 3
// y[2] = 10
// x[3] = 4
// y[3] = 17
// x can tinh = 2
// Ket qua = 5.000000
}
```



#### Lệnh: xoá ghi chú và viết lại code sao cho đơn giản với người đang học tập code cơ bản nhất (giữ nội dung chỉ là đặt biến bằng tiếng Việt để dễ hiểu với viết các lệnh cơ bản thôi với là vẫn chia void)

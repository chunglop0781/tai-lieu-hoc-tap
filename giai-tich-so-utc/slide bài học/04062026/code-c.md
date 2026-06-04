# newtonLui
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 


double noiSuyNewtonLui(double x_n, double x_star, double h, double y_arr[], int n) {
    double t = (x_star - x_n) / h;
    double k = t;
    double *D = (double *)malloc((n + 1) * sizeof(double));
    for (int i = 0; i <= n - 1; i++) {
        D[i] = y_arr[i + 1] - y_arr[i];
    }
    double y = y_arr[n] + t * D[n - 1];
    for (int j = 2; j <= n; j++) {
        for (int i = 0; i <= n - j; i++) {
            D[i] = D[i + 1] - D[i];
        }
        k = k * (t + j - 1) / j; 
        y = y + k * D[n - j];
    }
    
    free(D);
    return y;
}

int main() {
//    int n = 3; 
//    double h = 1.0;
//    double y_arr[] = {0.0, 1.0, 8.0, 27.0}; 
//    double x_n = 3.0;
//    double x_star = 2.5;
	int n;
    double h;
    double x_n;
    double x_star;
    printf("Nhap cac gia tri trong NOI SUY NEWTON LUI:\n");
    printf("n = "); scanf("%d", &n); 
    double y_arr[n + 1];
    printf("Khoang cach h = ");
    scanf("%lf", &h);
    printf("Nhap %d gia tri y0 -> y%d:\n", n + 1, n);
    for (int i = 0; i <= n; i++) {
        printf("y[%d] = ", i);
        scanf("%lf", &y_arr[i]);
    }
    printf("Moc cuoi x_n = ");
    scanf("%lf", &x_n);
    printf("Diem can tinh x* = ");
    scanf("%lf", &x_star);
    double ket_qua = noiSuyNewtonLui(x_n, x_star, h, y_arr, n);
    printf("\nGia tri gan dung f(%.6lf) = %.10lf\n", x_star, ket_qua);
    return 0;
}
```

# newtonTrenLuoiKhongDeu

```
#include <stdio.h>

void noiSuyNewton(int n, double x, double xi[], double yi[], double *y_out) {
    double y = yi[0];
    if (n == 1) {
        *y_out = y;
        return;
    }
    double t = x - xi[0];
    // Co n diem => n-1 sai phan cap 1
    double F[n - 1];
    for (int i = 0; i < n - 1; i++) {
        F[i] = (yi[i + 1] - yi[i]) / (xi[i + 1] - xi[i]);
    }
    y += F[0] * t;
    for (int j = 2; j <= n - 1; j++) {
        for (int i = 0; i <= n - j - 1; i++) {
            F[i] = (F[i + 1] - F[i]) /
                   (xi[i + j] - xi[i]);
        }
        t *= (x - xi[j - 1]);
        y += F[0] * t;
    }
    *y_out = y;
}

int main() {
	//    int n = 4; 
	//    double xi[] = {0.0, 1.0, 2.0, 3.0};
	//    double yi[] = {1.0, 2.0, 4.0, 8.0}; 
	//    double x = 1.5; 

	// int n = 5; 
	//    double xi[] = {3.0, 4.8, 6.0, 8.0, 9.0};
	//    double yi[] = {-4.0, 6.0, 0.0, -1.0, 8.0};
	//    double x[] = {5.0, 7.0};
    int n;
    printf("So diem du lieu n = ");
    scanf("%d", &n);
    if (n < 2) {
        printf("Can it nhat 2 diem du lieu!\n");
        return 1;
    }
    double xi[n];
    double yi[n];
    printf("\nNhap %d gia tri xi:\n", n);
    for (int i = 0; i < n; i++) {
        printf("xi[%d] = ", i);
        scanf("%lf", &xi[i]);
    }
    printf("\nNhap %d gia tri yi:\n", n);
    for (int i = 0; i < n; i++) {
        printf("yi[%d] = ", i);
        scanf("%lf", &yi[i]);
    }
    int k;
    printf("\nSo diem can noi suy = ");
    scanf("%d", &k);
    double tich = 1.0;
    for (int i = 0; i < k; i++) {
        double x;
        double y;
        printf("\nx[%d] = ", i);
        scanf("%lf", &x);
        noiSuyNewton(n, x, xi, yi, &y);
        printf("f(%.6lf) = %.10lf\n", x, y);
        tich *= y;
    }
    printf("\nTich cac gia tri noi suy = %.10lf\n", tich);
    return 0;
}
```

# hinhThangMoRong

```
#include <stdio.h>
#include <math.h>

#define MAX 100

int bac;
double hs[MAX];

/* Tinh P(x) = a0 + a1*x + a2*x^2 + ... + an*x^n */
double f(double x) {
    double result = 0.0;
    for (int i = 0; i <= bac; i++) {
        result += hs[i] * pow(x, i);
    }
    return result;
}

void nhapDuLieu(double *a, double *b, int *n) {
    printf("Nhap bac cua da thuc: ");
    scanf("%d", &bac);
    printf("Nhap cac he so cua da thuc:\n");
    for (int i = 0; i <= bac; i++) {
        printf("He so x^%d: ", i);
        scanf("%lf", &hs[i]);
    }
    printf("Nhap can duoi a: ");
    scanf("%lf", a);
    printf("Nhap can tren b: ");
    scanf("%lf", b);
    printf("Nhap so doan chia n (phai la so chan): ");
    scanf("%d", n);
}

void tinhTichPhan(double a, double b, int n, double *I) {
    double h = (b - a) / n;
    *I = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0)
            *I += 2 * f(x);
        else
            *I += 4 * f(x);
    }
    *I *= h / 3.0;
}

void inKetQua(double I) {
    printf("\nGia tri gan dung cua tich phan la: %lf\n", I);
}

int main() {
    double a, b, I;
    int n;
    // 1+2x+x^2
    // double a = -3.0;
    // double b = 7.0;
    nhapDuLieu(&a, &b, &n);
    if (n <= 0 || n % 2 != 0) {
        printf("n phai la so chan va lon hon 0!\n");
        return 1;
    }
    tinhTichPhan(a, b, n, &I);
    inKetQua(I);
    return 0;
}
```

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
	int n; 
//    double h = 1.0;
	double h;
//    double y_arr[] = {0.0, 1.0, 8.0, 27.0}; 
	double y_arr[n + 1];
//    double x_n = 3.0;
	double x_n;
//    double x_star = 2.5;
	double x_star;
    printf("Nhap cac gia tri trong NOI SUY NEWTON LUI:\n");
    printf("n = "); scanf("%d", &n); 
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

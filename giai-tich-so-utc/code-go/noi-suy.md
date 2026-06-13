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
# NoiSuyNewtonTrenLuoiKhongDeu
```
```

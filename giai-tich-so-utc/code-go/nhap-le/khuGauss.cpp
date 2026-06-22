#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void TimX(int n, double b[100], double a[100][100], double x[100], int *loi){
    *loi = 0;
    if (a[n][n] == 0){
        *loi = 1;
        return;
    }
    x[n] = b[n] / a[n][n];
    for (int i = n - 1; i >= 1; i--){
        double tong = b[i];
        for (int j = i + 1; j <= n; j++){
            tong = tong - a[i][j] * x[j];
        }
        if (a[i][i] == 0){
            *loi = 1;
            return;
        }
        x[i] = tong / a[i][i];
    }
}
void Gauss(int n, double a[100][100], double b[100], double x[100], int *loi){
    *loi = 0;
    for (int cot = 1; cot <= n; cot++){
        if (a[cot][cot] == 0){
            *loi = 1;
            return;
        }
        for (int hang = cot + 1; hang <= n; hang++){
            double heSo = a[hang][cot] / a[cot][cot];
            for (int j = cot + 1; j <= n; j++){
                a[hang][j] = a[hang][j] - heSo * a[cot][j];
            }
            b[hang] = b[hang] - heSo * b[cot];
        }
    }
    TimX(n, b, a, x, loi);
}

int main(){
        int n;
        double a[100][100];
        double b[100];
        double x[100];
        int loi;
        printf("Nhap so an n = ");
        scanf("%d", &n);
        printf("Nhap ma tran A:\n");
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                printf("A[%d][%d] = ", i, j); scanf("%lf", &a[i][j]);
            }
        }
        printf("Nhap vector b:\n");
        for (int i = 1; i <= n; i++){
            printf("b[%d] = ", i);
            scanf("%lf", &b[i]);
        }
        Gauss(n, a, b, x, &loi);
    if (loi){
        printf("He khong co nghiem duy nhat.\n");
    } else {
        printf("Nghiem cua he:\n");
        for (int i = 1; i <= n; i++){
            printf("x[%d] = %.4lf\n", i, x[i]);
        }
    }
    return 0;
}
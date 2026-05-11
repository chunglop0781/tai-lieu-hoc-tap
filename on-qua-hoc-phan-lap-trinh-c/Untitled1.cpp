#include <stdio.h>
int main() {
    int n;
    printf("Nhap gia tri n: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("n phai lon hon 0");
        return 0;
    }
    int a[n];
    printf("Vui long nhap tung gia tri cua n:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    int tich = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            tich *= a[i];
        }
    }
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    printf("Tich va min cua day la: %d, %d", tich, min);
    return 0;
}
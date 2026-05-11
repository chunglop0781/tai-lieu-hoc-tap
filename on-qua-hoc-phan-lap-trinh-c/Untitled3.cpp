#include <stdio.h>

int main() {
    int n;
    int a[n];
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Nhap %d so nguyen:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int dem = 0;
    int timthay = 0;
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        int tong = a[i] + a[i + 1];
        int tich = a[i] * a[i + 1];
        if (tong != 0 && tich % tong == 0) {
            dem++;
            if (!timthay) {
                x = a[i];
                y = a[i + 1];
                timthay = 1;
            }
        }
    }
    printf("So cap thoa man: %d\n", dem);
    if (timthay) {
        printf("Mot cap tim duoc: (%d, %d)\n", x, y);
    } else {
        printf("Khong co cap nao thoa man.\n");
    }
    return 0;
}

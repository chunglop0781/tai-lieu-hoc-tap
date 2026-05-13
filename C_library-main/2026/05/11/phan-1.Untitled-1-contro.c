#include <stdio.h>

int main() {

    int n = 3;
    int a[3];

    printf("Vui long nhap 3 so nguyen:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    // Sắp xếp giảm dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {

                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    // In mảng sau sắp xếp
    printf("\nMang sau khi sap xep giam dan:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    // Mảng con trỏ
    int *ptr[3];
    // Gán địa chỉ
    for (int i = 0; i < n; i++) {
        ptr[i] = &a[i];
    }
    // In thông tin
    printf("Thong tin tung phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu a[%d]\n", i);
        printf("Gia tri cua a[%d]      = %d\n", i, a[i]);
        printf("Dia chi cua a[%d]      = %p\n", i, (void*)&a[i]);
        printf("Gia tri con tro ptr[%d]= %p\n", i, (void*)ptr[i]);
        printf("Gia tri tai *ptr[%d]   = %d\n", i, *ptr[i]);
    }
    return 0;
}

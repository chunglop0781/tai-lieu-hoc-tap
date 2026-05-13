#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n = 7;
    int a[7] = {13, -355, 235, 47, 67, 943, 122};
    // Khai báo mảng con trỏ
    int *ptr[7];
    for(int i = 0; i < 5; i++){
        ptr[i] = &a[i]; // ptr lưu địa chỉ của x nếu x nhập lẻ thủ công int *ptr = &x; 
        printf("Gia tri cua tai phan tu thu %d: %d\n", i + 1, a[i]);
        printf("Dia chi cua phan tu thu %d (a[%d]): %p\n", i + 1, i, (void*)&ptr[i]); // In địa chỉ dạng hex
        printf("Gia tri cua con tro ptr[%d] (dia chi ma ptr tro den): %p\n", i, (void*)ptr[i]); // In địa chỉ mà con trỏ đang trỏ đến
        printf("Gia tri tai *ptr[%d]: %d\n", i, *ptr[i]); // In giá trị tại địa chỉ con trỏ
        printf("\n");
    }
    return 0;
}

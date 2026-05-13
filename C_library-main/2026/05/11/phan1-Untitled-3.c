#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int x, y, z;
    printf("Vui long 3 bien so nguyen x, y, z: ");
    scanf("%d %d %d", &x, &y, &z);
    int *ptr;  
    ptr = &x; *ptr = *ptr + 100;
    // không cần gõ thêm x = *ptr; vì x đã tự đổi
    ptr = &y; *ptr = *ptr + 100;
    ptr = &z; *ptr = *ptr + 100;
    printf("Gia tri cua x, y, z sau khi cong tung bien them 100 la: %d %d %d\n", x, y, z);
}
#include <stdio.h>

int main() {
    printf("1.5 * (11 / 3) = %0.2f\n", 1.5 * (11 / 3));
    printf("1.5 * 11 / 3 = %0.2f\n", 1.5 * 11 / 3);
    printf("(11 / 3) * 1.5 = %0.2f\n", (11 / 3) * 1.5);
    printf("11 / 3 * 1.5 = %0.2f\n", 11 / 3 * 1.5);
    printf("11 / 3 + 1.5 = %0.2f\n", 11 / 3 + 1.5);
    printf("Gia tri cua quan he 3 > 7 la: %d\n", 3 > 7);
    printf("Gia tri cua quan he 7 > 3 la: %d\n", 7 > 3);
    printf("Gia tri cua phep toan 3 && 7 la: %d\n", 3 && 7);

    {
        int x = 10;
        int y = 11;
        printf("Khi x = 10 va y = 11 thi cau lenh: \n");
        printf("\"\\n%%6d\\n%%6d\\n%%6d\", se in ra (gia tri sai):\n");
        printf("%6d\n", x-- * ++y);
        printf("%6d\n", x-- - --y);
        printf("%6d\n", x++ + ++y);
    }

    getchar();
}

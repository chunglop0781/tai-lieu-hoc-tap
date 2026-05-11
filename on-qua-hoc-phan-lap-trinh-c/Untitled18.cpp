#include <stdio.h>
#include <string.h>



int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled18.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled18.txt!");
		return 1;
	}
	int m, n;
    int mt[100][100];
    fscanf(f, "%d\n", &m);
    fscanf(f, "%d\n", &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &mt[i][j]);
        }
    }
    fclose(f);
    printf("Ma tran trong file:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", mt[i][j]);
        }
        printf("\n");
    }
    int min = mt[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
        	if (min > 0 && min > mt[i][j]) {
        		min = mt[i][j];
			}
        }
    }
    printf("Phan tu duong nho nhat cua ma tran: %d\n", min);
    int x;
    int found = 0;
    printf("Nhap so x: ");
    scanf("%d", &x);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mt[i][j] == x) {
                printf("Tim thay x tai: Cot %d, Hang %d\n", j + 1, i + 1);
                found = 1;
            }
			}
        }
    if (!found) {
        printf("Khong co phan tu nao bang x trong ma tran.\n");
    }
    return 0;
}
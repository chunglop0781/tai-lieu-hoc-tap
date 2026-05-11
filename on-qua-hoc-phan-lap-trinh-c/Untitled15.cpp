#include <stdio.h>
#include <string.h>



int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled15.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled15.txt!");
		return 1;
	}
	int m, n;
    int mt[100][100];
    fscanf(f, "%d\n", &m);
    fscanf(f, "%d\n", &n);
	printf("m = %d, n = %d\n", m, n);
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
    int phantuchan = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mt[i][j] % 2 == 0) {
            	phantuchan += mt[i][j];
			}
        }
    }
    printf("Tong cac phan tu chan cua ma tran bang: %d\n", phantuchan);
    int j;
    printf("Nhap gia tri j (j <= %d): ", n);
    scanf("%d", &j);
    if (j >= 0 && j <= n) {
    	for (int i = 0; i < m; i++) {
            printf("%4d", mt[i][j-1]);
        	printf("\n");
    	}
	} else {
		printf("Loi gia tri j!\n");
		return 1;
	}
    return 0;
}
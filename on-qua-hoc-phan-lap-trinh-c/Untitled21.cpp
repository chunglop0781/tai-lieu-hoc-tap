#include <stdio.h>
#include <string.h>



int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled21.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled21.txt!");
		return 1;
	}
	int n;
    int mt[100][100];
    fscanf(f, "%d\n", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &mt[i][j]);
        }
    }
    fclose(f);
    printf("Ma tran trong file:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", mt[i][j]);
        }
        printf("\n");
    }
	int max;
	for (int i = n - 1; i >= 0; i--) {
    	for (int j = n - 1; j >= 0; j--) {
        	if (i + j > n - 1 && mt[i][j] % 2 != 0) {
            	if (mt[i][j] > max) {
                	max = mt[i][j];
            	}
        	}
    	}
	}
	printf("Max phan tu le ben duoi duong cheo phu = %d\n", max);
	printf("Phan tu nam ben tren duong cheo phu co gia tri bang Max la:\n");
	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
        	if (i + j < n - 1 && mt[i][j] == max) {
            	printf("Phan tu = %d tai hang %d, cot %d.\n", mt[i][j], i+1, j+1);
        	}
    	}
	}
	return 0;
}
#include <stdio.h>
#include <string.h>



int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled17.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled17.txt!");
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
    int min = mt[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
        	if (min > mt[i][j]) {
        		min = mt[i][j];
			}
        }
    }
    printf("Gia tri nho nhat cua cac phan tu cua ma tran: %d\n", min);
    int dem = 0;
	printf("Cac cot chua gia tri nho nhat: ");
	for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
        if (mt[i][j] == min) {
        	printf("%d\n", j+1);
        	dem++;
            break;
        } }
    }
	printf("So cot chua gia tri nho nhat: %d\n", dem);
    return 0;
}
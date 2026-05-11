#include <stdio.h>
#include <string.h>



int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled16.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled16.txt!");
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
    int tongcot[100];
    int tongle = 0;
    int tongcotchan = 0;
    int tongcotle = 0;
    int phantule = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            	tongcot[j] += mt[i][j];
            	if (mt[i][j] % 2 != 0) {
            		tongle += mt[i][j];
            		phantule++;
				}
        }
    }
    for (int j = 0; j < n; j++) {
            if (tongcot[j] % 2 == 0) {
            	tongcotchan++;
			} else {
            	tongcotle++;
			}
	}
    printf("Tong cua cac cot bang:\n");
        for (int j = 0; j < n; j++) {
            printf("Cot %d = %d\n", j+1, tongcot[j]);
        }
    printf("So tong cot la so chan bang: %d\n", tongcotchan);
    printf("So tong cot la so le bang: %d\n", tongcotle);
    double tbc;
    tbc = tongle/phantule;
    printf("Trung binh cong cac phan tu le cua ma tran bang : %.2f\n", tbc);
    return 0;
}
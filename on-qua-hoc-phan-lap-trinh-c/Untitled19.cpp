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
    int x;
    printf("Nhap so nguyen x: ");
    scanf("%d", &x);
    int tonggtlon = 0;
    int demgtlon = 0;
    double tbcgtlon;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (x < mt[i][j]) {
            	tonggtlon += mt[i][j];
            	demgtlon++;
			}
        }
    }
    tbcgtlon = tonggtlon / demgtlon;
    printf("Trung binh cong cac phan tu cua ma tran co gia tri lon hon x la: %.2f\n", tbcgtlon);
	int tonghang[100];
	int dem = 0;
    for (int i = 0; i < m; i++) {
    	tonghang[i] = 0;
        for (int j = 0; j < n; j++) {
            	tonghang[i] += mt[i][j];
        }
    }
	printf("Tong cac phan tu cua moi hang:\n");
    for (int i = 0; i < m; i++) {
        printf("Hang %d co tong = %d\n", i + 1, tonghang[i]);
        if (tonghang[i] < 0) {
            dem++;
        }
    }
    printf("So hang co tong am la: %d\n", dem);
    return 0;
}
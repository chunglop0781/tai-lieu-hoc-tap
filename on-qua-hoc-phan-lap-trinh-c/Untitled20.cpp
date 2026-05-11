#include <stdio.h>
#include <string.h>



int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled20.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled20.txt!");
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
    double a, b;
    printf("Vui long nhap gia tri a, b: ");
    scanf("%lf %lf", &a, &b);
    int tongdk = 0;
    int ptdk = 0;
    double tbcdk;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(a <= mt[i][j] && b <= mt[i][j]) {
            	tongdk += mt[i][j];
            	ptdk++;
			}
        }
    }
    tbcdk = tongdk / ptdk;
    printf("Trung binh cong cac phan tu (cua ma trsn) co gia tri trong doan [a,b] voi a, b la cac so thuc bang: %.2f\n", tbcdk);
    int phantuam_min, phantuam_max;
	for (int i = 0; i < m; i++) {
	    for (int j = 0; j < n; j++) {
	        if (mt[i][j] < 0) {
                	if (mt[i][j] > phantuam_max)
                    	phantuam_max = mt[i][j];
                	if (mt[i][j] < phantuam_min)
                    	phantuam_min = mt[i][j];
        	}
    	}
	}
	printf("Mot phan tu am co gia tri lon nhat va mot phan tu am co gia tri nho nhat bang: %d, %d\n", phantuam_max, phantuam_min);
	    return 0;
}
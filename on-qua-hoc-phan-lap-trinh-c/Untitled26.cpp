#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    int mau;
    double khoangcach;
} Diem;

int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled26.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled26!\n");
		return 1;
	}
	int n;
	fscanf(f, "%d\n", &n);
	Diem d[100];
	for (int i = 0; i < n; i++) {
		fscanf(f, "%lf %lf %d\n", &d[i].x, &d[i].y, &d[i].mau);
	}
    fclose(f);
    double maxdo = 0;
    double tongxanh = 0;
    for (int i = 0; i < n; i++) {
    	d[i].khoangcach = pow(pow(d[i].x,2) + pow(d[i].y,2),1.0/2);
    	if (d[i].mau == 1) {
            if (d[i].khoangcach > maxdo)
                maxdo = d[i].khoangcach;
        }
        if (d[i].mau == 3) {
            tongxanh += fabs(d[i].y);
        }
	}
	printf("Khoang cach max tu diem do den O(0,0): %.2lf\n", maxdo);
    printf("Tong khoang cach tu cac diem xanh den truc Ox: %.2lf\n", tongxanh);
    return 0;
}
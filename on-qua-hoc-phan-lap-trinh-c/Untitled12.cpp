#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	int x;
	int y;
	double dodai;
} Diem;

int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled12.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled12.txt!\n");
		return 1;
	}
	int n;
	fscanf(f, "%d\n", &n);
	Diem d[100];
	for (int i = 0; i < n; i++) {
		fscanf(f, "%d %d\n", &d[i].x, &d[i].y);
	}
	int r;
	printf("Nhap he so ban kinh R: ");
	scanf("%d", &r);
	int dem = 0;
	for (int i = 0; i < n; i++) {
		d[i].dodai = pow(pow(d[i].x, 2) + pow(d[i].y, 2),1.0/2);
		if (d[i].dodai - r < 0) {
			dem++;
		}
	}
	printf("So diem nam ben trong hinh tron tam tai goc 0(0,0) ban kinh r = %d la: %d\n", r, dem);
	int x_min = d[0].x, x_max = d[0].x;
	int y_min = d[0].y, y_max = d[0].y;
	for (int i = 1; i < n; i++) {
		if (d[i].x < x_min) {
			x_min = d[i].x;
		}
		if (d[i].x > x_max) {
			x_max = d[i].x;
		}
		if (d[i].y < y_min) {
			y_min = d[i].y;
		}
		if (d[i].y > y_max) {
			y_max = d[i].y;
		}
	}
	int dientich;
	dientich = (x_max - x_min) * (y_max - y_min);
	printf("Dien tich can tim bang %d.\n", dientich);
	return 0;
}
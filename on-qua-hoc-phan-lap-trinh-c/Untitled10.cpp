#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	int x;
	int y;
	int dodai;
	int benngoai;
	double dientich;
} Diem;

int main() {
	FILE *f = fopen("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled10.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled10.txt!");
	}
	int n;
	fscanf(f, "%d\n", &n);
	Diem d[100];
	for (int i = 0; i < n; i++) {
		fscanf(f, "%d %d\n", &d[i].x, &d[i].y);
	}
	printf("Cac diem vua nhap:\n");
	for (int i = 0; i < n; i++) {
		printf("Diem %d: (%d, %d)\n", i+1, d[i].x, d[i].y);
	}
	int r;
	printf("Nhap he so ban kinh R: ");
	scanf("%d", &r);
	for (int i = 0; i < n; i++) {
		d[i].dodai = sqrt(d[i].x * d[i].x + d[i].y * d[i].y);
	}
	int benngoai = 0;
	for (int i = 0; i < n; i++) {
		if (d[i].dodai - r > 0) {
			benngoai++;
		}
	}
	printf("So diem nam ben ngoai hinh tron tam tai goc O(0,0) ban kinh R: %d\n", benngoai);
	int xmin = d[0].x, xmax = d[0].x;
	int ymin = d[0].y, ymax = d[0].y;
	for (int i = 0; i < n; i++) {
		if (d[i].x < xmin) xmin = d[i].x;
		if (d[i].x > xmax) xmax = d[i].x;
		if (d[i].y < ymin) ymin = d[i].y;
		if (d[i].y > ymax) ymax = d[i].y;
	}
	int dientich = (xmax - xmin) * (ymax - ymin);
	printf("Toa do cac dinh cua hinh chu nhat:\n");
		printf("A(%d, %d)\n", xmin, ymin);
		printf("B(%d, %d)\n", xmax, ymin);
		printf("C(%d, %d)\n", xmax, ymax);
		printf("D(%d, %d)\n", xmin, ymax);
	printf("Dien tich nho nhat = %d\n", dientich);
	return 0;
}
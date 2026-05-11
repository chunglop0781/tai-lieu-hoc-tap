#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} Diem;

int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled13.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled13.txt!");
		return 1;
	}
	int n;
	Diem d[100];
	fscanf(f, "%d\n", &n);
	for (int i = 0; i < n; i++) {
		fscanf(f, "%d %d\n", &d[i].x, &d[i].y);
	}
	int a,b;
	printf("Nhap he so a va b: ");
	scanf("%d %d", &a, &b);
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (d[i].y > a * d[i].x + b) {
			dem++;
		}
	}
	printf("So diem nam ben tren (khong thuoc) duong thang y=ax+b la: %d.\n", dem);
	int qp1 = 0, qp2 = 0;
	for (int i = 0; i < n; i++) {
		if (d[i].x > 0 && d[i].y > 0) {
			qp1++;
		}
		if (d[i].x < 0 && d[i].y > 0) {
			qp2++;
		}
	}
	printf("So diem nam ben trong goc phan tu thu nhat la: %d.\n", qp1);
	printf("So diem nam ben trong goc phan tu thu hai la: %d.\n", qp2);
	double dodai = 0;
	for (int i = 0; i < n - 1; i++) {
		if (d[i].x < 0 && d[i].y < 0 && d[i+1].x < 0 && d[i+1].y < 0) {
			dodai += pow(pow(d[i+1].x - d[i].x, 2) + pow(d[i+1].y - d[i].y, 2), 1.0/2);
		}
	}
	printf("Do dai cac diem nam ben trong goc phan tu thu ba la: %.2f.\n", dodai);
	return 0;
}
#include <stdio.h>

int main() {
	int n;
	printf("Vui long nhap so mang n: ");
	scanf("%d", &n);
	int x[100];
	int y[100];
	printf("Vui long nhap x va y cua tung diem.\n");
	for(int i = 0; i < n; i++){
		printf("Diem thu %d.\n", i + 1);
		printf("x = ");
		scanf("%d", &x[i]);
		printf("y = ");
		scanf("%d", &y[i]);
	}
	printf("Cac toa do diem vua nhap:\n");
	for(int i = 0; i < n; i++) {
	printf("Diem thu %d co toa do (%d, %d).\n", i+1, x[i], y[i]);
	}
	double a, b;
	printf("Nhap 2 so thuc a va b: ");
	scanf("%lf %lf", &a, &b);
	int diem_nam_phia_tren = 0;
	for(int i = 0; i < n; i++) {
		if (y[i] > a * x[i] + b) {
			diem_nam_phia_tren++;
		}
	}
	printf("So diem nam phia tren (khong thuoc) duong thang y=ax+b la: %d\n", diem_nam_phia_tren);
	int so_doan_thang_nam_ben_trong = 0;
	for(int i = 0; i < n; i++) {
		if (y[i] * y[i] + x[i] * x[i] < 5 * 5) {
			so_doan_thang_nam_ben_trong++;
		}
	}
	printf("So doan thang nam ben trong hinh tron tam tai goc O(0,0) ban kinh = 5 la: %d\n", so_doan_thang_nam_ben_trong);
	return 0;
}
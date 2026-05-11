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
	int dem_thuoc = 0;
	int dem_tren = 0;
	int dem_duoi = 0;
	for(int i = 0; i < n; i++){
		if (y[i] == -x[i]) {
			dem_thuoc++;
		}
		if(y[i] > -x[i]) {
			dem_tren++;
		}
		if(y[i] < -x[i]) {
			dem_duoi++;
		}
	}
	printf("So diem nam tren (thuoc), so diem nam phia tren va so diem nam phia duoi duong thang chua duong phan giac cua goc phan tu thu II la: %d, %d, %d\n", dem_thuoc, dem_tren, dem_duoi);
	int goc_phan_tu_thu_nhat = 0;
	int goc_phan_tu_thu_hai = 0;
	for(int i = 0; i < n; i++){
		if(x[i] > 0  && y[i] > 0) {
			goc_phan_tu_thu_nhat++;
		}
		if(y[i] > 0 && x[i] < 0) {
			goc_phan_tu_thu_hai++;
		}
	}
	printf("So doan thang nam trong goc phan tu thu I va so doan thang nam trong goc phan tu thu II la: %d, %d\n", goc_phan_tu_thu_nhat, goc_phan_tu_thu_hai);
}
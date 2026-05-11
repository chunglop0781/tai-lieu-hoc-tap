#include <stdio.h>

int main() {
	int n;
	printf("Vui long nhap so nguyen n: ");
	scanf("%d", &n);
	double a[100];
	printf("Vui long nhap so thuc a1, a2, ..., an:\n");
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%lf", &a[i]);
	}
	double x;
	printf("Vui long nhap gia tri thuc x:\n");
	scanf("%lf", &x);
	int sogiatribangx = 0;
	double tong = 0;
	int sogiatrilonhonx = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			sogiatribangx++;
		}
		if (a[i] > x) {
			tong += a[i];
			sogiatrilonhonx++;
		}
	}
	printf("So phan tu co gia tri bang x = %d\n", sogiatribangx);
	if (sogiatrilonhonx > 0) {
		double tbc = tong / sogiatrilonhonx;
		printf("TBC = %.2f\n", tbc);
	} else {
		printf("Khong co phan tu nao lon hon x\n");
	}
	return 0;
}
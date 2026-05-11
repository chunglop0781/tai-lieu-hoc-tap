#include <stdio.h>

int main() {
	int n;
	printf("Nhap he so n: ");
	scanf("%d", &n);
	printf("Nhap tung phan tu con cua mang n:\n");
	double a[100];
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%lf", &a[i]);
	}
	double min = a[0] * a[1] * a[2];
	int vitri = 0;
	for (int i = 1; i <= n - 3; i++) {
		double tich = a[i] * a[i+1] * a[i+2];
		if (tich < min) {
			min = tich;
			vitri = i;
		}
	}
	printf("\n");
	printf("Bo 3 phan tu co tich nho nhat: %.2f, %.2f, %.2f\n", a[vitri], a[vitri + 1], a[vitri + 2]);
	printf("Tich nho nhat: %.2f\n", min);
}
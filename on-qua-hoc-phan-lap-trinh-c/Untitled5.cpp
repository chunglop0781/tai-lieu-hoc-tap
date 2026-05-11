#include <stdio.h>

int main () {
	int n;
	printf("Nhap phan tu n: ");
	scanf("%d", &n);
	printf("Nhap cac phan tu cua day n:\n");
	int a[100];
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int min;
	for (int i = 0; i < n; i++) {
		if (min > a[i]) {
			min = a[i];
		}
	}
	printf("Min  = %d", min);
	if (min % 2 == 0) {
		printf("Min la so chan.\n");
	} else {
		printf("Min la so le.\n");
	}
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 3 && a[i] <= 50) {
			dem++;
		}
	}
	printf("Cac phan tu cua day thuoc [3,50] la: %d", dem);
}
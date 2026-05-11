#include <stdio.h>

int main() {
	int n;
	printf("Nhap cac gia tri nguyen cua n va tung gia tri cua tung n.\n");
	printf("Phan tu S1.\n");
	printf("n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++) {
	printf("a[%d] = ", i);
	scanf("%d", &a[i]);
	}
	printf("Phan tu S2.\n");
	printf("n = ");
	scanf("%d", &n);
	int b[n];
	for(int i = 0; i < n; i++) {
	printf("b[%d] = ", i);
	scanf("%d", &b[i]);
	}
	int S1 = 0;
	for(int i = 0; i < n; i++) {
	 if(a[i] % 2 == 0) {
	 	S1++;
	 }
	}
	int S2 = 0;
	for(int i = 0; i < n; i++) {
	 	S2 += b[i];
	}
	if(S2 == 0) {
		printf("Loi phep tinh, vui long nhap lai phan tu n2.\n");
		return 1;
	}
	float T = (float)S1 / S2;
	printf("T = %.2f", T);
	return 0;
}
#include <stdio.h>

struct hang {
	char mahang[20];
	int soluong;
	double dongia;
};

double giatri(struct hang h) {
	return h.soluong * h.dongia;
}

int main() {
	int n;
	printf("Nhap so loai hang: ");
	scanf("%d", &n);
	struct hang a[100];
	for (int i = 1; i < n + 1; i++) {
		printf("Nhap thong tin loai hang thu %d\n", i);
		printf("Ma hang: ");
		scanf("%s", &a[i].mahang);
		printf("So luong: ");
		scanf("%d", &a[i].soluong);
		printf("Don gia: ");
		scanf("%lf", &a[i].dongia);
	}
	printf("=> Danh sach hang vua nhap\n");
	for (int i = 1; i < n + 1; i++) {
		printf("Hang thu %d --- Ma hang: %s --- So luong: %d --- Don gia: %.2f --- Gia tri = %.2f\n", i, a[i].mahang, a[i].soluong, a[i].dongia, giatri(a[i]));
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (giatri(a[i]) < giatri(a[j])) {
				struct hang temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("=> Danh sach sau khi sap xep giam dan theo gia tri:\n");
	for (int i = 0; i < n; i++) {
		printf("Hang thu %d --- Ma hang: %s --- So luong: %d --- Don gia: %.2f --- Gia tri = %.2f\n", i, a[i].mahang, a[i].soluong, a[i].dongia, giatri(a[i]));
	}
	double tong = 0;
	for (int i = 0; i < n; i++) {
		tong += giatri(a[i]);
	}
	printf("=> Tong gia tri cac loai hang = %.2f\n", tong);
	return 0;
}
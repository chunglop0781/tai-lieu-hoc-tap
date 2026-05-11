#include <stdio.h>
#include <string.h>

typedef struct {
	char mahang[20];
	int soluong;
	double dongia;
	double giatri;
} hang;


int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled30.txt", "r");
	if (f == NULL) {
		printf("Khong mo duoc file Untitled30.txt!\n");
		return 1;
	}
	int n;
	fscanf (f, "%d\n", &n);
	hang h[100];
	for (int i = 0; i < n; i++) {
	fscanf(f, "%s %d %lf\n", h[i].mahang, &h[i].soluong, &h[i].dongia);
	h[i].giatri = h[i].soluong * h[i].dongia;
	}
	fclose (f);
	printf("Danh sach hang\n");
	for (int i = 0; i < n; i++) {
		printf("Hang thu %d --- Ma hang: %s --- So luong: %d --- Don gia: %.2f --- Gia tri = %.2f\n", i + 1, h[i].mahang, h[i].soluong, h[i].dongia, h[i].giatri);

	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (h[i].giatri < h[j].giatri) {
				hang temp = h[i];
				h[i] = h[j];
				h[j] = temp;
			}
		}
	}
	printf("=> Danh sach sau khi sap xep giam dan theo gia tri:\n");
	for (int i = 0; i < n; i++) {
		printf("Ma hang: %s --- So luong: %d --- Don gia: %.2f --- Gia tri = %.2f\n", h[i].mahang, h[i].soluong, h[i].dongia, h[i].giatri);
	}
	double tong = 0;
	for (int i = 0; i < n; i++) {
		tong += h[i].giatri;
	}
	printf("=> Tong gia tri cac loai hang = %.2f\n", tong);
	return 0;
}
#include <stdio.h>
#include <string.h>

typedef struct {
	char hoten[100];
	double toan;
	double ly;
	double hoa;
	double tongdiem;
} HocSinh;

int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled22.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled22!\n");
		return 1;
	}
	int n;
	fscanf(f, "%d\n", &n);
	HocSinh hs[100];
	for (int i = 0; i < n; i++) {
		fgets(hs[i].hoten, 100, f);
		hs[i].hoten[strcspn(hs[i].hoten, "\n")] = 0; //Tieng Viet co cach trong file txt thi phai co them cai nay
		fscanf(f, "%lf %lf %lf\n", &hs[i].toan, &hs[i].ly, &hs[i].hoa);
	}
	char tentoancao[100];
	double diemtoanmax;
	strcpy(tentoancao, hs[0].hoten);
	for (int i = 0; i < n; i++) {
			if (hs[i].toan > diemtoanmax) {
				strcpy(tentoancao, hs[i].hoten);
				diemtoanmax = hs[i].toan;
		}
	}
	printf("Hoc sinh co diem toan cao nhat la: %s (%.2f diem)\n", tentoancao, diemtoanmax);
	for (int i = 0; i < n; i++) {
		hs[i].tongdiem = hs[i].toan + hs[i].ly + hs[i].hoa;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)  {
			if (hs[i].tongdiem < hs[j].tongdiem) {
				HocSinh temp = hs[i];
				hs[i] = hs[j];
				hs[j] = temp;
			}
		}
	}
	printf("\n");
	printf("3 hoc sinh co tong diem cao nhat:\n");
	for (int i = 0; i < 3; i++) {
		printf("Ten: %s | Tong diem: %.2f\n", hs[i].hoten, hs[i].tongdiem);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)  {
			if (hs[i].tongdiem > hs[j].tongdiem) {
				HocSinh temp = hs[i];
				hs[i] = hs[j];
				hs[j] = temp;
			}
		}
	}
	printf("\n");
	printf("3 hoc sinh co tong diem thap nhat:\n");
	for (int i = 0; i < 3; i++) {
		printf("Ten: %s | Tong diem: %.2f\n", hs[i].hoten, hs[i].tongdiem);
	}
	printf("\n");
	return 0;
}
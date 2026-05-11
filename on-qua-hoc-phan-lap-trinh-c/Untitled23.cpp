#include <stdio.h>
#include <string.h>

typedef struct {
    char masv[20];
    char hoten[100];
    char quequan[100];
    double diemtrungbinh;
} SinhVien;

int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled23.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled23!\n");
		return 1;
	}
	int n;
	fscanf(f, "%d\n", &n);
	SinhVien sv[100];
	for (int i = 0; i < n; i++) {
		fgets(sv[i].masv, 100, f);
		sv[i].masv[strcspn(sv[i].masv, "\n")] = 0;
		fgets(sv[i].hoten, 100, f);
		sv[i].hoten[strcspn(sv[i].hoten, "\n")] = 0;
		fgets(sv[i].quequan, 100, f);
		sv[i].quequan[strcspn(sv[i].quequan, "\n")] = 0;
		fscanf(f, "%lf\n", &sv[i].diemtrungbinh);
	}
	printf("Danh sach cua %d sinh vien:\n", n);
	for (int i = 0; i < n; i++) {
		printf("Ho ten: %s | Ma SV: %s | Que quan: %s | Diem TB: %.2f\n", sv[i].hoten, sv[i].masv, sv[i].quequan, sv[i].diemtrungbinh);
	}
	printf("\n");
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (sv[i].diemtrungbinh > sv[j].diemtrungbinh) {
					SinhVien temp = sv[i];
					sv[i] = sv[j];
					sv[j] = temp;
				}
			}
		}
	printf("Danh sach cua %d sinh vien theo chieu giam dan cua diem trung binh:\n", n);
	for (int i = 0; i < n; i++) {
		printf("Ho ten: %s | Ma SV: %s | Que quan: %s | Diem TB: %.2f\n", sv[i].hoten, sv[i].masv, sv[i].quequan, sv[i].diemtrungbinh);
	}
	printf("\n");
	double x;
	printf("Nhap so thuc x: ");
	scanf("%lf", &x);
	printf("Danh sach sinh vien co diem trung binh lon hon hoac bang x la:\n", n);
		for (int i = 0; i < n; i++) {
				if (sv[i].diemtrungbinh >= x) {
					printf("Ho ten: %s | Ma SV: %s | Que quan: %s | Diem TB: %.2f\n", sv[i].hoten, sv[i].masv, sv[i].quequan, sv[i].diemtrungbinh);
			}
		}
	printf("\n");
	return 0;
}
#include <stdio.h>
#include <string.h>

typedef struct {
    char masv[20];
    char hoten[100];
    char khoa;
    double diemtb;
} SinhVien;

int main() {
    FILE *f = fopen("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\test1.txt", "r");
    if (f == NULL) {
        printf("Khong mo duoc file!\n");
        return 1;
    }
    int n;
    fscanf(f, "%d\n", &n);
    SinhVien sv[100];
    for (int i = 0; i < n; i++) {
	fgets(sv[i].hoten, 100, f);
	sv[i].hoten[strcspn(sv[i].hoten, "\n")] = 0;
	fscanf(f, "%s %c %lf\n", &sv[i].masv, &sv[i].khoa, &sv[i].diemtb);
	}
	fclose(f);
	printf("Thong tin cac sinh vien:\n");
	for (int i = 0; i < n; i++) {
		printf("Ho ten: %s | Ma SV: %s | Khoa: %c | Diem TB: %.2f\n", sv[i].hoten, sv[i].masv, sv[i].khoa, sv[i].diemtb);
	}
    return 0;
}

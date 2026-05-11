#include <stdio.h>
#include <string.h>

typedef struct{
	char msv[100];
	char hoten[100];
	char que[100];
	double toan;
	double ly;
	double hoa;
	double tongdiem;
} ThiSinh;


int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.03\\on-qua-hoc-phan-lap-trinh-c\\(26.03.2026).txt", "r");
	if (f == NULL) {
		printf("Loi file (26.03.2026)!");
		return 1;
	}
	int n;
	fscanf(f, "%d\n", &n);
	ThiSinh ts[100];
	for (int i = 0; i < n; i++) {
		fgets(ts[i].msv, 100, f);
		ts[i].msv[strcspn(ts[i].msv, "\n")] = 0;
		fgets(ts[i].hoten, 100, f);
		ts[i].hoten[strcspn(ts[i].hoten, "\n")] = 0;
		fgets(ts[i].que, 100, f);
		ts[i].que[strcspn(ts[i].que, "\n")] = 0;
		fscanf(f, "%lf %lf %lf\n", &ts[i].toan, &ts[i].ly, &ts[i].hoa);
	}
	fclose(f);
	double diemchuan;
	printf("Nhap diem chuan: ");
	scanf("%lf", &diemchuan);
	printf("Danh sach cua %d sinh vien:\n", n);
	for (int i = 0; i < n; i++) {
		ts[i].tongdiem = ts[i].toan + ts[i].ly + ts[i].hoa;
		printf("Ho ten: %s | Ma SV: %s | Que quan: %s | Diem Toan: %.2f| Diem Ly: %.2f| Diem Hoa: %.2f | Tong diem: %.2f\n", ts[i].hoten, ts[i].msv, ts[i].que, ts[i].toan, ts[i].ly, ts[i].hoa, ts[i].tongdiem);
	}
	printf("\n");
	printf("Danh sach nhung thi sinh do dai hoc que o Ha Noi:\n");
	for (int i = 0; i < n; i++) {
		ts[i].tongdiem = ts[i].toan + ts[i].ly + ts[i].hoa;
		if (ts[i].tongdiem >= diemchuan && strcmp(ts[i].que, "Ha Noi") == 0){
			printf("Ho ten: %s | Ma SV: %s | Diem Toan: %.2f| Diem Ly: %.2f| Diem Hoa: %.2f | Tong diem: %.2f\n", ts[i].hoten, ts[i].msv, ts[i].toan, ts[i].ly, ts[i].hoa, ts[i].tongdiem);
		}
	}
	printf("\n");
	printf("Danh sach nhung thi sinh co diem Toan cao nhat:\n");
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (ts[i].toan < ts[j].toan){
				ThiSinh temp = ts[i];
				ts[i] = ts[j];
				ts[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("Ho ten: %s | Ma SV: %s | Que quan: %s | Diem Toan: %.2f\n", ts[i].hoten, ts[i].msv, ts[i].que, ts[i].toan);
	}
	return 0;
}
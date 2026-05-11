#include <stdio.h>
#include <string.h>

typedef struct {
	char hoten[100];
	int diem;
	char truong[100];
} ThiSinh;

typedef struct {
	char ten[2];
	int tong;
} Truong;



int main() {
	FILE *f = fopen("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled28.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled28.txt!\n");
		return 1;
	}
	int n;
	fscanf(f, "%d\n", &n);
	ThiSinh ts[100];
	for (int i = 0; i < n; i++) {
		fscanf(f, "%s %d %s\n", &ts[i].hoten, &ts[i].diem, &ts[i].truong);
	}
	fclose(f);
	Truong t[3] = {{"A", 0}, {"B", 0}, {"C", 0}};
	for (int i = 0; i < n; i++) {
		if (strcmp(ts[i].truong, "A") == 0) t[0].tong += ts[i].diem;
		if (strcmp(ts[i].truong, "B") == 0) t[1].tong += ts[i].diem;
		if (strcmp(ts[i].truong, "C") == 0) t[2].tong += ts[i].diem;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (t[i].tong < t[j].tong) {
				Truong tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			}
		}
	}
	printf("3 truong co tong so diem theo lan luot tu cao den thap:\n");
	for (int i = 0; i < 3; i++) {
		printf("Truong %s: %d\n", t[i].ten, t[i].tong);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ts[i].diem > ts[j].diem) {
				ThiSinh tmp = ts[i];
				ts[i] = ts[j];
				ts[j] = tmp;
			}
		}
	}
	printf("3 thi sinh co tong diem thap nhat:\n");
	for (int i = 0; i < 3; i++) {
		printf("%s: %d\n", ts[i].hoten, ts[i].diem);
	}
	return 0;
}
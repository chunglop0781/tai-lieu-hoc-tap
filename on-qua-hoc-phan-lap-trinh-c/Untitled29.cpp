#include <stdio.h>
#include <string.h>

typedef struct {
	int bks;
	double tt;
	char cty[100];
} otovantai;

int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled29.txt", "r");
	if (f == NULL) {
		printf("Loi file Untitled29.txt!");
		return 1;
	}
	int n;
	fscanf(f, "%d\n", &n);
	otovantai vt[100];
	for (int i = 0; i < n; i++) {
		fscanf(f, "%d %lf %s\n", &vt[i].bks, &vt[i].tt, &vt[i].cty);
	}
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if(strcmp(vt[i].cty, "B") == 0 && vt[i].bks % 3 == 0) {
			dem++;
		}
	}
	printf("So bks oto B chia het cho 3 la: %d\n", dem);
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if(vt[i].tt > vt[j].tt) {
			otovantai temp = vt[i];
			vt[i] = vt[j];
			vt[j] = temp;
			}
		}
	}
	printf("3 oto co trong tai nho nhat:\n");
	for (int i = 0; i < 3; i++) {
		printf("BSK: %d | TT: %.2f | Cty: %s\n", vt[i].bks, vt[i].tt, vt[i].cty);
	}
}
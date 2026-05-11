#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	double x;
	double y;
} Diem;

int main() {
	FILE *f = fopen("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled11.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled11.txt!");
		return 1;
	}
	int n;
	Diem d[100];
	fscanf(f, "%d\n", &n);
	for (int i = 0; i < n; i++) {
		fscanf(f, "%lf %lf\n", &d[i].x, &d[i].y);
	}
    double tong = 0;
    for (int i = 1; i < n - 1; i++) {
        tong += pow((pow(d[i+1].x - d[i].x, 2) + pow(d[i+1].y - d[i].y, 2)), 1.0/2);
    }
    tong += sqrt(pow(d[0].x - d[n-1].x, 2) + pow(d[0].y - d[n-1].y, 2));
    printf("Do dai duong gap khuc = %.2lf\n", tong);
    double max = 0;
    int a = 0, b = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double kc = pow((pow(d[j].x - d[i].x, 2) + pow(d[j].y - d[i].y, 2)), 1.0/2);
            if (kc > max) {
                max = kc;
                a = i;
                b = j;
            }
        }
    }
    printf("Doan thang dai nhat:\n");
    printf("Diem dau: (%.2lf, %.2lf)\n", d[a].x, d[a].y);
    printf("Diem cuoi: (%.2lf, %.2lf)\n", d[b].x, d[b].y);
    printf("Do dai = %.2lf\n", max);
    return 0;
}
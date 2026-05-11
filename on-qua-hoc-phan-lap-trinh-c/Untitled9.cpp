#include <stdio.h>
#include <string.h>
#include <math.h>


typedef struct{
	int x;
	int y;
	double duongthang1;
	double duongthang2;
	double tong1;
} Diem;


int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled9.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled9.txt!\n");
		return 1;
	}
	int n;
	fscanf(f, "%d\n", &n);
	Diem d[100];
	for (int i = 0; i < n; i++) {
		fscanf(f, "%d %d\n", &d[i].x, &d[i].y);
	}
	printf("Cac diem hien co:\n");
	for (int i = 0; i < n; i++) {
		printf("Diem %d: (%d, %d)\n", i+1, d[i].x, d[i].y);
	}
	for (int i = 0; i < n - 1; i++) {
    	d[i].tong1 = sqrt((d[i+1].x - d[i].x) * (d[i+1].x - d[i].x) + (d[i+1].y - d[i].y) * (d[i+1].y - d[i].y));
	}
	printf("Do dai tung doan cua duong gap khuc:\n");
	for (int i = 0; i < n - 1; i++) {
		printf("Duong %d: %.2f\n", i+1, d[i].tong1);
	}
	double tong3 = 0;
	for (int i = 0; i < n - 1; i++) {
		tong3 += d[i].tong1;
	}
	printf("Do dai duong gap khuc = %.2f\n", tong3);
	int dem = 0;
	double tong2 = 0;
	for (int i = 0; i < n - 1; i++) {
    	for (int j = i + 1; j < n; j++) {
        	if (d[i].y * d[j].y < 0) {
            	dem++;
            	tong2 += sqrt((d[j].x - d[i].x) * (d[j].x - d[i].x) + (d[j].y - d[i].y) * (d[j].y - d[i].y));
        	}
    	}
	}
	printf("So doan thang cat truc OX: %d\n", dem);
	printf("Tong do dai cac doan cat truc OX: %.2f\n", tong2);
	return 0;
}
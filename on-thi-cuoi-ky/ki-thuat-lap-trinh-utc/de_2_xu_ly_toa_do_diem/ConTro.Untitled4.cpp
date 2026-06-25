#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	double x;
	double y;
} Diem;

void xuatRaManHinh(int n, Diem *d){
	printf("Cac diem co trong tep la:\n");
	for(int i = 0; i < n; i++){
		printf("(%.2lf, %.2lf)\n", d[i].x, d[i].y);
	}
}

double khoangCach(Diem dau, Diem cuoi){
    return sqrt(pow(cuoi.x - dau.x, 2) + pow(cuoi.y - dau.y, 2));
}

void xuatDiemGan(FILE *out, int n, Diem *d, double xA, double yA){
    Diem A;
    A.x = xA;
    A.y = yA;
    double *kc = (double*)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++){
        kc[i] = khoangCach(A, d[i]);
    }
    for(int i = 0; i < n - 1; i++){
    	for(int j = i + 1; j < n; j++){
    		if(kc[i] > kc[j]){
    			double temp1 = kc[i];
    			kc[i] = kc[j];
    			kc[j] = temp1;
    			Diem temp2 = d[i];
    			d[i] = d[j];
    			d[j] = temp2;
			}
		}
	}
	fprintf(out, "Cac diem gan A(%.2lf, %.2lf) nhat lan luot la:\n", xA, yA);
	for(int i = 0; i < n; i++){
		fprintf(out, "Diem %d: (%.2lf, %.2lf) - Khoang cach: %.2lf\n", i+1, d[i].x , d[i].y, kc[i]);
	}

	free(kc);
}

int main(){
	FILE *f = fopen("Diem.txt", "r");
	if(f == NULL){
		printf("Loi doc file txt!\n");
		return 1;
	}
	int n; fscanf(f, "%d\n", &n);
	Diem *d = (Diem*)malloc(n * sizeof(Diem));
	for(int i = 0; i < n; i++){
		fscanf(f, "%lf %lf\n", &d[i].x, &d[i].y);
	}
	xuatRaManHinh(n, d);
	double doDaiDuongGapKhuc = 0;
	for(int i = 0; i < n - 1; i++){
		doDaiDuongGapKhuc += khoangCach(d[i], d[i+1]);
	}
	printf("\n=> Do dai duong gap khuc bang = %.3lf\n", doDaiDuongGapKhuc);
	double xA, yA;
	printf("\nNhap (xA, yA) cua diem A: "); scanf("%lf %lf", &xA, &yA);
	FILE *out = fopen("DiemGan.txt", "w");
	xuatDiemGan(out, n, d, xA, yA);
	printf("\n=> Xuat thanh cong file DiemGan.txt!\n");
	fclose(f);
	free(d);
	return 0;
}
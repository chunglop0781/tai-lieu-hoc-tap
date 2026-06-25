#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	double x;
	double y;
} Diem;

void xuatRaManHinh(int n, Diem *d, double tongKhoangCachDenTrucHoanh){
	printf("Cac diem co trong tep la:\n");
	for(int i = 0; i < n; i++){
		printf("(%.2lf, %.2lf)\n", d[i].x, d[i].y);
	}
	printf("\n=> Tong khoang cach cua cac diem den truc hoanh la %.2lf\n", tongKhoangCachDenTrucHoanh);
}

double khoangCach(Diem dau, Diem cuoi){
	return sqrt(pow(cuoi.x - dau.x, 2) + pow(cuoi.y - dau.y, 2));
}

void timDoDaiDoanThangMax(int n, Diem *d){
	double *doanThang = (double*)calloc(n - 1, sizeof(double));
	for(int i = 0; i < n - 1; i++){
		doanThang[i] = khoangCach(d[i], d[i+1]);
	}
	for(int i = 0; i < n - 2; i++){
		for(int j = i + 1; j < n - 1; j++){
			if(doanThang[i] < doanThang[j]){
				double Temp = doanThang[i];
				doanThang[i] = doanThang[j];
				doanThang[j] = Temp;
			}
		}
	}
	printf("\n=> Doan thang co do dai lon nhat la %.3lf", doanThang[0]);
	free(doanThang);
}

int main(){
	FILE *f = fopen("input.txt", "r");
	if(f == NULL){
		printf("Loi file txt!\n");
		return 1;
	}
	int n; fscanf(f, "%d\n", &n);
	Diem *d = (Diem*)malloc(n * sizeof(Diem));
	double tongKhoangCachDenTrucHoanh = 0;
	for(int i = 0; i < n; i++){
		fscanf(f, "%lf %lf\n", &d[i].x, &d[i].y);
		tongKhoangCachDenTrucHoanh += fabs(d[i].y);
	}
	xuatRaManHinh(n, d, tongKhoangCachDenTrucHoanh);
	timDoDaiDoanThangMax(n, d);
	fclose(f);
	free(d);
	return 0;
}
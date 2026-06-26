#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>





void xuatDay(int n,double *a){
	printf("Day so: %.2lf",a[0]);
	for(int i=1;i<n;i++){
		printf(", %.2lf",a[i]);
	}
	printf("\n");
}



void tinhTong(int n,double *a){
	double tong=0;
	for(int i=0;i<n;i++){
		if((int)a[i]%3==0 || (int)a[i]%4==0){
			tong+=a[i];
		}
	}
	printf("Tong cac phan tu chia het cho 3 hoac 4: %.2lf\n",tong);
}



void tinhTrungBinh(int n,double *a){
	double tong=0;
	for(int i=0;i<n;i++){
		tong+=a[i];
	}
	printf("Diem trung binh: %.2lf\n",tong/n);
}



int main(){
	FILE *f = fopen("input.txt", "r");
	if(f ==  NULL){
		printf("Loi file!\n");
		return 1;
	}
	int n; fscanf(f, "%d\n",&n);
	double *a=(double*)malloc(n*sizeof(double));
	for(int i=0;i<n;i++){
		fscanf(f, "%lf", &a[i]);
	}
	xuatDay(n,a);
	tinhTong(n,a);
	tinhTrungBinh(n,a);
	free(a);
	return 0;
}
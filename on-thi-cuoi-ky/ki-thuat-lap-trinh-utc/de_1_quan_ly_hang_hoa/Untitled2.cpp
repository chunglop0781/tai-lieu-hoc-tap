#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	char Ten[30];
	float Gia;
	int SoLuong;
} MatHang;

void Xuat_hangsort(FILE *out, MatHang mh[], int n){
	fprintf(out, "\nCac mat hang sau khi sap xep:\n");
	for(int i = 0; i < n; i++){
		fprintf(out, "STT: %-4d | Mat hang: %-13s | So luong: %8d | Gia: %14.2f\n", i + 1, mh[i].Ten, mh[i].SoLuong, mh[i].Gia);
	}
}

void Xuat_hangton(FILE *out, MatHang mh[], int n){
	fprintf(out, "\nCac mat hang co gia tri tien > 10000 sau khi sap xep:\n");
	for(int i = 0; i < n; i++){
		if(mh[i].Gia > 10000){
			fprintf(out, "STT: %-4d | Mat hang: %-13s | So luong: %8d | Gia: %14.2f\n", i + 1, mh[i].Ten, mh[i].SoLuong, mh[i].Gia);
		}
	}
}

int main(){
	FILE *f = fopen("mathang.txt", "r");
	if(f == NULL){
		printf("Loi file txt!\n");
	}
	int n; fscanf(f, "%d\n", &n);
	float tongTien;
	MatHang mh[100];
	for(int i = 0; i < n; i++){
		fgets(mh[i].Ten, sizeof(mh[i].Ten), f);
		mh[i].Ten[strcspn(mh[i].Ten, "\n")] = '\0';
		fscanf(f, "%f\n", &mh[i].Gia);
		tongTien += mh[i].Gia;
		fscanf(f, "%d\n", &mh[i].SoLuong);
	}
	printf("Nhap file thanh cong!\n");
	printf("\n=> Tong tien = %.3f\n", tongTien);
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(mh[i].SoLuong < mh[j].SoLuong){
				MatHang temp = mh[i];
				mh[i] = mh[j];
				mh[j] = temp;
			} else if(mh[i].SoLuong == mh[j].SoLuong){
				if(mh[i].Gia < mh[j].Gia){
					MatHang temp = mh[i];
					mh[i] = mh[j];
					mh[j] = temp;
				}
			}
		}
	}
	FILE *out = fopen("hangsort.txt", "w"); //lan 1
	Xuat_hangsort(stdout, mh, n);
	Xuat_hangsort(out, mh, n);
	printf("\nIn file hangsort.txt thanh cong.\n");
	fclose(out);
	out = fopen("hangton.txt", "w"); //lan 2
	Xuat_hangton(stdout, mh, n);
	Xuat_hangton(out, mh, n);
	printf("\nIn file hangton.txt thanh cong.\n");
	fclose(out);
	fclose(f);
	return 0;
}
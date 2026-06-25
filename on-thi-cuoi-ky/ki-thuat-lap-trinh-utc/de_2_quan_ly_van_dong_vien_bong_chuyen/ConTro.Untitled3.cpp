#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	char HoTen[50];
	float ChieuCao;
	float CanNang;
} VanDongVien;

void xuatManHinh(FILE *f, VanDongVien *vdv, int n){
	printf("Danh sach van dong vien:\n");
	for(int i = 0; i < n; i++){
		printf("Ten: %s | Chieu cao: %.2fm | Can nang: %.2fkg\n", vdv[i].HoTen, vdv[i].ChieuCao, vdv[i].CanNang);
	}
}

void xuatVanBan(FILE *out, VanDongVien *vdv, int n){
	fprintf(out, "Nhung cau thu co can nang tren 60kg:\n");
	for(int i = 0; i < n; i++){
		if(vdv[i].CanNang > 60){
			fprintf(out, "Ten: %s | Chieu cao: %.2fm | Can nang: %.2fkg\n", vdv[i].HoTen, vdv[i].ChieuCao, vdv[i].CanNang);
		}
	}
}

int main(){
	FILE *f = fopen("Bongchuyen.txt", "r");
	if(f == NULL){
		printf("Loi file txt!\n");
		return 1;
	}
	int n;
	fscanf(f, "%d\n", &n);
	VanDongVien *vdv = (VanDongVien*)malloc(n * sizeof(VanDongVien));
	float tongChieuCao = 0;
	for(int i = 0; i < n; i++){
	    fgets(vdv[i].HoTen, sizeof(vdv[i].HoTen), f);
	    vdv[i].HoTen[strcspn(vdv[i].HoTen, "\n")] = '\0';
	    fscanf(f, "%f\n", &vdv[i].ChieuCao);
	    tongChieuCao += vdv[i].ChieuCao;
	    fscanf(f, "%f\n", &vdv[i].CanNang);
	}
	xuatManHinh(f, vdv, n);
	FILE *out = fopen("Bongchuyen.out", "w");
	xuatVanBan(out, vdv, n);
	printf("\nXuat Bongchuyen.out thanh cong!\n");
	float chieuCaoTB = (float)tongChieuCao/n;
	printf("\nChieu cao trung binh cua %d cau thu = %.4f", n, chieuCaoTB);
	fclose(out);
	fclose(f);
	free(vdv);
	return 0;
}
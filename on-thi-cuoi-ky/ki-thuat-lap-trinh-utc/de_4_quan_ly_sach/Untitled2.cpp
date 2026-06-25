#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	char MS[100];
	char TS[100];
	char TTG[100];
	int NXB, GIA;
} CuaHangSach;

void inGiaSachTangDan(FILE *out, int n, CuaHangSach *chs){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(chs[i].GIA > chs[j].GIA){
				CuaHangSach temp = chs[i];
				chs[i] = chs[j];
				chs[j] = temp;
			}
		}
	}
	fprintf(out, "Danh sach cua %d sach theo thu tu gia sach tang dan:\n", n);
	for(int i = 0; i < n; i++){
		fprintf(out, "Ma sach: %s | Ten sach: %s | Ten tac gia: %s | Nam xuat ban: %d | Gia: %d\n", chs[i].MS, chs[i].TS, chs[i].TTG, chs[i].NXB, chs[i].GIA);
	}
}

void timSach(int n, CuaHangSach *chs){
	char tenCanTim[100];
	double gaCanTim;
	printf("Nhap ten sach can tim: "); 
	fgets(tenCanTim, sizeof(tenCanTim), stdin);
	tenCanTim[strcspn(tenCanTim, "\n")] = '\0';
	printf("Nhap gia sach can tim: ");
	scanf("%lf", & gaCanTim);
	int timThay = 0;
	for(int i = 0; i < n; i++){
		if(strcmp(chs[i].TS, tenCanTim) == 0 && chs[i].GIA == gaCanTim){
			printf("Thong tin tim duoc: \n");
			timThay = 1;
			break;
		}
	}
	if(timThay == 0){
		printf("Khong tim thay sach!\n");
	}
}

int main(){
	FILE *f = fopen("input.txt","r");
	if(f == NULL){
		printf("Loi file txt!\n");
		return 1;
	}
	int n; fscanf(f, "%d\n", &n);
	CuaHangSach *chs = (CuaHangSach*)malloc(n * sizeof(CuaHangSach));
	for(int i = 0; i < n; i++){
		fgets(chs[i].MS, sizeof(chs[i].MS), f);
		chs[i].MS[strcspn(chs[i].MS, "\n")] = '\0';
		fgets(chs[i].TS, sizeof(chs[i].TS), f);
		chs[i].TS[strcspn(chs[i].TS, "\n")] = '\0';
		fgets(chs[i].TTG, sizeof(chs[i].TTG), f);
		chs[i].TTG[strcspn(chs[i].TTG, "\n")] = '\0';
		fscanf(f, "%d\n", &chs[i].NXB);
		fscanf(f, "%d\n", &chs[i].GIA);
	}
	FILE *out = fopen("output.txt", "w");
	inGiaSachTangDan(stdout, n, chs);
	inGiaSachTangDan(out, n, chs);
	printf("\n=> In danh sach thanh cong!\n\n");
	fclose(out);
	timSach(n, chs);
	fclose(f);
	free(chs);
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	char Hoten[100]; // Ho ten
	int NS; // Nam sinh
	int NKN; // Nam ket nap dang
} DoanVien;

void xuatManHinh(int n, DoanVien *dv){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(dv[i].NKN > dv[j].NKN){
				DoanVien temp = dv[i];
				dv[i] = dv[j];
				dv[j] = temp;
			}
		}
	}
	printf("Danh sach doan vien theo thu tu nam ket nap:\n");
	for(int i = 0; i < n; i++){
		printf("Ho ten: %s | Nam sinh: %d | Nam ket nap: %d\n", dv[i].Hoten, dv[i].NS, dv[i].NKN);
	}
	printf("\n");
}

void xuatOutput(FILE *out, int n, DoanVien *dv){
	fprintf(out, "Nhung doan vien co nam ket nap tu sau nam 2007 va tuoi doan tinh den nam 2015:\n");
	for(int i = 0; i < n; i++){
		if(dv[i].NKN > 2007){
			fprintf(out, "Ho ten: %s | Nam sinh: %d | Nam ket nap: %d | Tuoi doan: %d\n", dv[i].Hoten, dv[i].NS, dv[i].NKN, 2015 - dv[i].NKN);
		}
	}
}

int main(){
	FILE *f = fopen("input.txt", "r");
	int n; fscanf(f, "%d\n", &n);
	DoanVien *dv = (DoanVien*)malloc(n * sizeof(DoanVien));
	for(int i = 0; i < n; i++){
		fgets(dv[i].Hoten, sizeof(dv[i].Hoten), f);
		dv[i].Hoten[strcspn(dv[i].Hoten, "\n")] = '\0';
		fscanf(f, "%d\n", &dv[i].NS);
		fscanf(f, "%d\n", &dv[i].NKN);
	}
	xuatManHinh(n, dv);
	FILE *out = fopen("output.txt", "w");
	xuatOutput(out, n, dv);
	fclose(out);
	printf("\nXuat output.txt thanh cong!\n");
	fclose(f);
	free(dv);
	return 0;
}
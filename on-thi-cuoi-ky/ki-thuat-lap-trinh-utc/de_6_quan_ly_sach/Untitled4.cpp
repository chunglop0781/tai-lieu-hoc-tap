#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	char TenSach[100]; // Ten sach
	char NhaXB[100]; // Nha xuat ban
	int Gia; // Gia
} DauSach;

void DemNXB(int n, DauSach *ds){
	char timNXB[100];
	int demSachNXB = 0;
	printf("Vui long nhap nha xuat ban can tim: ");
	fgets(timNXB, sizeof(timNXB), stdin);
	timNXB[strcspn(timNXB, "\n")] = '\0';
	for(int i = 0; i < n; i++){
		if(strcmp(ds[i].NhaXB, timNXB) == 0){
			demSachNXB++;
		}
	}
	printf("Co %d cuon sach cua %s.", demSachNXB, timNXB);
}

void inDSTheoGiaGiamDan(FILE *out, int n, DauSach *ds){
	for(int i = 0 ; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(ds[i].Gia < ds[j].Gia){
				DauSach temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
	fprintf(out, "Danh sach cua %d dau sach theo thu tu giam dan cua gia:\n", n);
	for(int i = 0; i < n; i++){
		fprintf(out, "STT: %d | Ten sach: %s | Nha xuat ban: %s | Gia: %d\n", i+1, ds[i].TenSach, ds[i].NhaXB, ds[i].Gia);
	}
}

int main(){
	FILE *f = fopen("input.txt", "r");
	if(f == NULL){
		printf("Loi file txt!\n");
		return 1;
	}
	int n; fscanf(f, "%d\n", &n);
	DauSach *ds = (DauSach*)malloc(n * sizeof(DauSach));
	for(int i = 0; i <n ; i++){
		fgets(ds[i].TenSach, sizeof(ds[i].TenSach), f);
		ds[i].TenSach[strcspn(ds[i].TenSach, "\n")] = '\0';
		fgets(ds[i].NhaXB, sizeof(ds[i].NhaXB), f);
		ds[i].NhaXB[strcspn(ds[i].NhaXB, "\n")] = '\0';
		fscanf(f, "%d\n", &ds[i].Gia);
	}
	FILE *out = fopen("output.txt", "w");
	inDSTheoGiaGiamDan(out, n, ds);
	fclose(out);
	printf("Xuat output thanh cong!\n\n");
	DemNXB(n, ds);
	fclose(f);
	free(ds);
	return 0;
}
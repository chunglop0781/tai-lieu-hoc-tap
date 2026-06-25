#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	int BKS; //So bien kiem soat
	double TT; //Trong tai
	char CTy[100]; //Cong ty chu quan
} ThongTin;

void demCtyB(int n, ThongTin *tt){
	int dem = 0;
	for(int i = 0; i < n; i++){
		if(strcmp(tt[i].CTy, "B") == 0 && tt[i].BKS % 3 == 0){
			dem++;
		}
	}
	printf("Co %d xe o to cua cong ty B co BKS chia het cho 3.\n", dem);
}

void inRaBaOToCoTrongTaiNhoNhat(FILE *out, int n, ThongTin *tt){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(tt[i].TT < tt[j].TT){
				ThongTin temp = tt[i];
				tt[i] = tt[j];
				tt[j] = temp;
			}
		}
	}
	fprintf(out, "3 o to co trong tai nho nhat:\n");
	for(int i = 0; i < 3; i++){
		fprintf(out, "Bien kiem soat: %d | Trong tai: %.2lf | Cong ty: %s\n", tt[i].BKS, tt[i].TT, tt[i].CTy);
	}
}

int main(){
	FILE *f = fopen("input.txt", "r");
	if(f == NULL){
		printf("Loi file txt!\n");
		return 1;
	}
	int n; fscanf(f, "%d\n", &n);
	ThongTin *tt = (ThongTin*)malloc(n * sizeof(ThongTin));
	for(int i = 0; i < n; i++){
		fscanf(f, "%d\n", &tt[i].BKS);
		fscanf(f, "%lf\n", &tt[i].TT);
		fgets(tt[i].CTy, sizeof(tt[i].CTy), f);
		tt[i].CTy[strcspn(tt[i].CTy, "\n")] ='\0';
	}
	demCtyB(n, tt);
	FILE *out = fopen("output.txt", "w");
	inRaBaOToCoTrongTaiNhoNhat(out, n, tt);
	printf("Xuat output.txt thanh cong!\n");
	fclose(f);
	free(tt);
	return 0;
}
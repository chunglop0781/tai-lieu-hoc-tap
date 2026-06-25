#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	char ten[100];
	int banthang;
} DoiNha;

typedef struct{
	char ten[100];
	int banthang;
} DoiKhach;

int main(){
	FILE *f = fopen("input.txt", "r");
	if(f == NULL){
		printf("Loi file txt!\n");
		return 1;
	}
	int n; fscanf(f, "%d\n", &n);
	DoiNha *nha = (DoiNha*)malloc(n * sizeof(DoiNha));
	DoiKhach *khach = (DoiKhach*)malloc(n * sizeof(DoiKhach));
	for(int i = 0; i < n; i ++){
		fgets(nha[i].ten, sizeof(nha[i].ten), f);
		nha[i].ten[strcspn(nha[i].ten, "\n")] = '\0';
		fgets(khach[i].ten, sizeof(khach[i].ten), f);
		khach[i].ten[strcspn(khach[i].ten, "\n")] = '\0';
		fscanf(f, "%d\n", &nha[i].banthang);
		fscanf(f, "%d\n", &khach[i].banthang);
	}
	printf("\nDanh sach tran dau:\n");
	for(int i = 0; i < n; i ++){
		printf("%s vs %s voi ti so %d - %d\n", nha[i].ten, khach[i].ten, nha[i].banthang, khach[i].banthang);
	}
	
	fclose(f);
	free(nha);
	free(khach);
}
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

void InInput(DoiNha *nha, DoiKhach *khach, int n){
	printf("\nDanh sach tran dau:\n");
	for(int i = 0; i < n; i ++){
		printf("%s vs %s voi ti so %d - %d\n", nha[i].ten, khach[i].ten, nha[i].banthang, khach[i].banthang);
	}
}

typedef struct{
	int diem;
	int banthang;
	int banthua;
} HieuSoDoi;

void xuatOutput(DoiNha *nha, DoiKhach *khach, int n){
	HieuSoDoi *hsd = (HieuSoDoi*)calloc(4, sizeof(HieuSoDoi));
	for(int i = 0; i < n; i ++){
		if(nha[i].banthang > khach[i].banthang){
			if(strcmp(nha[i].ten, "A") == 0){
				hsd[0].diem += 3;
				hsd[0].banthang += nha[i].banthang;
			}
			else if(strcmp(nha[i].ten, "B") == 0){
				hsd[1].diem += 3;
				hsd[1].banthang += nha[i].banthang;
			}
			else if(strcmp(nha[i].ten, "C") == 0){
				hsd[2].diem += 3;
				hsd[2].banthang += nha[i].banthang;
			}
			else if(strcmp(nha[i].ten, "D") == 0){
				hsd[3].diem += 3;
				hsd[3].banthang += nha[i].banthang;
			}
			if(strcmp(khach[i].ten, "A") == 0){
				hsd[0].banthua += khach[i].banthang;
			}
			else if(strcmp(khach[i].ten, "B") == 0){
				hsd[1].banthua += khach[i].banthang;
			}
			else if(strcmp(khach[i].ten, "C") == 0){
				hsd[2].banthua += khach[i].banthang;
			}
			else if(strcmp(khach[i].ten, "D") == 0){
				hsd[3].banthua += khach[i].banthang;
			}
		} else if(nha[i].banthang == khach[i].banthang) {
			if(strcmp(nha[i].ten, "A") == 0){
				hsd[0].diem += 1;
				hsd[0].banthang += nha[i].banthang;
			}
    		if(strcmp(khach[i].ten, "A") == 0){
        		hsd[0].diem += 1;
        		hsd[0].banthang += khach[i].banthang;
    		}
    		if(strcmp(nha[i].ten, "B") == 0){
        		hsd[1].diem += 1;
        		hsd[1].banthang += nha[i].banthang;
    		}
    		if(strcmp(khach[i].ten, "B") == 0){
    		    hsd[1].diem += 1;
    		    hsd[1].banthang += khach[i].banthang;
    		}
    		if(strcmp(nha[i].ten, "C") == 0){
    		    hsd[2].diem += 1;
    		    hsd[2].banthang += nha[i].banthang;
    		}
    		if(strcmp(khach[i].ten, "C") == 0){
    		    hsd[2].diem += 1;
    		    hsd[2].banthang += khach[i].banthang;
    		}
    		if(strcmp(nha[i].ten, "D") == 0){
    		    hsd[3].diem += 1;
    		    hsd[3].banthang += nha[i].banthang;
    		}
    		if(strcmp(khach[i].ten, "D") == 0){
    		    hsd[3].diem += 1;
    		    hsd[3].banthang += khach[i].banthang;
    		}
		} else if(nha[i].banthang < khach[i].banthang) {
			if(strcmp(khach[i].ten, "A") == 0){
				hsd[0].diem += 3;
				hsd[0].banthang += khach[i].banthang;
			}
			else if(strcmp(khach[i].ten, "B") == 0){
				hsd[1].diem += 3;
				hsd[1].banthang += khach[i].banthang;
			}
			else if(strcmp(khach[i].ten, "C") == 0){
				hsd[2].diem += 3;
				hsd[2].banthang += khach[i].banthang;
			}
			else if(strcmp(khach[i].ten, "D") == 0){
				hsd[3].diem += 3;
				hsd[3].banthang += khach[i].banthang;
			}
			if(strcmp(nha[i].ten, "A") == 0){
				hsd[0].banthua += nha[i].banthang;
			}
			else if(strcmp(nha[i].ten, "B") == 0){
				hsd[1].banthua += nha[i].banthang;
			}
			else if(strcmp(nha[i].ten, "C") == 0){
				hsd[2].banthua += nha[i].banthang;
			}
			else if(strcmp(nha[i].ten, "D") == 0){
				hsd[3].banthua += nha[i].banthang;
			}
		}
	}
	FILE *out = fopen("output.txt", "w");
	fprintf(out, "Diem so, so ban thang, so ban thua cua tung doi:\n");
	fprintf(out, "Doi A | %d diem | %d ban thang | %d ban thua\n", hsd[0].diem, hsd[0].banthang, hsd[0].banthua);
	fprintf(out, "Doi B | %d diem | %d ban thang | %d ban thua\n", hsd[1].diem, hsd[1].banthang, hsd[1].banthua);
	fprintf(out, "Doi C | %d diem | %d ban thang | %d ban thua\n", hsd[2].diem, hsd[2].banthang, hsd[2].banthua);
	fprintf(out, "Doi D | %d diem | %d ban thang | %d ban thua\n", hsd[3].diem, hsd[3].banthang, hsd[3].banthua);
	fclose(out);
	printf("\nXuat file output.txt thanh cong!\n");
	free(hsd);
}

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
	InInput(nha, khach, n);
	xuatOutput(nha, khach, n);
	fclose(f);
	free(nha);
	free(khach);
}
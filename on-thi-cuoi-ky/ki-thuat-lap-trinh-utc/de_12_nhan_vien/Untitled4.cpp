#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct{
	char Hoten[50];
	double Luong;
	int MaCV;
}NhanVien;



void nhapDanhSach(int n, NhanVien *nv){
	for(int i = 0; i < n; i++){
		printf("Nhap ho ten: ");
		fflush(stdin); // don sach bo nho dem
		gets(nv[i].Hoten);
		printf("Nhap luong: ");
		scanf("%lf",&nv[i].Luong);
		printf("Nhap ma CV: ");
		scanf("%d",&nv[i].MaCV);

	}
}



void xuatFile(FILE *out,int n,NhanVien *nv){
	fprintf(out,"%d\n",n);
	for(int i = 0; i < n; i++){
		fprintf(out,"%s\n",nv[i].Hoten);
		fprintf(out,"%.2lf\n",nv[i].Luong);
		fprintf(out,"%d\n",nv[i].MaCV);

	}

}



void xuatManHinh(int n,NhanVien *nv){
	printf("\nDanh sach nhan vien:\n");
	for(int i = 0; i < n; i++){
		printf("Ho ten: %s | Luong: %.2lf | Ma CV: %d\n", nv[i].Hoten, nv[i].Luong, nv[i].MaCV);

	}

}



void sapXepLuong(int n,NhanVien *nv){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(nv[i].Luong < nv[j].Luong){
				NhanVien temp = nv[i];
				nv[i] = nv[j];
				nv[j] = temp;
			}
		}
	}
}



int main(){
	int n;
	printf("Nhap so nhan vien: ");
	scanf("%d",&n);
	NhanVien *nv = (NhanVien*)malloc(n*sizeof(NhanVien));
	nhapDanhSach(n,nv);
	FILE *out = fopen("nhanvien.txt","w");
	if(out == NULL){
		printf("Loi file!");
		return 1;
	}
	xuatFile(out,n,nv);
	sapXepLuong(n,nv);
	xuatManHinh(n,nv);
	fclose(out);
	free(nv);
	return 0;
}
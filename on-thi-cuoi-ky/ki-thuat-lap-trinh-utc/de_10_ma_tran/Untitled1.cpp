#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


// Doc ma tran tu file
void docMaTran(FILE *f,int n,int **a){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(f,"%d",&a[i][j]);
		}
	}
}


// Xuat ma tran
void xuatMaTran(int n,int **a){
	printf("Ma tran A:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}


// Tinh trung binh cac so nam duoi duong cheo phu
void tinhTrungBinhCheoPhu(int n,int **a){
	int tong=0;
	int dem=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i+j>n-1){
				tong+=a[i][j];
				dem++;
			}
		}
	}
	printf("Trung binh cac so duoi cheo phu: %.2lf\n",(double)tong/dem);
}

// Tinh trung binh cac so nam tren duong cheo chinh
void tinhTrungBinhCheoChinh(int n, int **a) {
    int tong = 0;
    int dem = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {   // Tren duong cheo chinh
                tong += a[i][j];
                dem++;
            }
        }
    }
    if (dem > 0)
        printf("Trung binh cac so tren cheo chinh: %.2lf\n", (double)tong / dem);
    else
        printf("Khong co phan tu tren duong cheo chinh.\n");
}


// Kiem tra ma tran tam giac tren
void kiemTraTamGiacTren(int n,int **a){
	int kt=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i][j]!=0){
				kt=0;
			}
		}
	}
	if(kt==1){
		printf("A la ma tran tam giac tren\n");
	}
	else{
		printf("A khong phai ma tran tam giac tren\n");
	}
}

// Kiem tra ma tran tam giac duoi
void kiemTraTamGiacDuoi(int n, int **a) {
    int kt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != 0) {
                kt = 0;
                break;
            }
        }
        if (kt == 0)
            break;
    }
    if (kt)
        printf("A la ma tran tam giac duoi\n");
    else
        printf("A khong phai ma tran tam giac duoi\n");
}


// Kiem tra ma tran thua
void kiemTraMaTranThua(int n,int **a){
	int dem0=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==0){
				dem0++;
			}
		}
	}
	if(dem0>=n*n*0.6){
		printf("A la ma tran thua\n");
	}
	else{
		printf("A khong phai ma tran thua\n");
	}
}



int main(){
	FILE *f=fopen("input.txt","r");
	if(f==NULL){
		printf("Loi mo file");
		return 1;
	}
	int n;
	fscanf(f,"%d",&n);
	int **a=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++){
		a[i]=(int*)malloc(n*sizeof(int));
	}
	docMaTran(f,n,a);
	fclose(f);
	xuatMaTran(n,a);
	tinhTrungBinhCheoPhu(n,a);
	tinhTrungBinhCheoChinh(n,a);
	kiemTraTamGiacTren(n,a);
	kiemTraTamGiacDuoi(n,a);
	kiemTraMaTranThua(n,a);
	for(int i=0;i<n;i++){
		free(a[i]);
	}
	free(a);
	return 0;
}
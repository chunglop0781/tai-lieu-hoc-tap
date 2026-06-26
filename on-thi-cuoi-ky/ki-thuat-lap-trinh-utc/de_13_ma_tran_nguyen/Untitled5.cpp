#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


void docFile(FILE *f,int *m,int *n,int ***a){
	fscanf(f,"%d %d\n",m,n);
	*a=(int**)malloc((*m)*sizeof(int*));
	for(int i=0;i<*m;i++){
		(*a)[i]=(int*)malloc((*n)*sizeof(int));
	}
	for(int i=0;i<*m;i++){
		for(int j=0;j<*n;j++){
			fscanf(f,"%d",&(*a)[i][j]);
		}
	}
}



void inMaTran(int m,int n,int **a){
	printf("Ma tran A:\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}



void inFile(FILE *out,int m,int n,int **a){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			fprintf(out,"%d\t",a[i][j]);
		}
		fprintf(out,"\n");
	}
}



void tinhTrungBinh(int m,int n,int **a){
	int tong=0;
	int dem=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]%2==0 && a[i][j]%3==1){
				tong+=a[i][j];
				dem++;
			}
		}
	}
	if(dem>0){
		printf("Trung binh cong = %.2lf\n",(double)tong/dem);
	}
	else{
		printf("Khong co phan tu thoa man\n");
	}
}



void tongTungHang(int m,int n,int **a){
	for(int i=0;i<m;i++){
		int tong=0;
		for(int j=0;j<n;j++){
			tong+=a[i][j];
		}
		printf("Tong hang %d = %d\n",i+1,tong);
	}
}



int main(){
	FILE *f=fopen("input.txt","r");
	if(f==NULL){
		printf("Loi file!");
		return 1;
	}
	int m,n;
	int **a;
	docFile(f,&m,&n,&a);
	inMaTran(m,n,a);
	tinhTrungBinh(m,n,a);
	tongTungHang(m,n,a);
	FILE *out=fopen("matran.txt","w");
	inFile(out,m,n,a);
	fclose(f);
	fclose(out);
	for(int i=0;i<m;i++){
		free(a[i]);
	}
	free(a);
	return 0;
}
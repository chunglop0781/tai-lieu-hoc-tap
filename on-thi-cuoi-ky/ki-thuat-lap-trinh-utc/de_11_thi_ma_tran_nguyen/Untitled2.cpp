#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>



void docMaTran(FILE *f,int n,int **a){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(f,"%d",&a[i][j]);
		}
	}
}



// Xuat ma tran ra man hinh va file
void xuatMaTran(FILE *out,int n,int **a){
	printf("Ma tran:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
			fprintf(out,"%d ",a[i][j]);
		}
		printf("\n");
		fprintf(out,"\n");
	}
}



// Tinh trung binh phan tu duoi cheo chinh chia het cho 3 hoac 4
void tinhTrungBinh(int n,int **a,FILE *out){
	int tong=0;
	int dem=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i>j){
				if(a[i][j]%3==0||a[i][j]%4==0){
					tong+=a[i][j];
					dem++;
				}
			}
		}
	}



	if(dem>0){
		printf("Trung binh:%.2lf\n",(double)tong/dem);
		fprintf(out,"Trung binh:%.2lf\n",(double)tong/dem);
	}

	else{
		printf("Khong co phan tu thoa man\n");
		fprintf(out,"Khong co phan tu thoa man\n");
	}
}



// Tinh tong tung cot
void tinhTongCot(int n,int **a,FILE *out){
	for(int i=0;i<n;i++){
		int tong=0;
		for(int j=0;j<n;j++){
			tong+=a[j][i];
		}
		printf("Tong cot %d:%d\n",i+1,tong);
		fprintf(out,"Tong cot %d:%d\n",i+1,tong);
	}
}




int main(){
	FILE *f=fopen("input.txt","r");
	if(f==NULL){
		printf("Loi mo file");
		return 1;
	}
	FILE *out=fopen("output.txt","w");
	int n;
	fscanf(f,"%d",&n);
	int **a=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++){
		a[i]=(int*)malloc(n*sizeof(int));
	}
	docMaTran(f,n,a);
	fclose(f);
	xuatMaTran(out,n,a);
	tinhTrungBinh(n,a,out);
	tinhTongCot(n,a,out);
	fclose(out);
	for(int i=0;i<n;i++){
		free(a[i]);
	}
	free(a);
	return 0;
}
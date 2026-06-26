#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct{
	double x;
	double y;
}Diem;



// Doc diem tu file
void docDiem(FILE *f,int n,Diem *d){
	for(int i=0;i<n;i++){
		fscanf(f,"%lf %lf",&d[i].x,&d[i].y);
	}
}



// Xuat diem
void xuatDiem(int n,Diem *d){
	printf("Danh sach diem:\n");
	for(int i=0;i<n;i++){
		printf("Diem %d:(%.2lf,%.2lf)\n",i+1,d[i].x,d[i].y);
	}
}



// Tinh khoang cach toi goc toa do
double khoangCach(Diem d){
	return sqrt(d.x*d.x+d.y*d.y);
}



// Tim diem xa goc toa do nhat
void timDiemXaNhat(int n,Diem *d){
	int vt=0;
	for(int i=0;i<n;i++){
		if(khoangCach(d[i])>khoangCach(d[vt])){
			vt=i;
		}
	}
	printf("\nDiem xa goc toa do nhat:");
	printf("(%.2lf,%.2lf)\n",d[vt].x,d[vt].y);
}



// Dem diem nam o goc phan tu thu 2
void demGocPhanTu2(int n,Diem *d){
	int dem=0;
	for(int i=0;i<n;i++){
		if(d[i].x<0&&d[i].y>0){
			dem++;
		}
	}
	printf("So diem nam o goc phan tu 2:%d\n",dem);
}



int main(){
	FILE *f=fopen("input.txt","r");
	if(f==NULL){
		printf("Loi mo file");
		return 1;
	}
	int n;
	fscanf(f,"%d",&n);
	Diem *d=(Diem*)malloc(n*sizeof(Diem));
	docDiem(f,n,d);
	fclose(f);
	xuatDiem(n,d);
	timDiemXaNhat(n,d);
	demGocPhanTu2(n,d);
	free(d);
	return 0;
}
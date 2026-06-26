#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	double x;
	double y;
}Diem;


// Doc danh sach diem tu file
void docDiem(FILE *f,int n,Diem *d){
	for(int i=0;i<n;i++){
		fscanf(f,"%lf %lf",&d[i].x,&d[i].y);
	}
}


// Xuat danh sach diem
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
	printf("\nDiem xa goc toa do nhat:\n");
	printf("(%.2lf,%.2lf)\n",d[vt].x,d[vt].y);
}


// Tinh do dai duong gap khuc
void tinhDuongGapKhuc(int n,Diem *d){
	double tong=0;
	for(int i=0;i<n-1;i++){
		tong+=sqrt(pow(d[i+1].x-d[i].x,2)+pow(d[i+1].y-d[i].y,2));
	}
	tong+=sqrt(pow(d[0].x-d[n-1].x,2)+pow(d[0].y-d[n-1].y,2));
	printf("\nDo dai duong gap khuc=%.2lf\n",tong);
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
	tinhDuongGapKhuc(n,d);
	free(d);
	return 0;
}
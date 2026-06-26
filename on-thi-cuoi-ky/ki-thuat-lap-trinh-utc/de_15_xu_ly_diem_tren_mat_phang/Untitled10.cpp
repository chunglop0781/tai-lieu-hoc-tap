#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct{
	double x;
	double y;
}Diem;



void nhapDiem(int n,Diem *d){
	for(int i=0;i<n;i++){
		printf("Nhap diem %d:\n",i+1);
		printf("x = ");
		scanf("%lf",&d[i].x);
		printf("y = ");
		scanf("%lf",&d[i].y);
	}
}



void xuatDiem(int n,Diem *d){
	printf("\nDanh sach diem:\n");
	for(int i=0;i<n;i++){
		printf("(%.2lf, %.2lf)\n", d[i].x, d[i].y);
	}
}



double khoangCach(Diem d){
	return sqrt(d.x*d.x+d.y*d.y);
}



void demDiemTrongHinhTron(int n,Diem *d){
	int dem=0;
	for(int i=0;i<n;i++){
		if(khoangCach(d[i])<=4){
			dem++;
		}
	}
	printf("So diem nam trong hinh tron ban kinh 4: %d\n",dem);
}



void timHinhChuNhat(int n,Diem *d){
	double xmin=d[0].x;
	double xmax=d[0].x;
	double ymin=d[0].y;
	double ymax=d[0].y;
	for(int i=1;i<n;i++){
		if(d[i].x<xmin){
			xmin=d[i].x;
		}
		if(d[i].x>xmax){
			xmax=d[i].x;
		}
		if(d[i].y<ymin){
			ymin=d[i].y;
		}
		if(d[i].y>ymax){
			ymax=d[i].y;
		}
	}
	printf("\nHinh chu nhat nho nhat:\n");
	printf("Dinh 1: (%.2lf, %.2lf)\n",xmin,ymin);
	printf("Dinh 2: (%.2lf, %.2lf)\n",xmin,ymax);
	printf("Dinh 3: (%.2lf, %.2lf)\n",xmax,ymax);
	printf("Dinh 4: (%.2lf, %.2lf)\n",xmax,ymin);
}



int main(){
	int n;
	printf("Nhap so diem: ");
	scanf("%d",&n);
	Diem *d=(Diem*)malloc(n*sizeof(Diem));
	nhapDiem(n,d);
	xuatDiem(n,d);
	demDiemTrongHinhTron(n,d);
	timHinhChuNhat(n,d);
	free(d);
	return 0;
}
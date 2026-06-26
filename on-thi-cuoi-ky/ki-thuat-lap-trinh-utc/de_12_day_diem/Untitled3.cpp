#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	double x;
	double y;
}Diem;


void docFile(FILE *f, int *n, Diem **d){
	fscanf(f,"%d",n);
	*d = (Diem*)malloc((*n)*sizeof(Diem));
	for(int i = 0; i < *n; i++){
		fscanf(f,"%lf%lf",&(*d)[i].x,&(*d)[i].y);
	}
}


void xuatDiem(int n, Diem *d){
	printf("Danh sach diem:\n");
	for(int i = 0; i < n; i++){
		printf("Diem %d: (%.2lf, %.2lf)\n",i+1,d[i].x,d[i].y);
	}
}


double khoangCach(Diem a, Diem b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}


void diemXaNhat(int n, Diem *d){
	Diem goc;
	goc.x = 0;
	goc.y = 0;
	double max = khoangCach(goc,d[0]);
	int vt = 0;
	for(int i = 1; i < n; i++){
		double kc = khoangCach(goc,d[i]);
		if(kc > max){
			max = kc;
			vt = i;
		}
	}
	printf("\nDiem xa goc nhat: (%.2lf, %.2lf)\n",d[vt].x,d[vt].y);
}


void demDoanGocPhanTu3(int n, Diem *d){
	int dem = 0;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(d[i].x < 0 && d[i].y < 0 && d[j].x < 0 && d[j].y < 0){
				dem++;
			}
		}
	}
	printf("So doan nam trong goc phan tu 3: %d\n",dem);
}



int main(){
	FILE *f = fopen("input.txt","r");
	if(f == NULL){
		printf("Loi file!");
		return 1;
	}
	int n;
	Diem *d;
	docFile(f,&n,&d);
	xuatDiem(n,d);
	diemXaNhat(n,d);
	demDoanGocPhanTu3(n,d);
	fclose(f);
	free(d);
	return 0;
}
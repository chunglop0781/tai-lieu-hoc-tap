#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct{
	char HoTen[50];
	int NamSinh;
	int NamKetNap;
}DangVien;



void docFile(FILE *f,int *n,DangVien **dv){
	fscanf(f,"%d\n",n);
	*dv=(DangVien*)malloc((*n)*sizeof(DangVien));
	for(int i=0;i<*n;i++){
		fgets((*dv)[i].HoTen,sizeof((*dv)[i].HoTen),f);
		(*dv)[i].HoTen[strcspn((*dv)[i].HoTen,"\n")]='\0';
		fscanf(f,"%d",&(*dv)[i].NamSinh);
		fscanf(f,"%d",&(*dv)[i].NamKetNap);
		fgetc(f);
	}
}



void xuatDanhSach(int n,DangVien *dv){
	printf("Danh sach dang vien:\n");
	for(int i=0;i<n;i++){
		printf("Ho ten: %s | Nam sinh: %d | Nam ket nap: %d\n", dv[i].HoTen, dv[i].NamSinh, dv[i].NamKetNap);
	}
}



void sapXep(int n,DangVien *dv){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(dv[i].NamKetNap>dv[j].NamKetNap){
				DangVien temp=dv[i];
				dv[i]=dv[j];
				dv[j]=temp;
			}
		}
	}
}



void thongKe(int n,DangVien *dv){
	int namHienTai=2026;
	printf("\nDang vien tren 20 nam tuoi dang:\n");
	for(int i=0;i<n;i++){
		if(namHienTai-dv[i].NamKetNap>=20){
			printf("%s - %d nam\n", dv[i].HoTen, namHienTai-dv[i].NamKetNap);
		}
	}
}



int main(){
	FILE *f=fopen("input.txt","r");
	if(f==NULL){
		printf("Loi file!");
		return 1;
	}
	int n;
	DangVien *dv;
	docFile(f,&n,&dv);
	sapXep(n,dv);
	xuatDanhSach(n,dv);
	thongKe(n,dv);
	fclose(f);
	free(dv);
	return 0;
}
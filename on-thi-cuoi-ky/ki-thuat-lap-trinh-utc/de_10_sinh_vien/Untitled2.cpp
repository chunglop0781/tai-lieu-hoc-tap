#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct{
	char HoTen[50];
	char QueQuan[50];
	char HocLuc;
}SinhVien;



// Doc danh sach sinh vien
void docSinhVien(FILE *f,int n,SinhVien *sv){
	for(int i=0;i<n;i++){
		fgets(sv[i].HoTen,sizeof(sv[i].HoTen),f);
		sv[i].HoTen[strcspn(sv[i].HoTen,"\n")]='\0';
		fgets(sv[i].QueQuan,sizeof(sv[i].QueQuan),f);
		sv[i].QueQuan[strcspn(sv[i].QueQuan,"\n")]='\0';
		fscanf(f,"%c",&sv[i].HocLuc);
		fgetc(f);
	}
}



// Xuat danh sach sinh vien
void xuatSinhVien(int n,SinhVien *sv){
	printf("Danh sach sinh vien:\n");
	for(int i=0;i<n;i++){
		printf("Ho ten:%s | Que:%s | Hoc luc:%c\n", sv[i].HoTen, sv[i].QueQuan, sv[i].HocLuc);
	}
}



// Tim sinh vien theo ten
void timSinhVien(int n,SinhVien *sv,char ten[]){
	int kt=0;
	for(int i=0;i<n;i++){
		if(strcmp(sv[i].HoTen,ten)==0){
			printf("Tim thay:\n");
			printf("%s | %s | %c\n", sv[i].HoTen, sv[i].QueQuan, sv[i].HocLuc);
			kt=1;
		}
	}
	if(kt==0){
		printf("Khong tim thay sinh vien\n");
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
	fgetc(f);
	SinhVien *sv=(SinhVien*)malloc(n*sizeof(SinhVien));
	docSinhVien(f,n,sv);
	fclose(f);
	xuatSinhVien(n,sv);
	char ten[50];
	printf("\nNhap ten sinh vien can tim:");
	fgets(ten,sizeof(ten),stdin);
	ten[strcspn(ten,"\n")]='\0';
	timSinhVien(n,sv,ten);
	free(sv);
	return 0;
}
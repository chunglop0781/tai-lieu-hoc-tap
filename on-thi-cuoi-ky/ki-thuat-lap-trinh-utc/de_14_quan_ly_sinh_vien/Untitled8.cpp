#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct{
	char MaSV[20];
	char HoTen[50];
	char Khoa[20];
	double DiemTB;
}SinhVien;



void nhapSinhVien(int n,SinhVien *sv){
	for(int i=0;i<n;i++){
		printf("\nNhap sinh vien %d\n",i+1);
		printf("Ma SV: ");
		fflush(stdin);
		gets(sv[i].MaSV);
		printf("Ho ten: ");
		gets(sv[i].HoTen);
		printf("Khoa: ");
		gets(sv[i].Khoa);
		printf("Diem TB: ");
		scanf("%lf",&sv[i].DiemTB);
	}
}



void xuatSinhVien(int n,SinhVien *sv){
	printf("\nDanh sach sinh vien:\n");
	for(int i=0;i<n;i++){
		printf("Ma: %s | Ho ten: %s | Khoa: %s | Diem TB: %.2lf\n", sv[i].MaSV, sv[i].HoTen, sv[i].Khoa, sv[i].DiemTB);
	}
}



void thongKeKhoa(int n,SinhVien *sv){
	int demA=0;
	int demB=0;
	int demC=0;
	for(int i=0;i<n;i++){
		if(strcmp(sv[i].Khoa,"A")==0){
			demA++;
		}
		if(strcmp(sv[i].Khoa,"B")==0){
			demB++;
		}
		if(strcmp(sv[i].Khoa,"C")==0){
			demC++;
		}
	}
	printf("\nSo sinh vien khoa A: %d\n",demA);
	printf("So sinh vien khoa B: %d\n",demB);
	printf("So sinh vien khoa C: %d\n",demC);
	if(demA>=demB && demA>=demC){
		printf("Khoa dong sinh vien nhat: A\n");
	}
	else if(demB>=demA && demB>=demC){
		printf("Khoa dong sinh vien nhat: B\n");
	}
	else{
		printf("Khoa dong sinh vien nhat: C\n");
	}
}



void sapXepDiem(int n,SinhVien *sv){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(sv[i].DiemTB<sv[j].DiemTB){
				SinhVien temp=sv[i];
				sv[i]=sv[j];
				sv[j]=temp;
			}
		}
	}
}



int main(){
	int n;
	printf("Nhap so sinh vien: ");
	scanf("%d",&n);
	SinhVien *sv=(SinhVien*)malloc(n*sizeof(SinhVien));
	nhapSinhVien(n,sv);
	xuatSinhVien(n,sv);
	thongKeKhoa(n,sv);
	sapXepDiem(n,sv);
	printf("\nDanh sach sau khi sap xep diem giam dan:\n");
	xuatSinhVien(n,sv);
	free(sv);
	return 0;
}
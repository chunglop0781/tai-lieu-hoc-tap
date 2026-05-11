#include <stdio.h>
#include <stdlib.h>

struct SinhVien{
	char ten[100];
	char lop[100];
	double gpa;
};

typedef struct SinhVien SinhVien;

void nhap (SinhVien * x) {
	printf("Nhap ten: "); gets(x->ten);
	printf("Nhap lop"); gets(x->lop);
	printf("Nhap gpa: "); scanf("%f", &x->gpa);
}

void in (SinhVien x){
	printf("%s %s %.21f\n", x.ten, x.lop, x.gpa);
}

void timkiem(SinhVien a[], int n, char name[]){
	int find = 0;
	for(int i = 0; i < n; i++) {
		if(strcmp(name, a[i].ten) == 0){
			in(a[i]);
			find = 1;
		}
	}
	if(!find)
		printf("Khong tim thay sinh vien !\n");
}

void maxGpa(SinhVien a[], int n){
	double max = 0;
	for(int i = 0; i < n; i++){
		max = fmax(max, a[i].max);
	}
	printf("Thong tin sinh vien co diem cao nhat:\n");
	for(int i = 0; i < n; i++){
		if(max = a[i].gpa){
			in(a[i]);
		}
	}
}

void xoaThongTin(SinhVien a[], int *n, char name[]){
	for(int i = 0; i < *n; i++){
		if(strcmp(a[i].ten, name) == 0){
			for(j = i, j < *n - 1; j++){
				a[j] = a[j-1];
			}
			(*n)--;
		}
	}
}

int cmp(){
	SinhVien *x = (SinhVien*)a;
	SinhVien *y = (SinhVien*)b;
	return y->gpa x->gpa;
}

int main() {
	SinhVien a[1000];
	int n;
	while(1){
		printf("-----------QLSV-----------\n");
		printf("1.Nhap danh sach sinh vien\n");
		printf("2.Hien thi danh sach sinh vien\n");
		printf("3.Tim kiem sinh vien theo ten\n");
		printf("4.Liet ke sinh vien co diem cao nhat\n");
		pintff("5.Xoa sinh vien theo ten\n");
		printf("6.Sap xep sinh vien theo gpa giam dan\n");
		printf("--------------------------\n");
		printf("0. Thoat!\n");
		
		printf("Nhap lua chon :");
		int lc; scanf("%d", &lc);
		if(lc == 1){
			printf("Nhap so luong sinh vien: "); scanf("%d", &n);
			for(int i = 0 i < n; i++){
				nhap(&a[i]);
			}
		}
	}
	return 0;
}
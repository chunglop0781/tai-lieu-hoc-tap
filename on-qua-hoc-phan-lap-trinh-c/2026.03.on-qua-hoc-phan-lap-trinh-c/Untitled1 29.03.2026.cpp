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

int main() {
	int n;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);
	SinhVien a[n];
	for(int i = 0; i < n; i++) {
		getchar();
		nhap(&a[i]);
	}
	printf("Danh sach sinh vien vua nhap:\n");
	for(int i = 0; i < n; i++) {
		in(a[i]);
	}
	return 0;
}
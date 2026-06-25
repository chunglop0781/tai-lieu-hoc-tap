#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	int tu, mau;
	double tuchiamau;
} PhanSo;

int UCLN(int a, int b){
	a = abs(a);
	b = abs(b);
	while(b != 0){
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void inDS(FILE *out, PhanSo *ps, int n){
	for(int i = 0; i < n; i++){
    	int ucln_tam = UCLN(ps[i].tu, ps[i].mau);
    	ps[i].tu = ps[i].tu / ucln_tam;
    	ps[i].mau = ps[i].mau / ucln_tam;
    	if(ps[i].tuchiamau < 0){
    	    fprintf(out, "Phan so %d = -%d/%d = %lf\n", i+1, abs(ps[i].tu), abs(ps[i].mau), ps[i].tuchiamau);
    	} else {
    		fprintf(out, "Phan so %d = %d/%d = %lf\n", i+1, abs(ps[i].tu), abs(ps[i].mau), ps[i].tuchiamau);
		}
	}
}

int main(){
	FILE *f = fopen("ps.txt", "r");
	if(f == NULL){
		printf("Loi file!\n");
		return 1;
	}
	int n;
	fscanf(f, "%d\n", &n);
	PhanSo *ps = (PhanSo*)malloc(n * sizeof(PhanSo));
	int tongTu = 0, tongMau = 1;
	for(int i = 0; i < n; i++){
		fscanf(f, "%d %d\n", &ps[i].tu, &ps[i].mau);
		ps[i].tuchiamau = (double)ps[i].tu / ps[i].mau;
		// (a/b)+(c/d)=(a*d+c*b)/(b*d)
		tongTu += tongTu * ps[i].mau + tongMau * ps[i].tu;
		tongMau += ps[i].mau * tongMau;
	}
	printf("Doc file ps.txt thanh cong.\n\n");
	inDS(stdout, ps, n);
	FILE *out = fopen("psrutgon.txt", "w");
	inDS(out, ps, n);
	printf("In file psrutgon.txt thanh cong.\n");
	fclose(out);
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(ps[i].tuchiamau < ps[j].tuchiamau){
				PhanSo temp = ps[i];
				ps[i] = ps[j];
				ps[j] = temp;
			}
		}
	}
	printf("=> Phan so lon nhat la phan so %d/%d = %lf\n", ps[0].tu, ps[0].mau, ps[0].tuchiamau);
	int uclnTong_tam = UCLN(tongTu, tongMau);
	tongTu = tongTu / uclnTong_tam;
	tongMau = tongMau / uclnTong_tam;
	double psTong = (double)tongTu / tongMau;
    if(psTong < 0){
        printf("\n=> Phan so tong = -%d/%d = %lf\n", abs(tongTu), abs(tongMau), psTong);
    } else {
    	printf("\n=> Phan so tong = %d/%d = %lf\n", abs(tongTu), abs(tongMau), psTong);
	}
	fclose(f);
	free(ps);
	return 0;
}
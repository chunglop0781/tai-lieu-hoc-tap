#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


void inHeSoAVaB(int n, int m, double *a, double *b){
	printf("Cac he so cua a: %.2lf ", a[0]);
	for(int i = 1; i <= n; i++){
		printf(", %.2lf", a[i]);
	}
	printf("\n");
	printf("Cac he so cua b: %.2lf ", b[0]);
	for(int i = 1; i <= m; i++){
		printf(", %.2lf", b[i]);
	}
	printf("\n");
}

double P(double x, int n, double *a){
	double dathucP = 0;
	for(int i = 0; i <= n; i++){
		dathucP += a[i] * pow(x, i);
	}
	return dathucP;
}

double Q(double x, int m, double *b){
	double dathucQ = 0;
	for(int i = 0; i <= m; i++){
		dathucQ += b[i] * pow(x, i);
	}
	return dathucQ;
}

void tinhS(double d1, double d2, int n, int m, double *a, double *b){
	double S = sqrt(P(d1, n, a) - Q(d2, m, b)) - 2013;
	printf("S = %.4lf", S);
}

void heSoPTruQ(double *a, double *b, int n, int m){
	double *heSo;
	if(n <= m) {
		heSo = (double*)calloc(m+1, sizeof(double));
		for(int i = 0; i <= m; i++){
			heSo[i] = a[i] - b[i];
		}
		printf("He so cua P(x)-Q(x) lan luot la %.2lf", heSo[0]);
		for(int i = 1; i <= m; i++){
			printf(", %.2lf", heSo[i]);
		}
	} else if(n > m) {
		heSo = (double*)calloc(n+1, sizeof(double));
		for(int i = 0; i <= n; i++){
			heSo[i] = a[i] - b[i];
		}
		printf("He so cua P(x)-Q(x) lan luot la %.2lf", heSo[0]);
		for(int i = 1; i <= n; i++){
			printf(", %.2lf", heSo[i]);
		}
	}
	printf("\n");
	free(heSo);
}

int main(){
	FILE *f = fopen("input.txt", "r");
	if(f == NULL){
		printf("Loi file txt!\n");
		return 1;
	}
	int n, m; fscanf(f, "%d %d\n", &n, &m);
	double *a = (double*)calloc(n+1, sizeof(double)); 
	double *b = (double*)calloc(m+1, sizeof(double));
	for(int i = 0; i <= n; i++){
		fscanf(f, "%lf", &a[i]);
	}
	for(int i = 0; i <= m; i++){
		fscanf(f, "%lf", &b[i]);
	}
	inHeSoAVaB(n, m, a, b);
	heSoPTruQ(a, b, n, m);
	double d1, d2;
	printf("Vui long nhap d1 va d2:\n");
	printf("d1 = "); scanf("%lf", &d1);
	printf("d2 = "); scanf("%lf", &d2);
	tinhS(d1, d2, n, m, a, b);
	fclose(f);
	free(a); free(b);
	return 0;
}
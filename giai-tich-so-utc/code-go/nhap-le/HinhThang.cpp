#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int bac;
double hs[100];
double P(double x){
	double result = 0.0;
	for(int i = 0; i <= bac; i++){
		result += hs[i] * pow(x, i);
	}
	return result;
}
void tinhTichPhanHinhThang(double a, double b, int n){
	double h = (b - a) / n;
    double I = P(a) + P(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0){
            I += 2 * P(x);
		}
        else{
            I += 4 * P(x);
		}
    }
    I *= h / 3.0;
    printf("\nGia tri gan dung cua tich phan la: %.5lf\n", I);
}

int main(){
	double a, b, I;
	int n;
	printf("Nhap bac cua da thuc: "); scanf("%d", &bac);
	printf("Nhap cac he so cua da thuc:\n");
	for(int i = 0; i <= bac; i++){
		printf("He so x^%d: ", i); scanf("%lf", &hs[i]);
	}
	printf("Nhap can duoi a: "); scanf("%lf", &a);
	printf("Nhap can tren b: "); scanf("%lf", &b);
	printf("Nhap so doan chia n (phai la so chan): "); scanf("%d", &n);
	if(n <= 0 || n % 2 != 0){
		printf("n phai la so chan va lon hon 0!\n");
		return 1;
	}
	tinhTichPhanHinhThang(a, b, n);
	return 0;
}

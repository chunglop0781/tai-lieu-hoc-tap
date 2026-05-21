# 21052026-lagrange1
```
#include<stdio.h>
#include<math.h>

void nhap(int n, float x[], float y[]){
	printf("Vui long nhap x[i], y[i]:\n");
	for(int i = 0; i < n; i++){
		printf("x[%d] = ", i); scanf("%f", &x[i]);
		printf("y[%d] = ", i); scanf("%f", &y[i]);
	}
}

double lagrange(int n, float x[], float y[], int input_x){
	double P = 0;
	for(int i = 0; i < n; i++){
		double L = 1;
		for(int j = 0; j < n; j++){
			if(i != j){
				L *= (input_x - x[i]) / (x[i] - x[j]);
			}
		}
		P += L * y[i];
	}
	return P;
}

void xuat(double P){
	printf("P = %.2f\n", P);
}

int main(){
	int n, input_x;
	printf("Nhap n, x: ");
	scanf("%d %d", &n, &input_x);
	float x[n], y[n];
	nhap(n, x, y);
	double P = lagrange(n, x, y, input_x);
	xuat(P);
	return 0;
}
```


# 21052026-lagrange2
```
#include<stdio.h>
#include<math.h>

void nhap(int n, int y[]){
	printf("Vui long nhap y[i]:\n");
	for(int i = 0; i < n; i++){
		printf("y[%d] = ", i); scanf("%d", &y[i]);
	}
}

void saiPhanCap1(int n, int y[], int D[]){
	for(int i = 0; i < n; i++){
		D[i] = y[i+1] - y[i];
	}
}

void saiPhanCapCao(int n, int D[], int j){
	for(int i = 0; i < n - j; i++){
		D[i] = D[i+1] - D[i];
	}
}

float newton(int n, int x0, int input_x, int h, int y[], int D[]){
	float t = (float)(input_x - x0) / h;
	float k = t;
	saiPhanCap1(n, y, D);
	float input_y = y[0] + t * D[0];
	for(int j = 2; j < n; j++){
		saiPhanCapCao(n, D, j);
		k *= (t - j + 1) / j;
		input_y += k * D[0];
	}
	return input_y;
}

void xuat(float input_y){
	printf("y = %.2f\n", input_y);
}

int main(){
	int x0, input_x, h, n;
	printf("Vui long nhap x[0], x, h, n: ");
	scanf("%d %d %d %d", &x0, &input_x, &h, &n);
	int y[n], D[n];
	nhap(n, y);
	float result = newton(n, x0, input_x, h, y, D);
	xuat(result);
	return 0;
}
```

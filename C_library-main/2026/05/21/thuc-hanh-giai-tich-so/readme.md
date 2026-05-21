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
	for(int i = 0; i <= n; i++){
		double L = 1;
		for(int j = 0; j <= n; j++){
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
	for(int i = 0; i <= n - j; i++){
		D[i] = D[i+1] - D[i];
	}
}

float newton(int n, int x0, int input_x, int h, int y[], int D[]){
	float t = (float)(input_x - x0) / h;
	float k = t;
	saiPhanCap1(n, y, D);
	float input_y = y[0] + t * D[0];
	for(int j = 2; j <= n; j++){
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

# 21052026-lagrange1-cogiaochua
```
#include <stdio.h>
#include <math.h>

void Nhap(float x[], float y[], int *n)
{
    int i;
    printf("Nhap n = ");
    scanf("%d", n);
    printf("Nhap cac bo gia tri (x,y): \n");
    for(i = 0; i <= *n; i++)
    {
        printf("Nhap x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("Nhap y[%d] = ", i);
        scanf("%f", &y[i]);
    }
}

void In(float x[], float y[], int n)
{
    int i;
    printf("Cac bo gia tri vua nhap la: \n");
    for(i = 0; i <= n; i++)
    {
        printf("(%.2f, %.2f) ", x[i], y[i]);
    }
}

void lagrange(float x[], float y[], int n)
{
    float P = 0, L = 1, x0;
    printf("\nNhap x0 = ");
    scanf("%f", &x0);
    for(int i = 0; i <= n; i++)
    {
        L = 1;
        for(int j = 0; j <= n; j++)
        {
            if(i != j)
                L *= (x0 - x[j]) / (x[i] - x[j]);
        }
        P += L * y[i];
    }

    printf("Gia tri gan dung cua ham so tai x0 la %.2f", P);
}

int main()
{
    int n;
    float x[50], y[50];
    Nhap(x, y, &n);
    In(x, y, n);
    lagrange(x, y, n);
    return 0;
}
```

# Cho hàm số f(x) = (sin(x)) / (x ^ 2 + 1) và số nguyên dương n (n > 2) hãy tính giá trị cho n mốc cách đều trong đoạn [2,3] và coi đó là các mốc nội suy. Sử dụng đa thức nội suy Lagrange để nội suy hàm số f(x) trên [2,3]. Từ đó, tính gần đúng f(x*) với x* ∈ [2,3] nhập từ bàn phím.
```
```

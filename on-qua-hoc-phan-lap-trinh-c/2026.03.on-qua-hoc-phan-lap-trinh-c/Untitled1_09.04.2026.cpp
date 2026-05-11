#include<stdio.h>
#include<math.h>

int main(){
	int n;
	printf("Nhap n: "); scanf("%d", &n); //Nhap n

	float x[n], y[n];
	for(int i = 0; i < n; i++){
		printf("Nhap x[%d] va y[%d]: ", i, i); 
		scanf("%f %f", &x[i], &y[i]);
	} // Nhap x[n], y[n]

	float X;
	printf("Nhap gia tri can tinh: ");
	scanf("%f", &X); // Nhap X

	float S = 0;

	for(int j = 0; j < n; j++){
		float P_1 = 1, P_2 = 1;
		for(int i = 0; i < n; i++){
			if(i != j){
				P_1 *= (X - x[i]);
				P_2 *= (x[j] - x[i]);
			}
		}
		S += (P_1 / P_2) * y[j];
	}

	printf("Gia tri noi suy: %.4f", S);

	return 0;
}
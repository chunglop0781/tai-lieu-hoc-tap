#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void tinhVaXuat(int n, int m, int *a, int *b){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i]>a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for(int i = 0; i < m - 1; i++){
		for(int j = i + 1; j < m; j++){
			if(b[i]>b[j]){
				int temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	int MaxA = a[n-1];
	int MinB = b[0];
	printf("MaxA - MinB = %d\n", MaxA-MinB);
	printf("Day a va day b theo thu tu tang dan:\n");
	printf("Day a: %d", a[0]);
	for(int i = 1; i < n; i++){
		printf(", %d", a[i]);
	}
	printf("\n");
	printf("Day b: %d", b[0]);
	for(int i = 1; i < m; i++){
		printf(", %d", b[i]);
	}
	printf("\n");
}

int main(){
	FILE *f = fopen("input.txt", "r");
	if(f == NULL){
		printf("Loi file txt!\n");
		return 1;
	}
	int n, m; fscanf(f, "%d %d", &n, &m);
	int *a = (int*)calloc(n, sizeof(int));
	int *b = (int*)calloc(m, sizeof(int));
	for(int i = 0; i < n; i++){
		fscanf(f, "%d", &a[i]);
	}
	for(int i = 0; i < m; i++){
		fscanf(f, "%d", &b[i]);
	}
	tinhVaXuat(n, m, a, b);
	fclose(f);
	return 0;
}
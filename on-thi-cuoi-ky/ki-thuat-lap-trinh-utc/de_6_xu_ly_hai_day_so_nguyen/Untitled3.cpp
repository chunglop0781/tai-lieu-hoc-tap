#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void timMinCuaAVaB(int n, int m, int *a, int *b){
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
	printf("Gia tri nho nhat cua day a la %d con day b la %d.\n\n", a[0], b[0]);
}

void kiemTraToanChan(int n, int m, int *a, int *b){
	int soPhanTuAChan = 0;
	int soPhanTuBChan = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % 2 == 0){
			soPhanTuAChan++;
		}
	}
	for(int i = 0; i < m; i++){
		if(b[i] % 2 == 0){
			soPhanTuBChan++;
		}
	}
	if(soPhanTuAChan == n){
		printf("Day a_n toan so chan.\n");
	} else {
		printf("Day a_n co so le.\n");
	}
	if(soPhanTuBChan == m){
		printf("Day b_m toan so chan.\n");
	} else {
		printf("Day b_m co so le.\n");
	}
}

int main(){
	FILE *f = fopen("input.txt", "r");
	if(f == NULL){
		printf("Loi file txt!\n");
		return 1;
	}
	int n, m; fscanf(f, "%d %d\n", &n, &m);
	int *a = (int*)calloc(n, sizeof(int));
	int *b = (int*)calloc(n, sizeof(int));
	for(int i = 0; i < n; i++){
		fscanf(f, "%d", &a[i]);
	}
	for(int i = 0; i < m; i++){
		fscanf(f, "%d", &b[i]);
	}
	timMinCuaAVaB(n, m, a, b);
	kiemTraToanChan(n, m, a, b);
	fclose(f);
	free(a); free(b);
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void timSoLeMax(int n, int *a){
	int *a_le = (int*)malloc(n * sizeof(int));
	int k = 0;
	for(int i = 0; i < n; i++){
    	if(a[i] % 2 != 0){
    	    a_le[k] = a[i];
    	    k++;
    	}
	}
	for(int i = 0; i < k - 1; i++){
    	for(int j = i + 1; j < k; j++){
    	    if(a_le[i] < a_le[j]){
    	        int Temp = a_le[i];
    	        a_le[i] = a_le[j];
    	        a_le[j] = Temp;
    	    }
    	}
	}
	printf("=> So le lon nhat la %d\n", a_le[0]);
	free(a_le);
}

int main(){
	FILE *f = fopen("input.txt", "r");
	if(f == NULL){
		printf("Loi file txt!\n");
		return 1;
	}
	int n; fscanf(f, "%d\n", &n);
	int *a = (int*)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++){
		fscanf(f, "%d ", &a[i]);
	}
	printf("Day so vua nhap do la: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	timSoLeMax(n, a);
	fclose(f);
	free(a);
	return 0;
}
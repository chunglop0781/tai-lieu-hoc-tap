#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


void nhapDay(int n,int *a){
	for(int i=0;i<n;i++){
		printf("Nhap a[%d]: ",i);
		scanf("%d",&a[i]);
	}
}



void xuatDay(int n,int *a){
	printf("Day so: ");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}



void timChanLonNhat(int n,int *a){
	int max=-999999;
	for(int i=1;i<n;i++){
		if(a[i]%2==0){
			if(a[i]>max){
				max=a[i];
			}
		}
	}
	if(max!=-999999){
		printf("So chan lon nhat: %d\n",max);
	}
	else{
		printf("Khong co so chan\n");
	}
}



int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	int *a=(int*)malloc(n*sizeof(int));
	nhapDay(n,a);
	xuatDay(n,a);
	timChanLonNhat(n,a);
	free(a);
	return 0;
}
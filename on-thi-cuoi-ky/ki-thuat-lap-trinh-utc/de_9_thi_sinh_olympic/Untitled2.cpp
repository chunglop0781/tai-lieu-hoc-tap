#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct{
	char HT[50];
	double SD;
	char DH[10];
}ThiSinh;



// Doc danh sach thi sinh
void docThiSinh(FILE *f,int n,ThiSinh *ts){
	for(int i=0;i<n;i++){
		fgets(ts[i].HT,sizeof(ts[i].HT),f);
		ts[i].HT[strcspn(ts[i].HT,"\n")]='\0';
		fscanf(f,"%lf",&ts[i].SD);
		fgetc(f);
		fgets(ts[i].DH,sizeof(ts[i].DH),f);
		ts[i].DH[strcspn(ts[i].DH,"\n")]='\0';
	}
}


// Tinh tong diem tung truong
void tinhTongDiem(int n,ThiSinh *ts){
	double tongA=0;
	double tongB=0;
	double tongC=0;
	for(int i=0;i<n;i++){
		if(strcmp(ts[i].DH,"A")==0){
			tongA+=ts[i].SD;
		}
		if(strcmp(ts[i].DH,"B")==0){
			tongB+=ts[i].SD;
		}
		if(strcmp(ts[i].DH,"C")==0){
			tongC+=ts[i].SD;
		}
	}
	printf("Tong diem A:%.2lf\n",tongA);
	printf("Tong diem B:%.2lf\n",tongB);
	printf("Tong diem C:%.2lf\n",tongC);
	if(tongA<tongB&&tongA<tongC){
		printf("Truong co diem nho nhat:A\n");
	}
	else if(tongB<tongA&&tongB<tongC){
		printf("Truong co diem nho nhat:B\n");
	}
	else{
		printf("Truong co diem nho nhat:C\n");
	}
}



// Sap xep diem giam dan
void sapXep(int n,ThiSinh *ts){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(ts[i].SD<ts[j].SD){
				ThiSinh temp=ts[i];
				ts[i]=ts[j];
				ts[j]=temp;
			}
		}
	}
}



// In 3 thi sinh diem cao nhat
void inTop3(int n,ThiSinh *ts){
	printf("\nTop 3 thi sinh:\n");
	for(int i=0;i<3&&i<n;i++){
		printf("%s %.2lf %s\n", ts[i].HT, ts[i].SD, ts[i].DH);
	}

}



// Xuat ket qua ra file
void xuatFile(FILE *out,int n,ThiSinh *ts){
	for(int i=0;i<n;i++){
		fprintf(out,"%s %.2lf %s\n", ts[i].HT, ts[i].SD, ts[i].DH);
	}
}



int main(){
	FILE *f=fopen("input.txt","r");
	if(f==NULL){
		printf("Loi mo file");
		return 1;
	}
	int n;
	fscanf(f,"%d",&n);
	fgetc(f);
	ThiSinh *ts=(ThiSinh*)malloc(n*sizeof(ThiSinh));
	docThiSinh(f,n,ts);
	fclose(f);
	tinhTongDiem(n,ts);
	sapXep(n,ts);
	inTop3(n,ts);
	FILE *out=fopen("output.txt","w");
	xuatFile(out,n,ts);
	fclose(out);
	free(ts);
	return 0;
}
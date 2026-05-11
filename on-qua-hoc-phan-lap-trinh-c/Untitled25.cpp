#include <stdio.h>
#include <string.h>

typedef struct {
    char ht[100];
    double sd;
    char t[100];
} ThiSinh;

int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled25.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled25!\n");
		return 1;
	}
	int n;
	fscanf(f, "%d\n", &n);
	ThiSinh ts[100];
	for (int i = 0; i < n; i++) {
		fgets(ts[i].ht, 100, f);
		ts[i].ht[strcspn(ts[i].ht, "\n")] = 0;
		fscanf(f, "%lf\n", &ts[i].sd);
		fgets(ts[i].t, 100, f);
		ts[i].t[strcspn(ts[i].t, "\n")] = 0;
	}
    fclose(f);
	char danhsachtruong[100][100];
	double tongdiem[100] = {0};
	int sotruong = 0;
	for (int i = 0; i < n; i++) {
    	int j;
    	for (j = 0; j < sotruong; j++) {
        	if (strcmp(ts[i].t, danhsachtruong[j]) == 0) {
            	tongdiem[j] += ts[i].sd;
            	break;
        	}
    	}
    	if (j == sotruong) { 
        	strcpy(danhsachtruong[sotruong], ts[i].t);
        	tongdiem[sotruong] = ts[i].sd;
        	sotruong++;
    	}
	}
    printf("Tong so diem theo tung truong:\n");
    for (int i = 0; i < sotruong; i++) {
        printf("%-15s : %.0lf\n", danhsachtruong[i], tongdiem[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ts[i].sd < ts[j].sd) {
                ThiSinh temp = ts[i];
                ts[i] = ts[j];
                ts[j] = temp;
            }
        }
    }
    printf("\n");
    printf("3 thi sinh co so diem cao nhat:\n");
    for (int i = 0; i < 3 && i < n; i++) {
        printf("%s - %.0lf - %s\n", ts[i].ht, ts[i].sd, ts[i].t);
    }
    return 0;
}
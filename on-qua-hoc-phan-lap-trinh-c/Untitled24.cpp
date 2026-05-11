#include <stdio.h>
#include <string.h>

typedef struct {
    char ten[100];
    double sbt;
    char doi[100];
} CauThu;

int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled24.txt", "r");
	if (f==NULL) {
		printf("Loi file Untitled24!\n");
		return 1;
	}
	int n;
	fscanf(f, "%d\n", &n);
	CauThu ct[100];
	for (int i = 0; i < n; i++) {
		fgets(ct[i].ten, 100, f);
		ct[i].ten[strcspn(ct[i].ten, "\n")] = 0;
		fscanf(f, "%lf\n", &ct[i].sbt);
		fgets(ct[i].doi, 100, f);
		ct[i].doi[strcspn(ct[i].doi, "\n")] = 0;
	}
    fclose(f);
	char danhsachdoi[100][100];
	double tongsbt[100] = {0};
	int sodoi = 0;
	for (int i = 0; i < n; i++) {
    	int j;
    	for (j = 0; j < sodoi; j++) {
        	if (strcmp(ct[i].doi, danhsachdoi[j]) == 0) {
            	tongsbt[j] += ct[i].sbt;
            	break;
        	}
    	}
    	if (j == sodoi) { 
        	strcpy(danhsachdoi[sodoi], ct[i].doi);
        	tongsbt[sodoi] = ct[i].sbt;
        	sodoi++;
    	}
	}
    printf("Tong so ban thang theo tung doi:\n");
    for (int i = 0; i < sodoi; i++) {
        printf("%-15s : %.0lf\n", danhsachdoi[i], tongsbt[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ct[i].sbt < ct[j].sbt) {
                CauThu temp = ct[i];
                ct[i] = ct[j];
                ct[j] = temp;
            }
        }
    }
    printf("\n");
    printf("3 cau thu ghi nhieu ban thang nhat:\n");
    for (int i = 0; i < 3 && i < n; i++) {
        printf("%s - %.0lf - %s\n", ct[i].ten, ct[i].sbt, ct[i].doi);
    }
    printf("\n");
    printf("3 cau thu ghi it ban thang nhat:\n");
    for (int i = n - 1; i >= n - 3 && i >= 0; i--) {
        printf("%s - %.0lf - %s\n", ct[i].ten, ct[i].sbt, ct[i].doi);
    }

    return 0;
}
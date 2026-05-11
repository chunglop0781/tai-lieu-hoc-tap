#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	int bac;
	double hs[100];
} DaThuc;

int main() {
	FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled14.txt", "r");
	if (f == NULL) {
		printf("Loi file Untitled14.txt!\n");
		return 1;
	}
	DaThuc P, Q, Tong, Hieu;
	double x1;
	double Px = 0, Qx = 0;
    fscanf(f, "%d\n", &P.bac);
    for (int i = 0; i <= P.bac; i++) {
        fscanf(f, "%lf\n", &P.hs[i]);
	}
    fscanf(f, "%d\n", &Q.bac);
    for (int i = 0; i <= Q.bac; i++) {
        fscanf(f, "%lf\n", &Q.hs[i]);
	}
    fscanf(f, "%lf\n", &x1);
    fclose(f);
    for (int i = 0; i <= P.bac; i++) {
        if (i + 1 == x1) {
        	Px = P.hs[i];
		}
	}
    for (int i = 0; i <= Q.bac; i++) {
        if (i + 1 == x1) {
        	Qx = Q.hs[i];
		}
	}
	printf("x1 = %.2lf\n", x1);
	printf("P(x1) = %.2lf\n", Px);
	printf("Q(x1) = %.2lf\n", Qx);
	if (Qx != 0) {
		printf("S = P(x1) / Q(x1) = %.2lf\n", Px / Qx);
	} else {
		printf("Khong the chia cho 0!\n");
	}
    Tong.bac = (P.bac > Q.bac) ? P.bac : Q.bac;
    for (int i = 0; i <= Tong.bac; i++) {
        Tong.hs[i] = 0;
        if (i <= P.bac) {
        	Tong.hs[i] += P.hs[i];
		}
        if (i <= Q.bac) {
        	Tong.hs[i] += Q.hs[i];
		}
    }
    Hieu.bac = (P.bac > Q.bac) ? P.bac : Q.bac;
    for (int i = 0; i <= Hieu.bac; i++) {
        Hieu.hs[i] = 0;
        if (i <= P.bac) {
        	Hieu.hs[i] += P.hs[i];
		}
        if (i <= Q.bac) {
        	Hieu.hs[i] -= Q.hs[i];
		}
    }
    printf("Da thuc P(x) + Q(x):\n");
    for (int i = Tong.bac; i >= 0; i--) {
        if (Tong.hs[i] != 0) {
            printf("%.2lf*x^%d ", Tong.hs[i], i);
		}
        if (i > 0 && Tong.hs[i-1] != 0) {
            printf("+ ");
		}
    }
    printf("\n");
    printf("Da thuc P(x) - Q(x):\n");
    for (int i = Hieu.bac; i >= 0; i--) {
        if (Hieu.hs[i] != 0) {
            printf("%.2lf*x^%d ", Hieu.hs[i], i);
		}
        if (i > 0 && Hieu.hs[i-1] != 0) {
            printf("+ ");
		}
    }
    printf("\n");
    return 0;
}
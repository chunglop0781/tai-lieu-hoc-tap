#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int bac;
double hs[100];

//P(x) tinh hinhThang
double P(double x) {
    double result = 0.0;
    for (int i = 0; i <= bac; i++) {
        result += hs[i] * pow(x, i);
    }
    return result;
}

// Langrange
void In(float x[], float y[], int n){
    for(int i = 0; i < n; i++){
        printf("(%.2f, %.2f)", x[i], y[i]);
    }
    printf("\n");
}
void Lagrange(float x[], float y[], int n){
    float x0, P = 0;
    printf("Nhap x* = "); scanf("%f", &x0);
    for(int i = 0; i < n; i++){
        float L = 1;
        for(int j = 0; j < n; j++){
            if(i != j){
                L *= (x0-x[j])/(x[i]-x[j]);
            }
        }
        P += y[i] * L;
    }
    printf("f(*x) = %.6f\n", P);
}


//NewtonTien
void noiSuyNewtonTien(int n, double x0, double x, double h, double D[]){
    double y0 = D[0];
    double t = (x-x0)/h;
    double k = t;
    double ketQua;
    for(int i = 0; i < n; i++){
        D[i] = D[i + 1] - D[i];
    }
    ketQua = y0 + t * D[0];
    for(int j = 2; j <= n; j++){
        for(int i = 0; i <= n - j; i++){
            D[i] = D[i + 1] - D[i];
        }
        k = k * (t-j+1)/j;
        ketQua = ketQua + k * D[0];
    }
    printf("\nKet qua = %lf\n", ketQua);
}


//NewtonLui
void NewtonLui(int n, double x[], double y[]){
    double xCanTinh;
    printf("Nhap xCanTinh = "); scanf("%lf", &xCanTinh);
    double h = x[1] - x[0];
    double D[100];
    for(int i = 0; i <= n - 1; i++){
        D[i] = y[i+1] - y[i];
    }
    double t = (xCanTinh - x[n])/h;
    double k = t;
    double ketQua = y[n] + t * D[n-1];
    for(int j = 2; j <= n; j++){
        for(int i = 0; i <= n - j; i++){
            D[i] = D[i + 1] - D[i];
        }
        k = k * (t+j-1)/j;
        ketQua = ketQua + k * D[n - j];
    }
    printf("\nKet qua = %lf\n", ketQua);
}


// NoiSuyNewtonTrenLuoiKhongDeu
void NoiSuyNewtonTrenLuoiKhongDeu(int n, double x[], double y[]){
    double xCanTinh;
    printf("Nhap xCanTinh = "); scanf("%lf", &xCanTinh);
    double F[100];
    double ketQua = y[0];
    double tich = xCanTinh - x[0];
    for (int i = 0; i < n; i++){
        F[i] = (y[i + 1] - y[i])/(x[i+1]-x[i]);
    }
    ketQua = ketQua + F[0] * tich;
    for(int j = 2; j <= n; j++){
        for(int i = 0; i <= n - j; i++){
            F[i] = (F[i + 1] - F[i])/(x[i+j]-x[i]);
        }
        tich = tich * (xCanTinh - x[j-1]);
        ketQua = ketQua + F[0] * tich;
    }
    printf("\nKet qua = %lf\n", ketQua);
}

//tinhTichPhanSimpson
void tinhTichPhanSimpson(double a, double b, int n) {
    double h = (b - a) / n;
    double I = P(a) + P(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0)
            I += 2 * P(x);
        else
            I += 4 * P(x);
    }
    I *= h / 3.0;
    printf("\nGia tri gan dung cua tich phan la: %lf\n", I);
}

///* Chia doi *///
double f(double x){
	return pow(x,2) - 4;
}

///* Day cung *///
double F(double x){
	return pow(x,4) - 3 * pow(x,2) - (-75 * x + 10000);
}


int main(){
    int luaChon;
    printf("1. Lagrange.\n");
    printf("2. NewtonTien.\n");
    printf("3. NewtonLui.\n");
    printf("4. NoiSuyNewtonTrenLuoiKhongDeu.\n");
    printf("5. tinhTichPhanSimpson.\n");
    printf("6. Chia doi.\n");
    printf("7. tinhTichPhanSimpson.\n");
    printf("Nhap lua chon: "); scanf("%d", &luaChon);
    if(luaChon == 1){
        float x[50], y[50]; int n;
        printf("Nhap n = "); scanf("%d", &n);
        for(int i = 0; i < n; i++){
            printf("x[%d] = ", i); scanf("%f", &x[i]);
            printf("y[%d] = ", i); scanf("%f", &y[i]);
        }
        In(x, y, n);
        Lagrange(x, y, n);
        // test f(x)=x^2+1
        // n = 4
        // x[0] = 0
        // y[0] = 1
        // x[1] = 1
        // y[1] = 2
        // x[2] = 2
        // y[2] = 9
        // x[3] = 3
        // y[3] = 28
        // x* = 1.5
        // f(1.5) = 4.375
    } else if(luaChon == 2){
        int n;
        double x0, x, h, D[100];
        printf("Nhap n = "); scanf("%d", &n);
        printf("Nhap x0 = "); scanf("%lf", &x0);
        printf("Nhap x_can_tinh = "); scanf("%lf", &x);
        printf("Nhap h = "); scanf("%lf", &h);
        printf("Nhap cac gia tri y:\n");
        for(int i = 0; i <= n; i++){
            printf("y[%d] = ", i); scanf("%lf", &D[i]);
        }
        noiSuyNewtonTien(n, x0, x, h, D);
        // test f(x)=x^2+1
        // n = 3
        // x0 = 0
        // x can tinh = 1.5
        // h = 1
        // y[0] = 1
        // y[1] = 2
        // y[2] = 9
        // y[3] = 28
        // Ket qua = 4.375000
    } else if(luaChon == 3){
        int n;
        double x[100], y[100];
        printf("Nhap bac cua da thuc n = "); scanf("%d", &n);
        printf("Nhap cac gia tri cua x:\n");
        for(int i = 0; i <= n; i++){
            printf("x[%d] = ", i); scanf("%lf", &x[i]);
        }
        printf("Nhap cac gia tri cua y:\n");
        for(int i = 0; i <= n; i++){
            printf("y[%d] = ", i); scanf("%lf", &y[i]);
        }
        NewtonLui(n, x, y);
        // test f(x)=x^2+1
        // n = 3
        // x[0] = 0
        // x[1] = 1
        // x[2] = 2
        // x[3] = 3
        // y[0] = 1
        // y[1] = 2
        // y[2] = 9
        // y[3] = 28
        // x can tinh = 2.5
        // Ket qua = 16.625000
    } else if(luaChon == 4){
        int n;
        double x[100], y[100];
        printf("Nhap bac cua da thuc n = "); scanf("%d", &n);
        printf("Nhap cac gia tri cua x:\n");
        for(int i = 0; i <= n; i++){
            printf("x[%d] = ", i); scanf("%lf", &x[i]);
        }
        printf("Nhap cac gia tri cua y:\n");
        for(int i = 0; i <= n; i++){
            printf("y[%d] = ", i); scanf("%lf", &y[i]);
        }
        NoiSuyNewtonTrenLuoiKhongDeu(n, x, y);
        // test f(x)=x^2+1
        // n = 3
        // x[0] = 0
        // x[1] = 1
        // x[2] = 3
        // x[3] = 4
        // y[0] = 1
        // y[1] = 2
        // y[2] = 10
        // y[3] = 17
        // x can tinh = 2
        // Ket qua = 5.000000
    } else if(luaChon == 5){
        double a, b, I;
        int n;
        printf("Nhap bac cua da thuc: ");
        scanf("%d", &bac);
        printf("Nhap cac he so cua da thuc:\n");
        for (int i = 0; i <= bac; i++) {
            printf("He so x^%d: ", i);
            scanf("%lf", &hs[i]);
        }
        printf("Nhap can duoi a: ");
        scanf("%lf", &a);
        printf("Nhap can tren b: ");
        scanf("%lf", &b);
        printf("Nhap so doan chia n (phai la so chan): ");
        scanf("%d", &n);
        if (n <= 0 || n % 2 != 0) {
            printf("n phai la so chan va lon hon 0!\n");
            return 1;
        }
        tinhTichPhanSimpson(a, b, n);
        // 1+2x+x^2
        // double a = -3.0;
        // double b = 7.0;
    } else if(luaChon == 6){
        	double a, b, ss;
	        printf("Nhap vao khoang [a,b]: ");
	        scanf("%lf %lf", &a, &b);
	        printf("Nhap sai so ss: ");
	        scanf("%lf", &ss);
	        double c;
	        c = (a + b) / 2;
	        if (f(c) == 0) {
	        	break;
	        }
	        if (f(a) * f(c) < 0) {
	        	b = c;
	        } else {
	        	a = c;
	        }
	        if (b - a < ss) {
	        	c = (a + b) / 2;
	        	break;
	        }
	        printf("Nghiem c tim duoc la: %lf\n", c);
    } else if(luaChon == 7){
        	double a, b, ss;
	double x0, Fu, x1;
	int dem = 0;
	printf("Nhap khoang cach [a, b]:\n");
	printf("a = "); scanf("%lf", &a);
	printf("b = "); scanf("%lf", &b);
	printf("Nhap sai so (ss): "); scanf("%lf", &ss);
	if (F(a) > 0){
		x0 = b;
		Fu = a;
	} else {
        x0 = a;
        Fu = b;
    }
    do {
    	x1 = x0 - (F(x0) / (F(Fu) - F(x0))) * (Fu - x0);
    	if(fabs(x1 - x0) < ss){
    		break;
		} else {
			x0 = x1;
		}
		dem++;
	} while (dem < 100000);
	printf("\nGiao diem cua f(x) va g(x) la: x1 = %.7lf\n", x1);
	printf("So buoc lap = %d\n", dem);
    }
    return 0;
}

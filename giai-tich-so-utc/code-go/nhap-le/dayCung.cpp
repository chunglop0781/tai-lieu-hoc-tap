#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double F(double x){
	return pow(3, x) + 2 * sin(x) - 10;
}

void dayCung(double a, double b, double ss, double x0, double Fu, double x1, int dem){
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

int main(){
	    double a, b, ss;
	    double x0, Fu, x1;
	    int dem = 0;
	    printf("Nhap khoang cach [a, b]:\n");
	    printf("a = "); scanf("%lf", &a);
	    printf("b = "); scanf("%lf", &b);
	    printf("Nhap sai so (ss): "); scanf("%lf", &ss);
	    dayCung(a, b, ss, x0, Fu, x1, dem);
	    return 0;
}
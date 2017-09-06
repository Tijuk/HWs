#include <stdio.h>
#include <stdlib.h>
#include "raiz2.h"
#include "math.h"

double funcao(double x){
	return cos(x) - powf(x,3) + x;
}

void test1(){
	double x0 = 0;
	double x1 = 3;
	int p = 6;
	double raiz = -1000;
	int sec = secante(x0,x1,p,funcao,&raiz);
	printf("\tx0[%lf] - x1[%lf] - p[%d]\n\tsec[%d] - raiz[%lf]", x0,x1,p,sec,raiz);
}

void test2(){
	double x0 = 0;
	double x1 = 1.5;
	double x2 = 3.0;
	int p = 6;
	double raiz = -1000;
	int iqi = IQI(x0,x1,x2,p,funcao,&raiz);
	printf("\tx0[%lf] - x1[%lf] - x2[%lf] - p[%d]\n\tiqi[%d] - raiz[%lf]", x0,x1,x2,p,iqi,raiz);
}

int main(){
	printf("\n");
	test1();
	printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	test2();
	printf("\n\n");
	system("pause");
	return 0;
}

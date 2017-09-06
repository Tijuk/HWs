#include <stdio.h>
#include <stdlib.h>
#include "raiz.h"

double f(double x){
	return x-3;	
}

void test1(double a, double b, int p){
	printf("f(x) = x-3, [a,b] = [%1.1lf,%1.1lf], p = %d\n", a,b,p);
	printf("\tResult = [%lf]\n\n", bissecao(a,b,p,f));
}

void test2(double v, double r){
	printf("Vol = %1.1lf, Raio = %1.1lf\n\tAltura = [%lf]\n\n", v,r, altura_agua(v,r));
}

void test3(double val){
	printf("Valor = %1.1lf\n\tRaiz de %1.1lf = [%lf]\n\n", val,val,fraiz(val));
}

int main(){
	test1(0,5,5);
	test2(1,1);
	test3(4);
	return 0;
}

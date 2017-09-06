#include <stdlib.h>
#include <stdio.h>
#include "raiz.h"
#include <math.h>

double tolerancia(int p){
	return 0.5 * pow(10, -p);
}

double bissecao (double a, double b, int p, double (*f) (double x)){
	//printf("%lf,%lf,%d", a,b,p);
	double tol = tolerancia(p);
	double min = a;
	double max = b;
	double erro = (b-a)/2;
	double c = (min+max)/2;
	while(erro >= tol){
		//printf("Running: %lf,%lf,%lf\n", erro, tol, c);
		if( ((*f)(min)) * ((*f)(c)) < 0){
			max = c;
		}
		else{
			min = c;
		}
		c = (min+max)/2;
		erro /= 2;
	}
	return c;
}

double altura_agua (double r, double v){
	double f(double x){
		return v - ((M_PI * pow(x,2))/3)*(3 * r - x);
	}
	return bissecao(0,v, 4, f);
}

double pontofixo (double x0, double epsilon, double (*g) (double x)){
	double x = x0;
	while(fabs((*g)(x) - x) > epsilon){
		x = (*g)(x);
	}
	return x;	
}

double fraiz (double z){
	double g(double x){
		return (x + z/x)/2;
	}
	double tol = tolerancia(6);
	return pontofixo(z, tol, g);
}

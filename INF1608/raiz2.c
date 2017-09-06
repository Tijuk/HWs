#include "raiz2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double absf(double x){
	return (x<0)? -x : x;
}

double derivada(double f0, double f1,double x0, double x1){
	return (f1 - f0)/(x1 - x0);
}

double det_aux(double (*f)(double), double a1, double b2, double c3){
	double f_a1 = (double)( (*f)(a1) );
	double f_b2 = (double)( (*f)(b2));
	return powf(f_a1,2) * f_b2 * c3;
}

double cramer(double (*f)(double), double x0, double x1, double x2){
	double pos_A = det_aux(f,x0,x1,1) + det_aux(f, x2, x0, 1) + det_aux(f, x1, x2, 1);
	double neg_A = det_aux(f,x0,x2,1) + det_aux(f, x1, x0, 1) + det_aux(f, x2, x1, 1);
	double det_A = pos_A - neg_A;

	double pos_Ac = det_aux(f,x0,x1,x2) + det_aux(f, x2, x0, x1) + det_aux(f, x1, x2, x0);
	double neg_Ac = det_aux(f,x0,x2,x1) + det_aux(f, x1, x0, x2) + det_aux(f, x2, x1, x0);
	double det_Ac = pos_Ac - neg_Ac;
	return det_Ac/det_A;
}

double NR(double x, double f, double f_linha){
	return x - ( f / f_linha );
}

int secante (double x0, double x1, int p, double (*f) (double x), double* r){
	double backward = 0.5 * powf(10,-p);
	int i;
	double fa, fa_, fb, fb_,a,b;
	a = x0;
	b = x1;
	*r = x0;
	fa = (double)(*f)(a);
	fb = (double)(*f)(b);
	fb_ = derivada(fa,fb, a,b);
	for(i = 0; i < 50; i++){
		a = b;
		fa = fb;
		fa_ = fb_;
		b = NR(a, fa, fa_);
		fb = (double)(*f)(b);
		fb_ = derivada(fa,fb,a,b);
		*r = b;
		if(absf(fb) < backward){
			return i;
		}
	}
	return 0;
}

int IQI (double x0, double x1, double x2, int p, double (*f) (double x), double* r){
	double backward = 0.5 * powf(10,-p);
	double a,b,c,c_novo, fa,fb,fc;//fa_,fb_,fc_;
	int i;
	a = x0; b = x1; c = x2;
	fa = (double)(*f)(a); fb = (double)(*f)(b); fc = (double)(*f)(c);
	for(i = 0; i < 50; i++){
		c_novo = cramer(f, a,b,c);
		a = b;
		fa = fb;
		b = c;
		fb = fc;
		c = c_novo;
		fc = (double)(*f)(c);
		*r = c;
		if(absf(fc) < backward){
			return i;
		}
	}
	return 0;
}

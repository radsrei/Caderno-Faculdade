#include <stdio.h>
#include <stdlib.h>

double media (double a,double b,double c);

int main (void){
	double x,y,z;
	scanf("%lf %lf %lf", &x,&y,&z);
	double resultado;
	resultado = media (x,y,z);
	printf ("Media eh:%.2lf",resultado);
	
	return 0;
}

double media (double a,double b,double c){
	double media;
	media = (a+b+c)/3;
	return media;
}

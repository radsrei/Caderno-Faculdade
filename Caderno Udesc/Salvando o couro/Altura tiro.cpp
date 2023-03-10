#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define tempoMax       1000000

int main (void){
	
	double T, V;
	
	double x,y,t,g;
	double max;
	g=9.8;
	

	printf("T em radians:");
	scanf("%lf",&T);
	
	printf("V:");
	scanf("%lf",&V);
	int i;
	for(i=0;i<tempoMax;i++){
		
		t=0.01*i;
		x=(V*cos(T))*t;
		y=(V*sin(T))*t - ((1/2)*g*pow(t,2));
		max=y;
		if(max>y){
			break;
		}
		printf("\tx=%.2lf \ty=%.2lf no tempo=%.2lf\n",x,y,t);
		
	}
	
	
	printf ("Maior altura eh %.2lf no tempo %.2lf",max,t);
	return 0;

	
}

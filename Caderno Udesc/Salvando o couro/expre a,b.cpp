#include <stdio.h>
#include <stdlib.h>

float expre(int a, int b);

int main (void){
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	float resultado;
	resultado=expre(a,b);
	printf("%.2f",resultado);
	
	return 0;
}


float expre(int a, int b){
	return ((a+b)*(a-b));
}

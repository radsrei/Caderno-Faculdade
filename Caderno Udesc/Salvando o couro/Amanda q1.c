#include <stdio.h>
#include <stdlib.h> 

typedef struct estrutura {
    int a,b,c;
}estrutura;

int main (void){
    estrutura base;
    scanf("%d %d %d",&base.a,&base.b,&base.c);
    // printf("%d %d %d",base.a,base.b,base.c);
	if((base.a+base.b)>base.c){
   		if((base.a+base.c)>base.b){
   			if((base.b+base.c)>base.a){
   				printf("Eh um triangulo");
			}
		}
	}
   	else{
   		printf("Nao eh triangulo");
	}
    return 0;
}

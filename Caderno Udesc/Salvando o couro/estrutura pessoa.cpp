#include <stdio.h>
#include <stdlib.h>


typedef struct pessoa{
    char nome [15];
    int idade;
}pessoa;


float media(pessoa *l);
void bubbleSort(pessoa *l,int n);

int main (void){
    pessoa lista[5];
    int i;
    float id_media;
    for(i=0;i<5;i++){
    	printf("nome:");
        scanf("%s",&lista[i].nome);
    }
    for(i=0;i<5;i++){;
            printf("idade:");
        scanf("%d",&lista[i].idade);
    }
    id_media=media(lista);
    bubbleSort(lista,5);
    for(i=0;i<5;i++){
        printf("Nome: %s\nIdade: %d\n\n",lista[i].nome,lista[i].idade);
    }
    printf("Media das idades %.2f",id_media);
    return 0;
}



float media(pessoa *l){

	int i;
	float soma=0;
	for(i=0;i<5;i++){
		soma+=l[i].idade;
	}
	return (soma/5);
}


void bubbleSort(pessoa *l, int n){ 

	int i;
	pessoa aux;
    for (i=0; i<n; i++) {
        if (l[i].idade < l[i+1].idade){
            aux=l[i];
			l[i]=l[i+1];
			l[i+1]=aux; 
		}
    bubbleSort(l,n-1); 
	}
} 

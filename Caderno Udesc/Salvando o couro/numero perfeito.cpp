#include <stdio.h>

int main(){
    int n, aux, i;

    scanf("%d", &n);
    aux = 0;

    for(i=1; i<n; i++){
        if (n%i==0){
            aux += i;
        }        
    }
    if (aux == n){
      printf("numero perfeito");
    }
    else{
    	printf("nao perfeito");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>


int main (void){
	int matrix [4][4]={0};
	int i,j;
	int cordx, cordy;
	int max,min;
	
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(i==0 && j==0){
				max = matrix[i][j];
				printf("max: %d\n",max);
			}
			if(matrix[i][j]>max){
				max = matrix[i][j];
				cordx=i;
				cordy=j;
				printf("max: %d\n",max);
			}
		}
	}
	min=matrix[cordx][0];
	for(j=0;j<4;j++){
		if(min>matrix[cordx][j]){
			min=matrix[cordx][j];
			printf("\nmin: %d\n", min);
		}
	}
	
	
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%d  ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("Minimax:%d  nas coordenadas %d %d\n",min,cordx+1,cordy+1);
	return 0;
}

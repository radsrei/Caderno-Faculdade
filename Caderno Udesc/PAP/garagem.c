#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "manutencao.h"



Carro * carros;
int num_carros;

int main()
{
	int i;
    num_carros = obtem_carros_de_arquivo( "carros.csv" );
    if ( num_carros > 0 )
    {
        printf("* Lista de Carros:\n");
        for (i = 0; i < num_carros; i++ )
        {
            printf("%s, %d anos\n", carros[i].modelo, carros[i].ano );
        }

        bubble_sort( carros, num_carros, sizeof(Carro), comparaCarros );

		printf("\n\n* Lista de alunos ordenada:\n");
        for (i = 0; i < num_carros; i++ )
        {
            printf("%s,feito em %d, %s\n", carros[i].modelo, carros[i].ano, carros[i].cor);
        }
    }
    else
    {
        printf("Nenhum Carros lido do arquivo CSV.");
    }

    free( carros );
    return 0;
}

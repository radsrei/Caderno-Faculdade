#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXIMO_DE_ESTUDANTES 100


//
// Carro * carros;
// int num_carros;

typedef struct{
    char * placa;
    char * modelo;
    char * cor;
    int ano;
} Carro;


int comparaCarros( void * a, void * b );
int preenche_estrutura( Carro * carros, char * linha );
int obtem_carros_de_arquivo( const char * arquivo );

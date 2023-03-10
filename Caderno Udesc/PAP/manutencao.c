#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "manutencao.h"

#define MAXIMO_DE_ESTUDANTES 100


 Carro * carros;
 int num_carros;


int obtem_carros_de_arquivo( const char * arquivo )
{
    FILE * fd = NULL;
    char * linha = NULL;
    int tam = 0;
    int lido = 0;
    int i;
    unsigned short contador = 0;
    char * conteudo[ MAXIMO_DE_ESTUDANTES ];

    fd = fopen( arquivo, "r" );
    if ( fd == NULL )
    {
        perror( "Erro ao abrir arquivo" );
        return -1;
    }

    memset( conteudo, 0, MAXIMO_DE_ESTUDANTES );

    while ( ( lido = getline( &linha, &tam, fd ) ) != -1 )
    {
#ifdef DEBUG
        printf( "%s", linha );
#endif
    conteudo[ contador ] = strdup( linha );
    contador++;
    }

    carros = (Carro*)malloc( contador * sizeof (Carro) );
    for ( i = 0; i < contador; i++ )
    {
        if ( conteudo[i] != NULL )
        {
            preenche_estrutura( &carros[i], conteudo[i] );
        }
    }

    // Liberar tudo que foi alocado
    for ( i = 0; i < contador; i++ )
    {
        free( conteudo[i] );
    }
    free(linha);
    fclose( fd );
    return contador;
}

int preenche_estrutura( Carro * carros, char * linha )
{
    unsigned short indice = 0;
    char * tok;
    for ( tok = strtok(linha, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n") )
    {
#ifdef DEBUG
        printf( "%d, %s\n", indice, tok );
#endif
        switch( indice )
        {
            case 0:
                carros->placa = strdup( tok );
                break;
            case 1:
                carros->modelo = strdup (tok);
                break;
            case 2:
                carros->cor = strdup (tok);
                break;
            case 3:
                carros->ano = atoi( tok );
                break;
            default:
                perror( "Erro ao processar arquivo CSV: formato fora do esperado." );
                return -1;
        }
        indice++;
    }
}



int comparaCarros( void * a, void * b )
{
    Carro * est_a = (Carro *) a;
    Carro * est_b = (Carro *) b;
    return est_b->ano - est_a->ano;
}

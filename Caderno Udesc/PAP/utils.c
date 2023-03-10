#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define MAXIMO_DE_ESTUDANTES 100
/* Notas:
 * https://linux.die.net/man/3/getline
 * http://man7.org/linux/man-pages/man3/perror.3.html
 */



void swap( void * vp1, void * vp2, int size )
{
    char * tmp = (char *) malloc( size );
    memcpy( tmp, vp1, size );
    memcpy( vp1, vp2, size );
    memcpy( vp2, tmp, size );
    free( tmp );
}

void bubble_sort( void * inicio_array, int num_elementos,int tam_elemento, int (*cmpfn)(void*, void*) ){
    int i,j;
    for( i = 0; i < num_elementos; ++i )
    {
        void * elemento_observado = inicio_array + i * tam_elemento;
        for ( j = 0; j < num_elementos; j++ )
        {
            void * elemento_comparado = inicio_array + j * tam_elemento;
            if ( cmpfn( elemento_observado, elemento_comparado ) > 0 )
            {
                swap( elemento_observado, elemento_comparado, tam_elemento );
            }
        }
    }
}

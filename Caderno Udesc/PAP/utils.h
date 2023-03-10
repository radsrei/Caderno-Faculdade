#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXIMO_DE_ESTUDANTES 100

/* Notas:
 * https://linux.die.net/man/3/getline
 * http://man7.org/linux/man-pages/man3/perror.3.html
 */

//sem tipagem aparente
void swap( void * vp1, void * vp2, int size );
void bubble_sort( void * inicio_array, int num_elementos,int tam_elemento, int (*cmpfn)(void*, void*) );

//com tipagem aparente

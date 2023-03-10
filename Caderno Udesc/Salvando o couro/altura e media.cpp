#include <stdio.h>
struct fulano {char nome[15];
               int altura; };
               
float media(struct fulano v[5])
{
    int i; float media=0;
    for(i=0;i<5;i++)
       media=media+v[i].altura;
    media=media/5;
    return(media);
}

int main( )
{
    struct fulano lista[5];
    int i; float im;
    for(i=0;i<5;i++)
    {
        printf("Nome: ");
        scanf("%s", lista[i].nome);
        printf("Altura: ");
        scanf("%d", &lista[i].altura);
    }
    for(i=0;i<5;i++)
        printf("%-10s%d\n", lista[i].nome,lista[i].altura);
        im=media(lista);
    printf("\nA media das alturas eh %f", im);
}

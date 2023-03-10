#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float iteracao(float, float);

float pow(float x);

float achar_valor(float x);

float valor_medio(float a, float b);

float teste_lado(float,float,float);

int main (void){
    int i;
    float j;
    float k;
    float a,b;
    float l, aux;
    float saidaa;
    float saidab;

    a = 0.531;
    b = 2.26;

    printf("Intervalo inicial %.3f --- %.3f\n",a,b);
    for (i = 0; i < 8; i ++){

        l = valor_medio(a,b);
       //printf("Medio %f\n",l);

        aux = achar_valor(l);

        saidaa = achar_valor(a);
        //printf("Saida a %f\n",saidaa);

        saidab = achar_valor(b);
        //printf("Saida b %f\n",saidab);

        k = teste_lado (aux,saidaa,saidab);
        printf ("Rodada = %d, %.7f, %.7f\t", i+1 ,a,b);
        printf("Valor medio = %.7f\n",l);
        if (k == 1){
            b = l;
        }
        if (k == 2)
            a = l;
    }

    float passo;
    passo = iteracao(a,b);
    int deu;
    deu = ceil(passo);
    printf("Numero de iterações para 10 elevado a -29 = %d",deu);
    //printf ("Rodada = %d, %.7f, %.7f\n", i,a,b);
    return 0;
}


float pow (float x){
    return (x*x*x*x*x);
}

float achar_valor(float x){
    float nvalor;
    nvalor = (pow(x) - (4*x) - 3);
    return nvalor;
}

float valor_medio(float a, float b){
    float valor;
    valor = (a + b)/2;
    return valor;
}

float teste_lado(float l, float a, float b){
    if(a * l < 0)
        return 1;
    if(b * l < 0)
        return 2;
}

float iteracao(float a, float b){
    long long double E;
    float runs;
    E = pow(10,-29);
    runs = (log(b-a)- log(E))/log(2);
    return runs;
}

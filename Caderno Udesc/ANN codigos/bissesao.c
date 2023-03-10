#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float iteracao(float, float);
float pot(float x);
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

        aux = achar_valor(l);

        saidaa = achar_valor(a);

        saidab = achar_valor(b);

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
    passo *=-1;
    int deu;
    deu = floor(passo);
    printf ("Numeros de repeticoes = %d\n", deu);
    return 0;   
}


float pot (float x){
    return (x*x*x*x*x);
}

float achar_valor(float x){
    float nvalor;
    nvalor = (pot(x) - (4*x) - 3);
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
    long double E;
    long double E2;
 
    float runs;
    E = pow(10,29);
    E2 = 1/E;

    runs = (log(b-a)- log(E))/(log(2));
    return runs;
}
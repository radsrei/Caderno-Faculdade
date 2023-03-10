#include <iostream>
using namespace std;




int main (void){
    float variavel;
    float limiteE;
    float limiteD;
    float g,x;
    double f,p;
    //g (x) = 2 + (7.29/((x*x)+6))
    //g'(x) = -14.58/((x*x+6)*(x*x+6))
    //f(x) = (x*x*x)-2*(x*x)+6*x-19.29
    //p1 = 2.89
    p = 2.89;
    limiteD = 3;
    limiteE = 2;
    g = 2 + (7.29/((x*x)+6));
    for( int i=1;i<=8;i++){
        //f = (p*p*p)-2*(p*p)+6*p-19.29;
        g = 2 + (7.29/((p*p)+6));
        printf("%d %.7lf\n",i,p);
       p = g;
    }
    //printf("%.7lf\n",p);
    return 0;
}




/*
void pontofixo(float a, float b, float c, float x0){
    //x0=1;
    int cont=0;
    float x,s,v,d,fx;
    do{

        cont = cont+1;
        x = quici(x0);
        fx=polinomio(x);
        v=mod(fx);
        d=x-x0;
        d=mod(d);
        if((v<c)||(d<c)){
            printf("\n iteracao : %d | x = %f | f(x) = %f ",cont,x,fx);
            break;
        }
        x0=x;
        printf("\n iteracao : %d | x = %f | f(x) = %f ",cont,x,fx);
    }while((v>c)||(d>c));

}

*/
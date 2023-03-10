#include <iostream>
using namespace std;

double fx(double x);
double falso(double a, double b, double fda, double fdb);

int main (void){
    
    double a;//xm
    double b;//x
    double n;//xn
    
    double fda;
    double fdb;
    double fdn;
        
    a = -0.548;
    b = 0.503;   
    fda = fx(a);
    fdb = fx(b);    
    int i;
    if(fda*fdb < 0){//ver se tem raiz da função
        for (i=0;i<21;i++){
            n = falso(a,b,fda,fdb);//acha o "novo" ponto
            fdn = fx(n);//aplica porque sim
            if(fdn*fda<0){//quem troca
                b = n;
            }
            if(fdn*fdb<0){//quem troca
                a = n;
            }
        }//repete
    }
    printf("Valor de aproximação = %.8f\n",n);  
    return 0;
}



double fx(double x){
    double result;
    result = ((x*x*x) - 4*x - 1);
    return result;
}   

double falso(double a, double b, double fda, double fdb){
    double n =0 ;
    n = (((a*fdb)-(b*fda))/(fdb-fda));
    return n;
}


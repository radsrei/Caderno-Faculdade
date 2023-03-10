#include <iostream>
using namespace std;



int main (void){
    //float x1,x2,x3,x4,x5;
    double vet[5] = {-0.6,1.9,0.8,0.6,3.0};
    for (int i=0; i<10; i++){
        vet[0]= ( vet[1]*1.1 -vet[2]*2.0 -vet[3]*2.8 +vet[4]*0.4 -2.9)/6.5;
        vet[1]= ( vet[0]*0.1 -vet[2]*1.6 +vet[3]*1.4 +vet[4]*1.8 -1.9)/8.5;
        vet[2]= (-vet[0]*2.5 +vet[1]*1.5 -vet[3]*1.3 +vet[4]*1.6 +1.5)/8.7;
        vet[3]= (-vet[0]*2.5 -vet[1]*1.7 +vet[2]*2.6 +vet[4]*1.8 +0.0)/8.7;
        vet[4]= (-vet[0]*2.5 +vet[1]*1.9 +vet[2]*2.7 +vet[3]*0.3 +4.5)/7.7;
        //printf("\n%d %lf%lf%lf%lf%lf",i+1,aux[0],aux[1],aux[2],aux[3],aux[4]);
    }
    for(int i=0;i<5;i++){
        printf("x%d = %lf\n",i+1,vet[i]);
    }
    return 0;
}
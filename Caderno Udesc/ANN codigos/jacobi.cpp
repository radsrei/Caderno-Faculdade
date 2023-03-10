#include <iostream>
using namespace std;




int main (void){
    float x1,x2,x3,x4,x5,x6,x7;
    float vet[7] = {-1.2,0.1,2.3,-4.6,-3.4,-0.6,-1.1};
    for (int i=0; i<10; i++){
        x1= (vet[1]*0.6  -vet[2]*2.5 -vet[3]*2.0 -vet[4]*2.9 -vet[6]*2.5 +vet[6]*0.2 -4.7)/12.2;
        x2= (-vet[0]*1.8 +vet[2]*1   -vet[3]*2.9 -vet[4]*1.9 -vet[5]*0.9 -vet[6]*2.3 -0.3)/11.2;
        x3= (vet[0]*2.9  -vet[1]*1.1 +vet[3]*0.8 +vet[4]*2.3 -vet[5]*0.9 +vet[6]*0.3-0.5)/11.9;
        x4= (-vet[0]*2.6 -vet[1]*1.4 -vet[2]*0.9 +vet[4]*1.4 +vet[5]*1.7 -vet[6]*1.2+2.5)/10;
        x5= (-vet[0]*1.8 +vet[1]*0.5 -vet[2]*1.5 -vet[3]*0.9 -vet[5]*2.6 +vet[6]*3+2.9)/12.1;
        x6= (vet[0]*2.4  -vet[1]*0.3 +vet[2]*1   -vet[3]*0.8 -vet[4]*0.2 -vet[6]*0.5+4.3)/9.7;
        x7= (-vet[0]*1.7 +vet[1]*2.7 -vet[2]*0.9 -vet[3]*1.8 +vet[4]*1   -vet[5]*2.6-4.2)/12.5;
        vet[0]=x1;
        vet[1]=x2;
        vet[2]=x3;
        vet[3]=x4;
        vet[4]=x5;
        vet[5]=x6;
        vet[6]=x7;
        //printf("\n%d %f%f%f%f%f%f%f",i+1,aux[0],aux[1],aux[2],aux[3],aux[4],aux[5],aux[6]);
    }
    for(int i=0;i<7;i++){
        printf("x%d = %f\n",i+1,vet[i]);
    }
    return 0;
}

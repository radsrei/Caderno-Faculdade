#include <iostream>
using namespace std;

float fx(float x);
float fxlinha(float x);


int main (void){
    float x;
    float xn;
    x = 1.517;
    float fxrest;
    float fxlinharest;
    int i;
    for(i=1;i<5;i++){
        fxrest = fx(x);
        fxlinharest = fxlinha(x);
        if(fxlinharest ==0){
            printf("Derivada de F(x) é zero\n");
            break;
        }
        xn = (x-(fxrest/fxlinharest));
        x = xn;
        printf("\tX%d = %f\n",i+1,xn);
    }
   
    
    return 0;
}


//x³ -4x -1
float fx(float x){
    float result;
    result = ((x*x*x) - 4*x - 1);
    return result;
}

//3x² -4
float fxlinha(float x){
    float result;
    result = ((3*(x*x)) -4);
    return result;
}
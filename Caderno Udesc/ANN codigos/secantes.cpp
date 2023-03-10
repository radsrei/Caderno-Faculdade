#include <iostream>
using namespace std;

double fx(double x);

int main (void){
    double xm;//x-1
    double x;//x
    double xn=0;//x+1


    double fdx;
    double fdxm;
    x = 0.13;
    xm = -0.878 ;

    int i;

    for (i=3;i<6;i++){
        fdxm = fx(xm);
        fdx = fx(x);
        xn = xm - (fdxm*((x-xm)/(fdx-fdxm)));
        printf("\tX%d = %.8f\n",i,xn);
        xm = x;
        x = xn;
        

    }

    return 0;
}


//x³ -4x -1
double fx(double x){
    double result=0;
    result = (x*x*x - 4*x - 1);
    printf("Para x=%f, F(x)=%f\n",x,result);
    return result;
}
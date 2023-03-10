#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double formula(double fdeh2, double fdeh,int i);

int main (void){
    int i,j;
    double fdex[7][7];
    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            fdex[i][j] =0;
        }
    }
    for (i=0;i<=7;i++){
        fdex[0][i] = 1/(pow(2,i));
    }
    fdex[1][0] = -0.6869511793;//1
    fdex[1][1] = -1.4640595308;//0.5
    fdex[1][2] = -1.2573273753;//0.25
    fdex[1][3] = -1.0809643444;//0.125
    fdex[1][4] = -0.9893460787;//0.0625
    fdex[1][5] = -0.9460979629;//0.03125
    fdex[1][6] = -0.9258733857;//0.015625
    // for(i=1;i<=6;i++){
    //     for(j=6;j<=1;j--){
    //         //fdex[i+1][j] = formula(fdex[i][j],fdex[i][j+1],i);
    //         fdex[i+1][j-1]= formula (fdex[i][j],fdex[i][j-1],i);
            
    //     }
    // }
    fdex[2][0] = formula (fdex[1][0],fdex[1][1],1);
    fdex[2][1] = formula (fdex[1][1],fdex[1][2],1);
    fdex[2][2] = formula (fdex[1][2],fdex[1][3],1);
    fdex[2][3] = formula (fdex[1][3],fdex[1][4],1);
    fdex[2][4] = formula (fdex[1][4],fdex[1][5],1);
    fdex[2][5] = formula (fdex[1][5],fdex[1][6],1);
    fdex[3][0] = formula (fdex[2][0],fdex[2][1],2);
    fdex[3][1] = formula (fdex[2][1],fdex[2][2],2);
    fdex[3][2] = formula (fdex[2][2],fdex[2][3],2);
    fdex[3][3] = formula (fdex[2][3],fdex[2][4],2);
    fdex[3][4] = formula (fdex[2][4],fdex[2][5],2);
    fdex[4][0] = formula (fdex[3][0],fdex[3][1],3);
    fdex[4][1] = formula (fdex[3][1],fdex[3][2],3);
    fdex[4][2] = formula (fdex[3][2],fdex[3][3],3);
    fdex[4][3] = formula (fdex[3][3],fdex[3][4],3);
    fdex[5][0] = formula (fdex[4][0],fdex[4][1],4);
    fdex[5][1] = formula (fdex[4][1],fdex[4][2],4);
    fdex[5][2] = formula (fdex[4][2],fdex[4][3],4);
    fdex[6][0] = formula (fdex[5][0],fdex[5][1],5);
    fdex[6][1] = formula (fdex[5][1],fdex[5][2],5);
    fdex[7][0] = formula (fdex[6][0],fdex[6][1],6);
    
    //  for(i=0;i<7;i++){
    //     for(j=0;j<7;j++){
    //          printf("%.10lf\n",fdex[i][j]);
    //   }
    // }


    printf("\n\n%.10lf\n\n",fdex[7][0]);
    
    return 0;
}

double formula(double fdeh, double fdeh2, int i){
    double result;
    double div;
    div = pow(2,i)-1;
    result = (pow(2,i)*fdeh2 - fdeh)/(div);
    return result;
}
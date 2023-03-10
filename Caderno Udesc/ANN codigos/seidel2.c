#include <stdio.h>
#include <math.h>
#define ERROR 0.001 // erro, precissao
#define N 5 // Tamanho da matriz (linhas do sistema linear)

void main (){
 int i, j;

    // Declara a matriz com os coeficientes e respostas
    float A[N][N]   = {{6.5, -1.1, +2.0,+2.8,-0.4},
                       {-0.1, 8.5, 1.6,-1.4,-1.8},
                       {2.5,-1.5, 8.7, -1.3,-1.6},
                       {2.5,1.7,-2.6,8.7,-1.8},
                       {2.5,-1.9,-2.7,-0.3,7.7}};

    // Declara matriz com os resultados
    float b[N][1]  = {{-2.9},
                      {-1.9},
                      {1.5},
                        {0},
                        {4.5}};

    // Declarar o vetor de chute inicial
    float x[N][1] = {{-0.6},
                     {1.9},
                     {0.8},
                     {0.6},
                     {3.0}};

    // Declara o vetor do x velho para calcular o erro
    float xAntigo[N][1] = {{0},
                          {0},
                          {0},
        {0}};

    // Declara bandeira que indica quando parar
    float xError[N][1] = {{0},
                        {0},
                        {0},
      {0}};

    // Erro que vai pra 1 quando todos os esrros forem no minimo menor que o ERROR
    int erro = 0;

    // Loop do metodo
    do {

        // Loop para
        for (i = 0; i < 10; i++) {
            float s = 0;

            // Calculando o somatorio do conjunto x das iterações
            //usando a regra de cramer
            for (j = 0; j < N; j++) {
                if (j != i)
                    s = s + A[i][j]*x[j][0];//lop para calcular o Ax
            }

            // Faz (bi - s) / Aii ser o x
            x[i][0] = ((b[i][0] - s)/ A[i][i]);//lop para calcular o B-somatorio / A

        }
        //criterio da convergencia
        for (i = 0; i<N; i++){
            xError[i][0] = (fabs((x[i][0]- xAntigo[i][0]) / x[i][0])) * 100;
            if (xError[i][0] >= ERROR){
                erro = 1;//erro como uma questão de parada
            }else{
                erro = 0;
            }
            xAntigo[i][0] = x[i][0];
        }
        // printf("\n");

        // for (i = 0; i <N; i++){
        //    printf("X%i = %f\n",i+1, x[i][0]);
        // }

    } while (erro != 0);
    for (i = 0; i <N; i++){
        printf("X%i = %f\n",i+1, x[i][0]);
    }
} 
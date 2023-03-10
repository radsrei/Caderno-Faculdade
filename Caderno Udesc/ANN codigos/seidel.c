#include <stdio.h>
#include <math.h>
#define ERROR 0.001 // erro, precissao
#define N 3 // Tamanho da matriz (linhas do sistema linear)

void main (){
 int i, j;

    // Declara a matriz com os coeficientes e respostas
    float A[N][N]   = {{3, -0.1, -0.2},
                       {0.1, 7, -0.3},
                       {0.3, -0.2, 10}};

    // Declara matriz com os resultados
    float b[N][1]  = {{7.85},
                      {-19.3},
                      {71.4},
       {15}};

    // Declarar o vetor de chute inicial
    float x[N][1] = {{0},
                     {0},
                     {0},
     {0}};

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
        for (i = 0; i < N; i++) {
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

        printf("\n");

        for (i = 0; i <N; i++){
           printf("X%i = %f\t |Er| = %f\n",i+1, x[i][0], xError[i][0]);
        }

    } while (erro != 0);
 
} 
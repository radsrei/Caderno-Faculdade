#include <stdlib.h> 
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t
#define RAD 1000


#define TAM 50 //constante para tamanho do vetor
clock_t t; //variável para armazenar tempo
int vetor[TAM]; //vetor com 10000 posições

// Função para calcular o tamanho do arquivo de entrada.
long calcularTamanhoArquivo(FILE *arquivo) {
    long posicaoAtual = ftell(arquivo);
    long tamanho;
    fseek(arquivo, 0, SEEK_END);
    tamanho = ftell(arquivo);
    fseek(arquivo, posicaoAtual, SEEK_SET);
    return tamanho;
}

// Função para calcular modulo exponencial 
unsigned long long moduloExponencial(unsigned long long base, unsigned long long exp, unsigned long long mod){
    unsigned long long x = 1;
    unsigned long long y = base;
    while (exp > 0){
      if (exp % 2 == 1)
        x = (x * y) % mod;
        y = (y * y) % mod;
        exp = exp/2;
      }
    return x % mod;
}

// Função para testar o primalidade por Teste de Miller
unsigned long long Miller(unsigned long long p,unsigned long long interacao){
  int i;
  unsigned long long s;
  if (p < 2){
    return 0;
  }
  if (p != 2 && p % 2==0){
    return 0;
  }  
  s = p - 1;   
  while (s % 2 == 0){
    s/= 2;
  }
  for (i = 0; i < interacao; i++){
    unsigned long long a = rand() % (p - 1) + 1, temp = s;
    unsigned long long mod = moduloExponencial(a, temp, p);
    while (temp != p - 1 && mod != 1 && mod != p - 1){
      mod = moduloExponencial(mod, mod, p);
      temp *= 2;
    }
    if (mod != p - 1 && temp % 2 == 0){
      return 0;
    }
  }
  return 1;
}

// Função euclides extendido
unsigned long long euclidesExtendido(unsigned long long a, unsigned long long b, unsigned long long *x, unsigned long long *y){
     // Base Case
    if (a == 0)
    {
        *x = 0; 
        *y = 1;
        return b;
    }
 
    unsigned long long  x1, y1; 
    unsigned long long gcd; 
    gcd = euclidesExtendido(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;

}

unsigned long long inversoModular(unsigned long long a, unsigned long long m){
  unsigned long long x, y;
  unsigned long long g;
  g = euclidesExtendido(a, m, &x, &y);
    if (g != 1){
        return -1;
    }else
    {
      x = (x % m + m) % m;
      return x;
    }
}


// Função para achar p e q por força bruta
void forcaBruta(unsigned long long e, unsigned long long n) {
   

   unsigned long long b; 
   unsigned long long a = ceil(sqrt(n));

   while(true) {  
      unsigned long long b1 = a * a - n;  
      b = (unsigned long long)sqrt(b1);
      if(b * b == b1)  
            break;  
      else
            a += 1;  
   }  

   printf("Primos que geraram as chaves públicas: %llu %llu ", (a - b), (a + b));

   return;  
}


int main() {
  unsigned long long falha,aux,p,q,n,e,aux2,aux3,d; 
  unsigned long long x,y,sub;
  falha = true;
  int i;
  t = clock(); 

  // criação da chave publica. 
  // Gera p primo
  srand(time(NULL));
  while (falha){
    aux = rand()%RAD;
    if (Miller(aux,5)){
      p = aux;
      falha = false;
    }else{
      falha = true;
    }
  }
  // Gera q primo
    falha = true;
    srand(time(NULL)); 
    while (falha){
    aux2 = rand()%RAD;
    //printf("%llu\n", aux);
    if (aux2 != aux){ 
      if (Miller(aux2,5)){
        q = aux2;
        falha = false;
      }else{
        falha = true;
      }
    }else{ 
        falha = true;
      } 
  }
  // Gera e (coprimo de p e q)
  falha = true; 
  sub = (q-1)*(p-1);
  srand(time(NULL));
  while (falha){
    aux3 = rand()%RAD;
    if (Miller(aux3,5)){
      e = aux3;
      if (euclidesExtendido(e,sub, &x, &y) == 1){
        falha = false;
      }else{
        falha = true;
      }
    }else{
      falha = true;
    }
  }
  // criação da chave privada
  n = p*q;
  d = inversoModular(e,sub);

  // escrevendo no arquivo
  long tamanho;
  int auxiliar;
  char c,k;
  unsigned long long t,h,desc;
  FILE *fp,*arquivo,*descrip; 
  fp = fopen ("a.txt", "r");
    if (fp == NULL) {
      printf ("Houve um erro ao abrir o arquivo.\n");
      return 1;
    }
    arquivo = fopen("arq01.txt","w");
    tamanho = calcularTamanhoArquivo(fp);
    descrip = fopen("descrip.txt","w");

    for (auxiliar = 0; auxiliar<tamanho;auxiliar++){
      c = fgetc(fp);
      t = c - '0';
      h = moduloExponencial(t, e, n);
      fprintf (arquivo, "%llu ", h);
      desc= moduloExponencial(h, d, n);
      k = desc + '0';
      fprintf (descrip, "%c", k);
    }
    
    fclose (arquivo);
    fclose (descrip);
   t = clock() - t;

  

   printf("Tempo de execucao criptografia e descriptografia: %lf \n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    t = clock(); 

    forcaBruta(e, n);
    
    t = clock() - t;
   printf("Tempo de execucao para decobrir chaves publicas por força bruta: %lf \n", ((double)t)/((CLOCKS_PER_SEC/1000)));



  return 0;
}

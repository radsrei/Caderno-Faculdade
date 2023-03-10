#include <stdlib.h> 
#include <math.h>
#include <stdio.h>
#include<stdbool.h>

long long mulmod(long long a, long long b, long long mod)
{
    long long x = 0,y = a % mod;
    while (b > 0)
        {
            if (b % 2 == 1)
                {
                    x = (x + y) % mod;
                }
            y = (y * 2) % mod;
            b/= 2;
        }
    return x % mod;
}

/*
 * modular exponentiation
 */
long long moduloExponencial(long long base, long long exp, long long mod){
    long long x = 1;
    long long y = base;
    while (exp > 0){
      if (exp % 2 == 1)
        x = (x * y) % mod;
        y = (y * y) % mod;
        exp = exp/2;
      }
    return x % mod;
}

/*
 * Miller-Rabin Primality test, iteration signifies the accuracy
 */
int Miller(long long p,int iteration){
  int i;
  long long s;
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
    
  for (i = 0; i < iteration; i++){
    long long a = rand() % (p - 1) + 1, temp = s;
    long long mod = moduloExponencial(a, temp, p);
    while (temp != p - 1 && mod != 1 && mod != p - 1){
      mod = mulmod(mod, mod, p);
      temp *= 2;
    }
    
    if (mod != p - 1 && temp % 2 == 0){
      return 0;
    }
  }
  
  return 1;
}

int extended_gcd(long long a, long long b, long long *x, long long *y){
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    long long _x, _y;
    long long gcd = extended_gcd(b % a, a, &_x, &_y);
 
    *x = _y - (b/a) * _x;
    *y = _x;
 
    return gcd;
}






int main() {
  long long falha,aux,p,q,n,e; 
  long long x,y,sub;
  falha = true;

  while (falha){
  aux = rand()%100;
  if (Miller(aux,5)){
    p = aux;
    falha = false;
  }else{
    falha = true;
  }
  }

  falha = true;

  while (falha){
  aux = rand()%1000;
  if (Miller(aux,5)){
    q = aux;
    falha = false;
  }else{
    falha = true;
  }
  }
  
  falha = true; 
  sub = (q-1)*(p-1);
  while (falha){
  aux = rand()%100;
  if (Miller(aux,5)){
    e = aux;
    if (extended_gcd(e,sub, &x, &y) == 1){
      falha = false;
    }else{
      falha = true;
    }
  }else{
    falha = true;
  }
  }

  
  int i;
  n = q*p;
  long long M[] ={01001000,01100101, 01101100, 01101100, 01101111, 00100000, 01010111, 01101111, 01110010, 01101100, 01100100,};

  long long crip[10];
  for (i = 0; i < 11; i++){
      crip[i] = moduloExponencial(M[i], e, n);
  }

  for (i = 0; i < 11; i++){
      printf("%lld \n", crip[i]);
  }

  return 0;
}


/*
Nosso trabalho foi implementado em C, e dividido em funções

- primeiramente geramos avalores
  randomicos para P e Q, e verificamos se ele é primo com um algoritmo baseado no Teste de Primaridade de Miller

- Apos geramos um E que é co primo de P e Q, para verificar se ele é co primo usamos o algoritmo de Euclides Estendido

- A chave publica é gerada com os valores de E e N, onde E é o co primo de P e Q e N é valor da multiplicação de P e Q

- Para a chave privada foi necessario calcular o D, o D é o inverso Modular, criamos uma funcao de inverso modular com o auxilio da funcao de Euclides Estendido

- A chave privada é gerada com o valor de D, e o valor de N

- Tanto para a criptografia e descriptografia usamos o algoritmo de potencia modular

*/
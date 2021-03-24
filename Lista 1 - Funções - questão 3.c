#include <stdio.h>
#include <stdlib.h>

//* Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial
//* deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve
//* de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do
//* usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial.

  int fatorial(int x){

      if(x==0 || x==1)
      return 1;

    else
        return x*fatorial(x-1);

 }

  void main(){

    int n, fat;

    printf("digite um numero: \n");
    scanf("%d", &n);

    fat=fatorial(n);

    printf("o fatorial eh: %d", fat);
  }

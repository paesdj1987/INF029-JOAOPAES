#include <stdio.h>
#include <stdlib.h>

//* Fa�a um programa que tenha uma fun��o que recebe um n�mero inteiro e retorna o fatorial
//* deste n�mero. Esta fun��o deve ainda verificar se � poss�vel calcular o fatorial, se n�o for, ela deve
//* de alguma forma retornar para a main que deu algum erro. A fun��o main deve solicitar o valor do
//* usu�rio e imprimir o fatorial dele, ou se n�o � poss�vel calcular o fatorial.

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

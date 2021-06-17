#include <stdio.h>
#include <stdlib.h>

#include "arquivo_headers.h"

int main()
{
   int num, soma;

   printf("insira um numero maior que 1: \n");
   scanf("%d", &num);

   soma=somatorio(num);

   printf("o somatorio eh: %d \n", soma);

   return 0;
}

int somatorio (int n){

    int i;

    if(n<=0)
        return n;
    else
        return n + somatorio(n-1);

}


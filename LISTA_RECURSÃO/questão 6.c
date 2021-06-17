#include <stdio.h>
#include <stdlib.h>

#include "arquivo_headers.h"

int main()
{

   int base, expoente, pot;


   printf("digite a base: \n");
   scanf("%d", &base);

   printf("digite a expoente: \n");
   scanf("%d", &expoente);

   pot= potencia(base, expoente);

   printf("potencia: %d\n", pot);

   return 0;
}

int potencia (int k, int n){ //k=base, n=expoente, i=contador



    if(n<1){
        return 1;
    }
    return k*potencia(k, n-1);

}


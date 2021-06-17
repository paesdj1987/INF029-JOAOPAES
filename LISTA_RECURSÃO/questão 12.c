#include <stdio.h>
#include <stdlib.h>

#include "arquivo_headers.h"



int main (){

   int a=10, b=0;

   crescente(a,b);

   return 0;
}

int crescente(int a, int b){

       printf("%d\n", b);

       if (a>b){

           return crescente(a, b+1);

       }

   }

#include <stdio.h>
#include <stdlib.h>

#include "arquivo_headers.h"

int main (){

   int a=10, b=0;

   crescentepar(a,b);

   return 0;
}

int crescentepar(int a, int b){

       printf("%d\n", b);

       if ((a>b)&&(a%2==0)){
           return crescentepar(a, b+2);
       }

   }

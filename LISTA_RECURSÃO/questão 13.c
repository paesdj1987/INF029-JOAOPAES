#include <stdio.h>
#include <stdlib.h>

#include "arquivo_headers.h"

int main (){

   int num=10;

   decrescente(num);
}

void decrescente(int a){

       printf("%d\n", a);

       if (a>0){

           return decrescente(a-1);

       }

       else {

           return 0 ;

       }

   }

#include <stdio.h>
#include <stdlib.h>

#include "arquivo_headers.h"

int main (){

   int num=10;

   decrescentepar(num);
}

void decrescentepar(int a){

       printf("%d\n", a);

       if ((a>0)&&(a%2==0)){

           return decrescentepar(a-2);

       }

       else {

           return 0 ;

       }

   }

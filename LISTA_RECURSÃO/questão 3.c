#include <stdio.h>
#include <stdlib.h>

#include "arquivo_headers.h"

int main()
{

   int x, invert;

   printf("escreva um numero com ate 3 algarismo: \n");
   scanf("%d", &x);


   invert = inverterNumero(x);



   return 0;
}

int inverterNumero(int num) {

	if(num==0){
      return num;
    }
    else
    {
        printf("%d", num % 10);
        num=num / 10;
        return inverterNumero(num);
    }


}

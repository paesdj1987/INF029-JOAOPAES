#include <stdio.h>
#include <stdlib.h>

#include "arquivo_headers.h"



int main()
{
   int n=9,i;

   printf("\n A sequência de Fibonacci eh: \n");

   for(i=0; i<n; i++)
       printf("%d \n", fibonacci(i+1));
    getch();

       return 0;
}

int fibonacci (int n){

    if (n==1 || n==2)
        return 1;
    else
    {
     return fibonacci(n-1)+(n-2);
    }


}

#include <stdio.h>
#include <stdlib.h>


#include "arquivo_headers.h"

int main()
{
   int vet[8] = {5, 10, 15, 20, 25, 30, 35, 40};


   saida(vet, 8);
   printf("\n");
   invertVetor(vet, 0, 7);
   printf("\n");
   saida(vet, 8);

   return 0;
}


void invertVetor(int vet[], int x, int y){

    int aux;

    if(x<y){

        aux=vet[x];
        vet[x]=vet[y];
        vet[y]=aux;
        invertVetor(vet, x+1, y-1);
    }

}

void saida(int vet[], int a){

    if (a == 1){
        printf("%d \n", vet[a-1]);
        }
    else
    {
        saida(vet, a-1);
        printf("%d \n", vet[a-1]);
    }

}

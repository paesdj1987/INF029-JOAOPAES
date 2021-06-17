#include <stdio.h>
#include <stdlib.h>

#include "arquivo_headers.h"



int main()
{
    int vet[5] = {5, 10, 15, 20, 25};
    printf("Soma: %d \n", somaNumero(vet, 5));

    return 0;
}

int somaNumero (int vet[], int tam){

    if(tam==0)
        return 0;
    else
        return vet[tam-1]+somaNumero(vet, tam-1);

}



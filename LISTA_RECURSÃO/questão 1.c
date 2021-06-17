#include <stdio.h>
#include <stdlib.h>


#include "arquivo_headers.h"



int main(){

    int num;
    double valorFat;

    printf("digite um numero: \n");
    scanf("%d", &num);

    valorFat=fatorial(num);

    printf("Fatorial de %d = %.1f \n", num, valorFat);

    return 0;
}

double fatorial(int num){

    double fat;

    if(num<=1)
        return 1;
    else
    {
        fat=num*fatorial(num-1);
        return (fat);
    }

}

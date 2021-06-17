#include <stdio.h>
#include <stdlib.h>

#include "arquivo_headers.h"

int main(){

    int result, valor;

    printf("insira um num: \n");
    scanf("%d", &valor);

    result = somaN(valor);

    printf("o valor do somatorio eh: %d", result);

}

int somaN(int num){

    if(num==0)
        return 0;
    else
    {
        return num + somaN(num-1);
    }

}

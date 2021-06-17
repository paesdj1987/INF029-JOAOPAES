#include <stdio.h>
#include <stdlib.h>

#include "arquivo_headers.h"


int main(){

    int result;
    int num;
    int k;

    printf("num: \n");
    scanf("%d", &num);

    printf("num que sera avaliado: \n");
    scanf("%d", &k);

    result = repet(num, k);

    printf("O numero foi repetido %d vezes \n", result);

}


int repet(int num, int k){

    if (num==0)
        return 0;
    else
    {
        return repet(num/10, k)+(num%10==k);
    }

}


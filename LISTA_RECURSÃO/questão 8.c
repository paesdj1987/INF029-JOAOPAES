#include <stdio.h>
#include <stdlib.h>

#include "arquivo_headers.h"

int main(){

    int n1, n2, result;

    printf("insira um num: \n");
    scanf("%d", &n1);

    printf("insira um outro num: \n");
    scanf("%d", &n2);

    result = mdc(n1, n2);

    printf("\n %d \n", result);

}

int mdc(int x, int y){

    if (x%y == 0){
        return y;
    }
    else
    {
        return mdc(y,x % y);
    }
}

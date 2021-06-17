#include <stdio.h>
#include <stdlib.h>

#include "arquivo_headers.h"

int main(){

    int a=5, b=4;
    int result;

    result=multi(a,b);

    printf("A o resultado da multiplicacao eh: %d\n", result);


}

int multi(int x, int y){

    if(y==1)
        return x;
    else
    {
        return x+multi(x, --y);
    }

}

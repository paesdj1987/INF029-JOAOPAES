#include <stdio.h>
#include <stdlib.h>

//* Crie um programa que tenha uma fun��o subtrai e a fun��o main. A fun��o main deve ler tr�s
//* valores, enviar para a fun��o subtrai. A fun��o subtrai deve realizar a subtra��o dos tr�s valores
//* (primeiro menos o segundo menos o terceiro) e retornar o valor. A Fun��o main deve imprimir o
//* resultado da subtra��o.

int subtrai(int x , int y, int z){

    int subtrai=x-y-z;
    return subtrai;
}


void main(){

    int num1, num2, num3, vsub;

    printf("informe um numero: \n");
    scanf("%d", &num1);

    printf("informe outro numero: \n");
    scanf("%d", &num2);

    printf("informe outro numero: \n");
    scanf("%d", &num3);

    vsub=subtrai(num1,num2,num3);

    printf("o resultado eh: %d", vsub);


}


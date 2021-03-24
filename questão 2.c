#include <stdio.h>
#include <stdlib.h>

//* Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três
//* valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores
//* (primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o
//* resultado da subtração.

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


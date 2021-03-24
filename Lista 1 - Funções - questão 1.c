#include <stdio.h>
#include <stdlib.h>

//* Crie um programa que tenha uma função soma e a função main. A função main deve ler dois
//* valores, enviar para a função soma. A função soma deve realizar a soma e retornar o valor.
//* A Função main deve imprimir o resultado da soma.

int soma(int x , int y){

    int soma=x+y;
    return soma;
}


void main(){

    int num1, num2, vsoma;

    printf("informe um numero: \n");
    scanf("%d", &num1);

    printf("informe outro numero: \n");
    scanf("%d", &num2);

    vsoma= soma(num1, num2);

    printf("o valor da soma eh: %d \n", vsoma);


}

#include <stdio.h>
#include <stdlib.h>

//* Crie um programa que tenha uma fun��o soma e a fun��o main. A fun��o main deve ler dois
//* valores, enviar para a fun��o soma. A fun��o soma deve realizar a soma e retornar o valor.
//* A Fun��o main deve imprimir o resultado da soma.

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

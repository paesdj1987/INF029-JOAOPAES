#include <stdio.h>
#include <stdlib.h>

//* Crie um programa que tenha uma fun��o ler4Numeros. Essa fun��o deve ler quatro n�meros do
//* usu�rio e retornar os quatro n�meros. A fun��o main deve imprimir esses quatro n�meros. Utilize
//*  struct para fazer o retorno.

struct quatroNum {

    int n;
};

void ler4Numeros(struct quatroNum *x, int y) {

    int i;
    y=4;
    for(i=0; i<4; i++){
        printf("%d \n", x[i]);
    }

        return;
}
int main () {

    int a[4];

    printf("digite num1: \n");
    scanf("%d", &a[0]);

    printf("digite num1: \n");
    scanf("%d", &a[1]);

    printf("digite num1: \n");
    scanf("%d", &a[2]);

    printf("digite num1: \n");
    scanf("%d", &a[3]);




    ler4Numeros(a, 4);


}

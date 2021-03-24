#include <stdio.h>
#include <stdlib.h>

//* Crie um programa que tenha uma função ler4Numeros. Essa função deve ler quatro números do
//* usuário e retornar os quatro números. A função main deve imprimir esses quatro números. Utilize
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

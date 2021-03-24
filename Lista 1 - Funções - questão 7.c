#include <stdio.h>
#include <stdlib.h>

//* Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do
//* usuário e retornar as três palavras. A função main deve imprimir essas três palavras.

void ler3palavras(char a[][30]) {

    int i;

    for(i=0; i<3; i++){

        printf("%s \n", a[i]);

    }

}
int main () {


    char x[3][30];

    for (int i = 0; i< 3; i++)
    {
    printf("\n insira a palavra: \n");
    scanf("%s", &x[i][0]);
    }
    ler3palavras(x);

return 0;
}

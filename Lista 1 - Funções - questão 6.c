#include <stdio.h>
#include <stdlib.h>

void ler3Letras(char a[][3]) {

    int i;

    for(i=0; i<3; i++){

        printf("%s", a[i]);

    }


}
int main () {


    char x[3][3];

    for (int i = 0; i< 3; i++)
    {
    printf("\n insira a letra: \n");
    scanf("%s", &x[i][0]);
    }
    ler3Letras(x);

return 0;
}


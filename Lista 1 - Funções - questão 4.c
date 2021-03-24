#include <stdio.h>
#include <stdlib.h>

void ler3numeros(int *x, int y){
	
	int i;
	y=3;
	for (i=0; i<y; i++)
	
		printf("%d \n", x[i]);
return;	
}

int main () {

    int vetor[3];
    int i, z;
    
    z=3;
    
    for(i=0; i<z; i++)
    {
    printf("insira num1:  \n");
    scanf("%d", &vetor[i]);
    
    }
    
    ler3numeros(vetor, z);

}


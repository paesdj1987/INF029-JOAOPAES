#include <stdio.h>
#include <stdlib.h>

int main(){

	int a, b, op = 1;
	double resultado;

	for(;;){
		printf("Digite o primeiro valor\n");
		scanf("%d", &a);
		printf("Digite o segundo valor\n");
		scanf("%d", &b);

		printf("Digite a opera��o\n0 - Sair\n1 - Somar\n2- Subtrair\n3- Multiplicar\n4-Dividir\n");
		scanf("%d", &op);
		switch (op){
			case 0:{
				printf("Sair\n");
				break;
			}
			case 1:{
				resultado = a + b;
				printf("Resultado = %f\n", resultado);
				break;
			}
			case 2:{
				resultado = a - b;
				printf("Resultado = %f\n", resultado);
				break;
			}
			case 3:{
				resultado = a * b;
				printf("Resultado = %f\n", resultado);
				break;
			}
			case 4:{
				if (b == 0){
					printf("N�o � poss�vel dividir por 0\n");
				}else{
					resultado = a / b;
					printf("Resultado = %f\n", resultado);
				}
				break;
			}
			default: printf("Op��o inv�lida\n");
		}

		if (op == 0) break;

	}

}








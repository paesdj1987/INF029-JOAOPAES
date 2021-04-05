#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/** Versão 1 do projeto escola **/


typedef struct {
    int ano, mes, dia;

}dma;

typedef struct {

    dma dataN;
    char cpf[15];
    int mat;
    char nome[100];
    char sexo[1];

}Aluno;



int main () {

    int op_principal;
    int qtdAluno=0;
    int i;
    int idade;
    int sair=0;
    Aluno aluno;
    Aluno list_aluno[5];

    while(!sair){

    printf("*** Bem Vindo Ao Sistema Escolar AZX - Menu Inicial *** \n");
    printf("\n 1 - Inserir Aluno \n");
    printf("\n 2 - Listar relacao de Alunos \n");
    printf("\n 3 - Sair do Programa \n");

    printf("\n Digite a opcao desejada: \n");
    scanf("%d", &op_principal);


    switch (op_principal) {

        case 1: {

            printf("Menu 1 - Inserir Aluno \n");

            printf("\n Digite nome: \n");
            fgets(list_aluno[qtdAluno].nome,100,stdin);

            size_t ln = strlen(list_aluno[qtdAluno].nome) - 1;
            if (list_aluno[qtdAluno].nome[ln] == '\n')
            list_aluno[qtdAluno].nome[ln] = '\0';

            printf("\n Digite a matricula: \n");
            scanf("%d", &list_aluno[qtdAluno].mat);

            printf("\n Digite o sexo: \n");
            scanf("%c", &list_aluno[qtdAluno].sexo);

            printf("\n Digite a idade no formato ** xx/xx/xxxx **\n");
            scanf("%d",&idade);

            list_aluno[qtdAluno].dataN.dia = idade / 1000000;
            list_aluno[qtdAluno].dataN.mes = idade % 1000000 / 10000;
            list_aluno[qtdAluno].dataN.ano = idade % 1000000 % 10000;

            printf("\n Digite o CPF: \n");
            fgets(list_aluno[qtdAluno].cpf, 15 , stdin);
            getchar();

            qtdAluno++;

        }

        case 2: {

            printf("Em construcao \n");

        }

        case 3:{
        printf("Finalizando programa \n");
        break;
        }



    }


    }


return 0;
}







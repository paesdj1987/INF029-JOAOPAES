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
            fgets(list_aluno[qtdAluno].nome, 100, stdin);

            printf("\n Digite a matricula: \n");
            scanf("%d", &list_aluno[qtdAluno].mat);
            getchar();

            printf("\n Digite o sexo: \n");
            scanf("%c", &list_aluno[qtdAluno].sexo);

            printf("\n Digite a idade no formato dia/mes/ano \n");
            scanf("%d",&idade);
            getchar();

            list_aluno[qtdAluno].dataN.dia = idade / 1000000;
            list_aluno[qtdAluno].dataN.mes = idade % 1000000 / 10000;
            list_aluno[qtdAluno].dataN.ano = idade % 1000000 % 10000;


            printf("\n Digite o CPF: \n");
            fgets(list_aluno[qtdAluno].cpf, 15 , stdin);
            getchar();


            qtdAluno++;

            break;

        }

        case 2: {

        printf("Menu 2 - Listagem de Alunos \n");

        for(i = 0; i < qtdAluno; i++){

            printf("Nome: %s\n",list_aluno[i].nome);
            printf("Matricula: %d\n",list_aluno[i].mat);
            printf("Sexo: %c\n",list_aluno[i].sexo);
            printf("Data de Nascimento %d/%d/%d\n",list_aluno[i].dataN.dia, list_aluno[i].dataN.mes, list_aluno[i].dataN.ano);
            printf("CPF: %s\n",list_aluno[i].cpf);
            }

        break;

        }

        case 3:{

        printf("Finalizando programa \n");
        sair=1;
        break;

        }

        default: {
            printf("opcao invalida \n");
        }


    }


    }


return 0;
}








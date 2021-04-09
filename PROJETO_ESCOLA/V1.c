#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/** Versão 1 do projeto escola **/


typedef struct {
    int ano, mes, dia;

}dma;

typedef struct {

    dma dataN;
    char cpf[15];
    int mat;
    char nm[50];
    char sexo[1];

}Aluno;



int main () {

    int op_principal;
    int qtdAluno=0;
    int i;
    int idade=0;
    int sair=0;
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

            printf("\n### Cadastro de Aluno ###\n");

            printf("Digite a matricula: \n");
            scanf("%d", &list_aluno[qtdAluno].mat);
            getchar();

            printf("Digite o sexo - m-> masculinho e f-> feminino: \n");
            scanf("%c", list_aluno[qtdAluno].sexo);

            printf("Digite o dia de nascimento: \n");
            scanf("%d", &list_aluno[qtdAluno].dataN.dia);

            printf("Digite o mes de nascimento: \n");
            scanf("%d", &list_aluno[qtdAluno].dataN.mes);

            printf("Digite o ano de nascimento: \n");
            scanf("%d", &list_aluno[qtdAluno].dataN.ano);
            getchar();

            printf("Digite o nome: \n");
            fgets(list_aluno[qtdAluno].nm, 50, stdin);

            size_t ln = strlen(list_aluno[qtdAluno].nm) - 1;
            if (list_aluno[qtdAluno].nm[ln] == '\n');
            list_aluno[qtdAluno].nm[ln] = '\0';

            printf("Digite o CPF: \n");
            fgets(list_aluno[qtdAluno].cpf, 15, stdin);
            ln = strlen(list_aluno[qtdAluno].cpf) - 1;
            if (list_aluno[qtdAluno].cpf[ln] == '\n'){
                list_aluno[qtdAluno].cpf[ln] = '\0';
            }


            qtdAluno++;

            printf("\n");

            break;

        }

        case 2: {

            printf("Menu 2 - Listagem de Alunos \n");

            for(i = 0; i < qtdAluno; i++){

                printf("Nome: %s \n",list_aluno[i].nm);
                printf("Matricula: %d \n",list_aluno[i].mat);
                printf("Sexo: %c \n",list_aluno[i].sexo);
                printf("Data de Nascimento %d/%d/%d \n",list_aluno[i].dataN.dia, list_aluno[i].dataN.mes, list_aluno[i].dataN.ano);
                printf("CPF: %s \n",list_aluno[i].cpf);
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













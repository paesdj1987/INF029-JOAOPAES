#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM_LISTA_ALUNO 5
#define CADASTRO_OK 1
#define CADASTRO_ERRO_MAT 2
#define CADASTRO_ERRO_SEX 3



/** Versão 2 do projeto escola **/


typedef struct datanas{
    int ano, mes, dia;

}dma;

typedef struct ficha_aluno{

    dma dataN;
    char cpf[15];
    int mat;
    char nome[50];
    char sexo;

}Aluno;


/* Declaração de Funções - AQUI */

int menuAluno();
int inserirAluno(Aluno list_aluno[], int qtdAluno);
void listarAluno(Aluno list_aluno[], int qtdAluno);


int main () {


    Aluno list_aluno[TAM_LISTA_ALUNO];

    int opcAluno;
    int retAluno;

    int qtdAluno=0;

    int sair=0;


    while(!sair){

    opcAluno = menuAluno();

    switch (opcAluno){

        case 1:{

            retAluno = inserirAluno(list_aluno, qtdAluno);

            if(retAluno==CADASTRO_OK){
                printf("Cadastro realizado com sucesso! \n");
                qtdAluno++;
            }
            else {

                if (retAluno==CADASTRO_ERRO_MAT){
                    printf("Matricula invalida. \n");
                }
                else
                {
                    if (retAluno==CADASTRO_ERRO_SEX){
                         printf("Sexo invalido. \n");
                    }
                    else
                    {
                        printf("Erro no cadastro! \n");
                    }

                }

            }

            break;
        }

        case 2:{
            listarAluno(list_aluno, qtdAluno);
            break;
        }

        case 3:{
            printf("Saindo do programa \n");
            sair=1;
            break;
        }


        default: {
                printf("opcao invalida \n");
        }


      }


    }


return 1;
}


/*  Funções criadas para atender ao programa */


int menuAluno() {

    int op_menuAluno;

    printf(" *** Bem Vindo Ao Sistema Escolar AZX - Menu Aluno *** \n");
    printf("\n 1 - Inserir \n");
    printf("\n 2 - Listar Relacao \n");
    printf("\n 3 - Sair do Programa \n");

    printf("\n Digite a opcao desejada: \n");
    scanf("%d", &op_menuAluno);

    return op_menuAluno;
}

int inserirAluno(Aluno list_aluno[], int qtdAluno){

            int dataNasc;

            printf("\n*** Menu 1 - Inserir ***\n");

            printf("\n Digite a matricula: \n");
            scanf("%d", &list_aluno[qtdAluno].mat);
            getchar();

            if(list_aluno[qtdAluno].mat==0) {
                return CADASTRO_ERRO_MAT;
            }

            printf("\n Digite o sexo: \n");
            scanf("%c", &list_aluno[qtdAluno].sexo);

            list_aluno[qtdAluno].sexo=toupper(list_aluno[qtdAluno].sexo);

            if (list_aluno[qtdAluno].sexo != 'M' && list_aluno[qtdAluno].sexo != 'F') {
                return CADASTRO_ERRO_SEX;
            }

            printf("\n Informe a idade no formato dd/dd/dddd: \n");
            scanf("%d", &dataNasc);
            getchar();

            list_aluno[qtdAluno].dataN.dia = dataNasc / 1000000;
            list_aluno[qtdAluno].dataN.mes = dataNasc % 1000000 / 10000;
            list_aluno[qtdAluno].dataN.ano = dataNasc % 1000000 % 10000;


            printf("\n Digite o nome: \n");
            fgets(list_aluno[qtdAluno].nome, 50, stdin);

            size_t ln = strlen(list_aluno[qtdAluno].nome) - 1;
            if (list_aluno[qtdAluno].nome[ln] == '\n')
            list_aluno[qtdAluno].nome[ln] = '\0';

            printf("\n Digite o CPF: \n");
            fgets(list_aluno[qtdAluno].cpf, 15, stdin);
            ln = strlen(list_aluno[qtdAluno].cpf) - 1;
            if (list_aluno[qtdAluno].cpf[ln] == '\n'){
                list_aluno[qtdAluno].cpf[ln] = '\0';
            }

            printf("\n");

            return CADASTRO_OK;

}

void listarAluno(Aluno list_aluno[], int qtdAluno){

            printf("\n*** Menu 2 - Listar Relacao***\n");
            int i;

            for(i = 0; i < qtdAluno; i++){

                printf("\n Nome: %s \n",list_aluno[i].nome);
                printf("\n Matricula: %d \n",list_aluno[i].mat);
                printf("\n Sexo: %c \n",list_aluno[i].sexo);
                printf("\n Data de Nascimento %d/%d/%d \n",list_aluno[i].dataN.dia, list_aluno[i].dataN.mes, list_aluno[i].dataN.ano);
                printf("\n CPF: %s \n",list_aluno[i].cpf);
                }

                printf("\n");

}




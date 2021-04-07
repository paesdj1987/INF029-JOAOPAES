#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM_LISTA_ALUNO 5
#define CADASTRO_OK 1
#define CADASTRO_ERRO_MAT 2
#define CADASTRO_ERRO_SEX 2


/** Versão 2 do projeto escola **/


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


/* Declaração de Funções - AQUI */

int menu_Aluno();
int inserirAluno(Aluno list_aluno[], int qtdAluno);
void listarAluno(Aluno list_aluno[], int qtdAluno);;


int main () {

    Aluno aluno;
    Aluno list_aluno[TAM_LISTA_ALUNO];

    int op1;
    int qtdAluno=0;
    int voltaOp1;
    int i;
    int sair=0;


    while(!sair){

    op1 = op_menuAluno();

    switch (op1) {

        case 1:{

            voltaOp1 = inserirAluno(list_aluno, qtdAluno);

            if(voltaOp1==CADASTRO_OK){

                printf("cadastro realizado com sucesso!!! \n");
                qtdAluno++;
            }
            else{

                switch (voltaOp1){

                    case CADASTRO_ERRO_MAT:{
                        printf("Numero de Matricula com erro. \n");
                        break;
                    }
                    case CADASTRO_ERRO_SEX:{
                        printf("Sexo invalido. \n");
                        break;
                    }
                    default: {
                        printf("Erro nao reconhecido. \n");
                    }

                }

                printf("Erro no cadastro! \n");
            }
            break;
        }

        case 2:{

            listarAluno(list_aluno, qtdAluno);
            break;
        }


        default: {
                printf("opcao invalida \n");
        }


      }


    }


return 0;
}


/*  Funções criadas para atender ao programa */


int menu_Aluno() {

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

            printf("\n### Cadastro - Pessoal ###\n");

            printf("\n Digite a matricula: \n");
            scanf("%d", &list_aluno[qtdAluno].mat);
            getchar();

            if(list_aluno[qtdAluno].mat==0) {
                return CADASTRO_ERRO_MAT;
            }

            printf("\n Digite o sexo - M-> masculinho e F-> feminino: \n");
            scanf("%c", list_aluno[qtdAluno].sexo);

            list_aluno[qtdAluno].sexo = toupper(list_aluno[qtdAluno].sexo);

            if ((list_aluno[qtdAluno].sexo != 'F') && (list_aluno[qtdAluno].sexo != 'M')) {
                return CADASTRO_ERRO_SEX;
            }

            printf("\n Digite o dia de nascimento: \n");
            scanf("%d", &list_aluno[qtdAluno].dataN.dia);

            printf("\n Digite o mes de nascimento: \n");
            scanf("%d", &list_aluno[qtdAluno].dataN.mes);

            printf("\n Digite o ano de nascimento: \n");
            scanf("%d", &list_aluno[qtdAluno].dataN.ano);
            getchar();

            printf("\n Digite o nome: \n");
            fgets(list_aluno[qtdAluno].nm, 50, stdin);

            size_t ln = strlen(list_aluno[qtdAluno].nm) - 1;
            if (list_aluno[qtdAluno].nm[ln] == '\n');
            list_aluno[qtdAluno].nm[ln] = '\0';

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

            printf("Menu 2 - Listagem de Alunos \n");
            int i;

            for(i = 0; i < qtdAluno; i++){

                printf("Nome: %s \n",list_aluno[i].nm);
                printf("Matricula: %d \n",list_aluno[i].mat);
                printf("Sexo: %c \n",list_aluno[i].sexo);
                printf("Data de Nascimento %d/%d/%d \n",list_aluno[i].dataN.dia, list_aluno[i].dataN.mes, list_aluno[i].dataN.ano);
                printf("CPF: %s \n",list_aluno[i].cpf);
                }

                printf("\n");

}




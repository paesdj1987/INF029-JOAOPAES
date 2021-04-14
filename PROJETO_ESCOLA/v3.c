#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM_LISTA_ALUNO 5
#define TAM_LISTA_PROFESSOR 5
#define CADASTRO_OK 1
#define CADASTRO_ERRO_MAT 2
#define CADASTRO_ERRO_SEX 3



/** Versão final do projeto escola **/


typedef struct datanas{
    int ano, mes, dia;

}dma;

typedef struct ficha_pessoa{

    dma dataN;
    char cpf[15];
    int mat;
    char nome[50];
    char sexo;

}Pessoa;


/* Declaração de Funções - AQUI */

int menuAluno();
int menuPrincipal();
int menuProfessor();
int inserirAluno();
int inserirProfessor();
void listarAluno();
void listarProfessor();


int main (void) {


    Pessoa list_aluno[TAM_LISTA_ALUNO];
    Pessoa list_professor[TAM_LISTA_PROFESSOR];

    int opcPrincipal, opcAluno, opcProfessor;
    int retAluno, retProfessor;


    int qtdAluno=0, qtdProfessor=0;

    int sair=0;


    while(!sair){

    opcPrincipal = menuPrincipal();

    switch (opcPrincipal){

            case 1:{         // Menu Aluno


                    opcAluno = menuAluno();

                        switch (opcAluno){

                            case 1:{          // Inserir aluno

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

                            case 2:{  // Listar aluno
                                    listarAluno(list_aluno, qtdAluno);
                                    break;
                                }

                            case 5:{  // Voltar
                                    opcPrincipal = menuPrincipal();
                                    break;
                                }

                            default: {
                                    printf("opcao invalida \n");
                                    break;
                                }


                                }

                      }
            case 2:{       // Menu professor

                opcProfessor = menuProfessor();

                        switch (opcProfessor){

                            case 1:{          // Inserir professor

                                retProfessor = inserirProfessor(list_professor, qtdProfessor);

                                if(retProfessor==CADASTRO_OK){
                                    printf("Cadastro realizado com sucesso! \n");
                                    qtdProfessor++;
                                }
                                else {

                                    if (retProfessor==CADASTRO_ERRO_MAT){
                                        printf("Matricula invalida. \n");
                                    }

                                    else
                                    {
                                        if (retProfessor==CADASTRO_ERRO_SEX){
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

                            case 2:{  // Listar professor
                                    listarProfessor(list_professor, qtdProfessor);
                                    break;
                                }

                            case 5:{  // Voltar
                                    opcPrincipal = menuPrincipal();
                                    break;
                                }

                            default: {
                                    printf("opcao invalida \n");
                                    break;
                                }


                                }

            }

            case 4:{       // Sair
                printf("Saindo do programa \n");
                sair=1;
                break;
            }

            default:{
                printf("Opcao invalida \n");
                break;
            }

    }

 }

    return 1;
}


/*  Funções criadas para atender ao programa */

int menuPrincipal(){

	int op_Principal;

	printf("\n *** Bem Vindo Ao Sistema Escolar AZX *** \n");
	printf("\n 1 - Aluno\n");
	printf("\n 2 - Professor\n");
	printf("\n 3 - Disciplina\n");
	printf("\n 4 - Sair \n");

	printf("Digite a sua opcao\n");
	scanf("%d",&op_Principal);

	return op_Principal;

}


int menuAluno() {

    int op_menuAluno;

    printf("\n *** Bem Vindo Ao Sistema Escolar AZX - Menu Aluno *** \n");
    printf("\n 1 - Inserir Aluno \n");
    printf("\n 2 - Listar Relacao Aluno \n");
    printf("\n 3 - Consultar Aluno \n");
    printf("\n 4 - Apagar Aluno \n");
    printf("\n 5 - Voltar \n");

    printf("\n Digite a opcao desejada: \n");
    scanf("%d", &op_menuAluno);

    return op_menuAluno;
}

int menuProfessor() {

    int op_menuProfessor;

    printf("\n *** Bem Vindo Ao Sistema Escolar AZX - Menu Professor *** \n");
    printf("\n 1 - Inserir Professor \n");
    printf("\n 2 - Listar Relacao Professor \n");
    printf("\n 3 - Consultar Professor\n");
    printf("\n 4 - Apagar Professor\n");
    printf("\n 5 - Voltar \n");

    printf("\n Digite a opcao desejada: \n");
    scanf("%d", &op_menuProfessor);

    return op_menuProfessor;
}

int inserirAluno(Pessoa list_aluno[], int qtdAluno){


            printf("\n*** Menu 1 - Inserir ***\n");

            printf("\n Digite a matricula de aluno: \n");
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

            int dataNasc;

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

int inserirProfessor(Pessoa list_professor[], int qtdProfessor){


            printf("\n*** Menu 1 - Inserir ***\n");

            printf("\n Digite a matricula de trabalho: \n");
            scanf("%d", &list_professor[qtdProfessor].mat);
            getchar();

            if(list_professor[qtdProfessor].mat==0) {
                return CADASTRO_ERRO_MAT;
            }

            printf("\n Digite o sexo: \n");
            scanf("%c", &list_professor[qtdProfessor].sexo);

            list_professor[qtdProfessor].sexo=toupper(list_professor[qtdProfessor].sexo);

            if (list_professor[qtdProfessor].sexo != 'M' && list_professor[qtdProfessor].sexo != 'F') {
                return CADASTRO_ERRO_SEX;
            }

            int dataNasc;

            printf("\n Informe a idade no formato dd/dd/dddd: \n");
            scanf("%d", &dataNasc);
            getchar();

            list_professor[qtdProfessor].dataN.dia = dataNasc / 1000000;
            list_professor[qtdProfessor].dataN.mes = dataNasc % 1000000 / 10000;
            list_professor[qtdProfessor].dataN.ano = dataNasc % 1000000 % 10000;


            printf("\n Digite o nome: \n");
            fgets(list_professor[qtdProfessor].nome, 50, stdin);

            size_t ln = strlen(list_professor[qtdProfessor].nome) - 1;
            if (list_professor[qtdProfessor].nome[ln] == '\n')
            list_professor[qtdProfessor].nome[ln] = '\0';

            printf("\n Digite o CPF: \n");
            fgets(list_professor[qtdProfessor].cpf, 15, stdin);
            ln = strlen(list_professor[qtdProfessor].cpf) - 1;
            if (list_professor[qtdProfessor].cpf[ln] == '\n'){
                list_professor[qtdProfessor].cpf[ln] = '\0';
            }

            printf("\n");

            return CADASTRO_OK;

}


void listarAluno(Pessoa list_aluno[], int qtdAluno){

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

void listarProfessor(Pessoa list_professor[], int qtdProfessor){

            printf("\n*** Menu 2 - Listar Relacao***\n");
            int i;

            for(i = 0; i < qtdProfessor; i++){

                printf("\n Nome: %s \n",list_professor[i].nome);
                printf("\n Matricula: %d \n",list_professor[i].mat);
                printf("\n Sexo: %c \n",list_professor[i].sexo);
                printf("\n Data de Nascimento %d/%d/%d \n",list_professor[i].dataN.dia, list_professor[i].dataN.mes, list_professor[i].dataN.ano);
                printf("\n CPF: %s \n",list_professor[i].cpf);
                }

                printf("\n");

}


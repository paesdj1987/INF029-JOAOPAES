#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM_ALUNO 5
#define TAM_PROFESSOR 5
#define TAM_DISCIPLINA 5
#define CADASTRO_OK 1
#define CADASTRO_ERRO_MAT 2
#define CADASTRO_ERRO_SEX 3
#define PROFESSOR_NAO_ENCONTRADO 1



/** Versão projeto escola **/


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

typedef struct disciplina{

	char nome[50], professor [50], semestre[50];
	int mat;

}Disciplina;


/* Declaração de Funções - AQUI */

int menuAluno();
int menuPrincipal();
int menuProfessor();
int menuDisciplina();
int inserirAluno(Pessoa list_aluno[], int qtd);
int inserirProfessor(Pessoa list_professor[], int qtd);
int inserirDisciplina(Disciplina list_disciplina[], Pessoa list_professor[], int qtdDisciplina, int qtdProfessor);
void listarAluno(Pessoa list_aluno[], int qtd);
void listarProfessor(Pessoa list_professor[], int qtd);
void listarDisciplina(Disciplina list_disciplina[], int qtdDisciplina);


int main () {


    Pessoa list_aluno[TAM_ALUNO];
    Pessoa list_professor[TAM_PROFESSOR];
    Disciplina list_disciplina[TAM_DISCIPLINA];


    int opcPrincipal, opcAluno, opcProfessor, opcDisciplina;
    int retAluno, retProfessor, retDisciplina;

    int volta1;
    int volta2;
    int volta3;

    int qtdDisciplina=0;
    int qtdAluno=0;
    int qtdProfessor=0;

    int sair=0;


    while(!sair){

    opcPrincipal = menuPrincipal();

    switch (opcPrincipal){

            case 1:{         // Menu Aluno

                volta1=0;

                while(!volta1){

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

                            case 3:{  // Voltar
                                    printf("\e[H\e[2J");
                                    volta1=1;
                                    break;
                                }

                            default: {
                                    printf("opcao invalida \n");
                                    break;
                                }


                                }

                      }
                break;
            }

            case 2:{       // Menu professor

                volta2=0;

                while(!volta2){

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

                            case 3:{  // Voltar
                                    printf("\e[H\e[2J");
                                    volta2 = 1;
                                    break;
                                }

                            default: {
                                    printf("opcao invalida \n");
                                    break;
                                }


                                }
                        }
                        break;
                }




            case 3:{       // menu disciplina

                volta3=0;

                while(!volta3){

                opcDisciplina = menuDisciplina();

                        switch(opcDisciplina){

                            case 1:{          // Inserir professor

                                retDisciplina = inserirDisciplina (list_disciplina, list_professor, qtdDisciplina, qtdProfessor);

                                if(retDisciplina==CADASTRO_OK){
                                    printf("Cadastro realizado com sucesso! \n");
                                    qtdDisciplina++;
                                }
                                else {

                                    if (retDisciplina==CADASTRO_ERRO_MAT){
                                        printf("Matricula das disciplina invalida. \n");
                                    }

                                    else
                                    {
                                        if (retDisciplina==PROFESSOR_NAO_ENCONTRADO){
                                             printf("Professor nao encontrado. \n");
                                        }
                                        else
                                        {
                                            printf("Erro no cadastro! \n");
                                        }

                                      }

                                    }
                             break;
                            }

                            case 2:{  // Listar Disciplina
                                    listarDisciplina(list_disciplina, qtdDisciplina);
                                    break;
                                }

                            case 3:{  // Voltar
                                    printf("\e[H\e[2J");
                                    volta3 = 1;
                                    break;
                                }

                            default: {
                                    printf("opcao invalida \n");
                                    break;
                                }


                                }
                        }

                break;
            }

            case 4:{       // Sair
                printf("\e[H\e[2J");
                sair=1;
                break;
            }

            default:{
                printf("Opcao invalida \n");
                break;
            }

    }



    return 1;
    }

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
    printf("\n 3 - Voltar \n");

    printf("\n Digite a opcao desejada: \n");
    scanf("%d", &op_menuAluno);

    return op_menuAluno;
}

int menuProfessor() {

    int op_menuProfessor;

    printf("\n *** Bem Vindo Ao Sistema Escolar AZX - Menu Professor *** \n");
    printf("\n 1 - Inserir Professor \n");
    printf("\n 2 - Listar Relacao Professor \n");
    printf("\n 3 - Voltar \n");

    printf("\n Digite a opcao desejada: \n");
    scanf("%d", &op_menuProfessor);

    return op_menuProfessor;
}

int menuDisciplina(){

	int op_menuDisciplina;

	printf("\n### Menu Disciplina ### \n\n");
	printf("1 - Cadastrar Disciplina\n");
	printf("2 - Listar Disciplina\n");
	printf("3 - Voltar\n\n");

	printf("Digite a sua opcao\n");
	scanf("%d",&op_menuDisciplina);

	return op_menuDisciplina;
}




int inserirAluno(Pessoa list_aluno[], int qtd){


            printf("\n*** Menu 1 - Inserir Aluno***\n");

            printf("\n Digite a matricula de aluno: \n");
            scanf("%d", &list_aluno[qtd].mat);
            getchar();

            if(list_aluno[qtd].mat==0) {
                return CADASTRO_ERRO_MAT;
            }

            printf("\n Digite o sexo: \n");
            scanf("%c", &list_aluno[qtd].sexo);

            list_aluno[qtd].sexo=toupper(list_aluno[qtd].sexo);

            if (list_aluno[qtd].sexo != 'M' && list_aluno[qtd].sexo != 'F') {
                return CADASTRO_ERRO_SEX;
            }

            int dataNasc;

            printf("\n Informe a idade no formato dd/dd/dddd: \n");
            scanf("%d", &dataNasc);
            getchar();

            list_aluno[qtd].dataN.dia = dataNasc / 1000000;
            list_aluno[qtd].dataN.mes = dataNasc % 1000000 / 10000;
            list_aluno[qtd].dataN.ano = dataNasc % 1000000 % 10000;


            printf("\n Digite o nome: \n");
            fgets(list_aluno[qtd].nome, 50, stdin);

            size_t ln = strlen(list_aluno[qtd].nome) - 1;
            if (list_aluno[qtd].nome[ln] == '\n')
            list_aluno[qtd].nome[ln] = '\0';

            printf("\n Digite o CPF: \n");
            fgets(list_aluno[qtd].cpf, 15, stdin);
            ln = strlen(list_aluno[qtd].cpf) - 1;
            if (list_aluno[qtd].cpf[ln] == '\n'){
                list_aluno[qtd].cpf[ln] = '\0';
            }

            printf("\n");

            return CADASTRO_OK;

}

int inserirProfessor(Pessoa list_professor[], int qtd){


            printf("\n*** Menu 1 - Inserir Professor***\n");

            printf("\n Digite a matricula de trabalho: \n");
            scanf("%d", &list_professor[qtd].mat);
            getchar();

            if(list_professor[qtd].mat==0) {
                return CADASTRO_ERRO_MAT;
            }

            printf("\n Digite o sexo: \n");
            scanf("%c", &list_professor[qtd].sexo);

            list_professor[qtd].sexo=toupper(list_professor[qtd].sexo);

            if (list_professor[qtd].sexo != 'M' && list_professor[qtd].sexo != 'F') {
                return CADASTRO_ERRO_SEX;
            }

            int dataNasc;

            printf("\n Informe a idade no formato dd/dd/dddd: \n");
            scanf("%d", &dataNasc);
            getchar();

            list_professor[qtd].dataN.dia = dataNasc / 1000000;
            list_professor[qtd].dataN.mes = dataNasc % 1000000 / 10000;
            list_professor[qtd].dataN.ano = dataNasc % 1000000 % 10000;


            printf("\n Digite o nome: \n");
            fgets(list_professor[qtd].nome, 50, stdin);

            size_t ln = strlen(list_professor[qtd].nome) - 1;
            if (list_professor[qtd].nome[ln] == '\n')
            list_professor[qtd].nome[ln] = '\0';

            printf("\n Digite o CPF: \n");
            fgets(list_professor[qtd].cpf, 15, stdin);
            ln = strlen(list_professor[qtd].cpf) - 1;
            if (list_professor[qtd].cpf[ln] == '\n'){
                list_professor[qtd].cpf[ln] = '\0';
            }

            printf("\n");

            return CADASTRO_OK;

}


int inserirDisciplina (Disciplina list_disciplina[], Pessoa list_professor[], int qtdDisciplina, int qtdProfessor) {

            int i;

            printf("\n Matricula da Disciplina\n");
            scanf("%d",&list_disciplina[qtdDisciplina].mat);
            getchar();

            if(list_disciplina[qtdDisciplina].mat == 0)
                return CADASTRO_ERRO_MAT;

            printf("\n Nome da Disciplina \n");
            fgets(list_disciplina[qtdDisciplina].nome, 50, stdin);

            size_t ln = strlen(list_disciplina[qtdDisciplina].nome) - 1;
            if(list_disciplina[qtdDisciplina].nome[ln] = '\n')
                list_disciplina[qtdDisciplina].nome[ln] = '\0';

            printf("\n Semestre da Disciplina por extenso \n");
            fgets(list_disciplina[qtdDisciplina].semestre, 50, stdin);

            printf("\n Professor da Disciplina \n");
            fgets(list_disciplina[qtdDisciplina].professor, 50, stdin);

            ln = strlen(list_disciplina[qtdDisciplina].professor) - 1;
            if(list_disciplina[qtdDisciplina].professor[ln] = '\n')
                list_disciplina[qtdDisciplina].professor[ln] = '\0';

            for(i = 0; i < qtdProfessor; i++)
                if(list_disciplina[qtdDisciplina].professor != list_professor[i].nome)
                    return PROFESSOR_NAO_ENCONTRADO;


            return CADASTRO_OK;

}


void listarAluno(Pessoa list_aluno[], int qtd){

            printf("\n*** Menu 2 - Listar Relacao Aluno***\n");
            int i;

            for(i = 0; i < qtd; i++){

                printf("\n Nome: %s \n",list_aluno[i].nome);
                printf("\n Matricula: %d \n",list_aluno[i].mat);
                printf("\n Sexo: %c \n",list_aluno[i].sexo);
                printf("\n Data de Nascimento %d/%d/%d \n",list_aluno[i].dataN.dia, list_aluno[i].dataN.mes, list_aluno[i].dataN.ano);
                printf("\n CPF: %s \n",list_aluno[i].cpf);
                }

                printf("\n");

}

void listarProfessor (Pessoa list_professor[], int qtd){

            printf("\n*** Menu 2 - Listar Relacao Professor***\n");
            int i;

            for(i = 0; i < qtd; i++){

                printf("\n Nome: %s \n",list_professor[i].nome);
                printf("\n Matricula: %d \n",list_professor[i].mat);
                printf("\n Sexo: %c \n",list_professor[i].sexo);
                printf("\n Data de Nascimento %d/%d/%d \n",list_professor[i].dataN.dia, list_professor[i].dataN.mes, list_professor[i].dataN.ano);
                printf("\n CPF: %s \n",list_professor[i].cpf);
                }

                printf("\n");

}

void listarDisciplina (Disciplina list_disciplina[], int qtdDisciplina){

    printf("\n*** Menu 3 - Listar Relacao Disciplina***\n");
	int i;

	for(i = 0; i < qtdDisciplina; i++){
		printf("-------\n");
		printf("Matricula: %d\n", list_disciplina[i].mat);
		printf("Nome: %s\n", list_disciplina[i].nome);
		printf("Semestre: %s", list_disciplina[i].semestre);
		printf("Professor: %s\n", list_disciplina[i].professor);
        }

	printf("\n");
}

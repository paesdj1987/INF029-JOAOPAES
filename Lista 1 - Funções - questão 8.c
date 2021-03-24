#include <stdio.h>
#include <stdlib.h>

//* Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do
//* cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve
//* imprimir os dados do cliente.

typedef struct{
    int dia, mes, ano;
}DataNas;

typedef struct{
    DataNas dataNas;
    char sexo[1];
    char nome[50];
    int cpf;

}Cliente;



void cadastrarCliente(Cliente c) {

    printf("\t nome: %s \n", c.nome);
    printf("\t sexo: %s \n", c.sexo);
    printf("\t data nascimento: %d%d%d \n", c.dataNas.dia, c.dataNas.mes, c.dataNas.ano);
    printf("\t cpf: %d", c.cpf);

}

int main () {

    Cliente cliente;

    printf("\n insira o nome: \n");
    gets(cliente.nome);

    printf("insira a data de nascimento: \n");
    scanf("%d%d%d", &cliente.dataNas.dia, &cliente.dataNas.mes, &cliente.dataNas.ano);

    printf("sexo - M-> Masculino e F-> Feminino: \n");
    scanf("%s", &cliente.sexo);

    printf("insira o cpf: \n");
    scanf("%d", &cliente.cpf);

    cadastrarCliente(cliente);



return 0;
}


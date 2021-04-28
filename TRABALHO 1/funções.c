#include <stdio.h>
#include <stdlib.h>


int somar(int x, int y){
  int soma = 0;
  soma = x + y;
  return soma;
}



int fatorial(int x){ //função utilizada para testes
  int fat = 1;
  return fat;
}


int valida_datas (int dia, int mes, int ano){

    if ((dia < 1 || dia > 31) || (mes < 1 || mes > 12) || (ano < 1900 || ano > 2019)   // validação basica para rodar
        return 0;

    if (dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11))          // meses que não podem ter mais de 30 dias
        return 0;

    if (dia > 29 && (mes == 2 && ano % 4 == 0 || ano % 400 == 0 && ano % 100 != 0))        // fevereiro (caso especifico 1)
        return 0;

    if (dia > 28 && (mes == 2 && ano % 4 != 0 || ano % 400 != 0 && ano % 100 == 0))        // fevereiro (caso específico 2)
        return 0;


    return 1;

}

int busca_datas (char d){

    if (d >= 48 && d <= 57)
        return 0;
    else
        return 1;

}



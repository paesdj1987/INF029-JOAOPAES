// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: joão danilo ferreira paes
//  email: paesdj@gmail.com
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>






int valida_datas(int dia, int mes, int ano);
int busca_datas(char d);


int q1(char *data){

    int datavalida = 1;

    int iDia;
    int iMes;
    int iAno;

    int resultado;

    char sDia[3];
    char sMes[3];
    char sAno[5];


    //tratar DIA

    int i;

    for(i=0; data[i] != '/'; i++){

        sDia[i]=data[i];

        if(i>1)
            return 0;

        if (busca_datas(sDia[i]) == 0)
            return 0;

        if (busca_datas(sDia[i]) == 1)
            return 0;

    }

    sDia[i] = '\0';
    i++;

    if (strlen(sDia) == 0)
        return 0;


    iDia=atoi(sDia);


    // tratar MES

    int m;
    int contMes=0;

    for (m = i; data[m] != '/'; m++, contMes++){

        sMes[contMes] = data[m];

            if (contMes>1)
                return 0;

            if (busca_datas(sMes[contMes]) == 0)
                return 0;

            if (busca_datas(sMes[contMes]) == 1)
                return 0;

    }

    sMes[m] = '\0';
    m++;


    if (strlen(sMes) == 0)
        return 0;

    iMes = atoi(sMes);


    // tratar ANO

    int contAno=0;


    for (i = m; i<strlen(data); i++, contAno++){

        sAno[contAno] = data[i];

        if (busca_datas(data[i]) == 0)
            return 0;

        if (busca_datas(data[i]) == 1)
            return 0;

    }

    if (contAno != 2 && contAno != 4)
        return 0;


    sAno[contAno] = '\0';

    iAno = atoi(sAno);


    // VALIDAÇÃO


    resultado = valida_datas(iDia, iMes, iAno);

    return resultado;



    if (datavalida)
        return 1;
    else
        return 0;


}

int valida_datas (int dia, int mes, int ano){

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900 || ano > 2019)   // validação basica para rodar
        return 0;

    if ((dia > 30) && mes == 4 || mes == 6 || mes == 9 || mes == 11)          // meses que não podem ter mais de 30 dias
        return 0;

    if ((dia > 29) && mes == 2 && ano % 4 == 0 || ano % 400 == 0 && ano % 100 != 0)        // fevereiro (caso especifico 1)
        return 0;

    if ((dia > 28) && mes == 2 && ano % 4 != 0 || ano % 400 != 0 && ano % 100 == 0)        // fevereiro (caso específico 2)
        return 0;


    return 1;

}

int busca_datas (char d){

    if (d >= 48 && d <= 57)
        return 0;
    else
        return 1;

}

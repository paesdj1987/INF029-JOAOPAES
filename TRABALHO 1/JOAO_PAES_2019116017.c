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
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



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



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){

    int iDiaInicio, iMesInicio, iAnoInicio;
    int iDiaFim, iMesFim, iAnoFim;

    int a, b;
    int contMes=0, contAno=0;
    int mesAnterior;

    char dia[3], mes[3], ano[3];


    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;

    nDias = 4;
    nMeses = 10;
    nAnos = 2;


    if (q1(datainicial) == 0)
        return 2;

    if (q1 (datafinal) == 0)
        return 3;


    for (a=0; datainicial[a] != '/'; a++)
        dia[a] = datainicial[a];

        dia[a] = '\0';
        a++;


    for (b=a, contMes=0; datainicial[a] != '/'; a++, contMes++)
        mes[contMes] = datainicial[b];

        mes[b]='\0';
        b++;

    for (a=b, contAno=0; a< strlen(datainicial); a++, contAno++)
        ano[contAno] = datainicial[a];

        ano[contAno]='\0';


    iDiaInicio = atoi(dia);
    iMesInicio = atoi(mes);
    iAnoInicio = atoi(ano);


    // tratando data final

    for (a=0; datafinal[a] != '/'; a++)
        dia[a] = datafinal[a];

        dia[a] = '\0';
        a++;


    for (b=a, contMes=0; datafinal[a] != '/'; a++, contMes++)
        mes[contMes] = datafinal[b];

        mes[b]='\0';
        b++;

    for (a=b, contAno=0; a< strlen(datafinal); a++, contAno++)
        ano[contAno] = datafinal[a];

        ano[contAno]='\0';

    iDiaFim = atoi(dia);
    iMesFim = atoi(mes);
    iAnoFim = atoi(ano);

    if (iAnoFim < iAnoInicio || (iAnoFim == iAnoInicio && iMesFim < iMesInicio) || (iAnoFim == iAnoInicio && iMesFim == iMesInicio && iDiaFim < iDiaInicio))
    return 4;

    mesAnterior=iMesFim-1;

    if (iDiaFim<iDiaInicio) {

        if (mesAnterior==1 || mesAnterior==3 || mesAnterior==5 || mesAnterior==7 || mesAnterior==8 || mesAnterior==10 || mesAnterior==12)
            iDiaFim+=31;
        if (mesAnterior==4 || mesAnterior==6 || mesAnterior==9 || mesAnterior == 11)
            iDiaFim+=30;

        if(mesAnterior==2) {

            if ((mesAnterior%100 != 0) && mesAnterior%400 == 0 || mesAnterior%4 == 0)
                iDiaFim+=29;
            else
                iDiaFim+=28;

        }

        iMesFim--;

    }

    if (iMesFim < iMesInicio){

        iMesFim+=12;
        iAnoFim--;
    }

    nDias=iDiaFim-iDiaInicio;
    nMeses=iMesFim-iMesInicio;
    nAnos=iAnoFim-iAnoInicio;


    /*mantenha o código abaixo, para salvar os dados em
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;

}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){

    int qtdOcorrencias = 0;
    int i;

    if (isCaseSensitive==1)
        for(i=0; i<strlen(texto); i++)
            if(c == texto[i])
                qtdOcorrencias++;
            if(texto[i] == c)
                qtdOcorrencias++;

    if (isCaseSensitive != 1)
        for(i=0; i<strlen(texto); i++)
            if (c == texto[i] || toupper(c) == texto[i] || tolower(c)== texto[i])
                qtdOcorrencias++;
            if (texto[i] == c || texto[i] == toupper (c) || texto[i] == tolower(c))
                qtdOcorrencias++;


    return qtdOcorrencias;

}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = 0;

    int x, y, z;

    int acent;

    x=y=z = acent = qtdOcorrencias = 0;

    for (x=0; x<strlen(strTexto); x++){

        if(strBusca[0] == strTexto[x]){

            while (strBusca[y] == strTexto[x]){
                x++;
                y++;
            }


        if(y==strlen(strBusca)){

            posicoes[z] = x - (strlen(strBusca)-1) - acent;
            z++;

            posicoes[z] = x - acent;
            z++;

        }
        y=0;
    }

    if(strTexto[x] < 0 && strTexto[x + 1] < 0)
        acent++;

    }

    qtdOcorrencias=z/2;


    return qtdOcorrencias;

}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){

    int numInverso = 0;
    int i;

        while (num > 0){
            i = num % 10;
            numInverso = numInverso * 10 + i;
            num /= 10;
        }

    return numInverso;

}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){

    int qtdOcorrencias=0;
    int i;

    int tam=1;

    i=numerobusca;

    while (i != 0){

        tam=tam*10;
        i=i/10;
    }

    i=numerobase;

    while (i != 0){

        if(i%tam == numerobusca){

            qtdOcorrencias++;
            i=i/tam;
        }
        else{
            i = i/10;
        }

    }

    return qtdOcorrencias;
}

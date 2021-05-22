#include <stdio.h>
#include <stdlib.h>
#include "Joao_Paes_2019116017.h"

Est_Principal vetorPrincipal[TAM];

void dobrar(int *x){
    *x = *x * 2;
}

void inicializar(){
  int i;

  for (i = 0; i < TAM; i++){
    vetorPrincipal[i].auxiliar = NULL;
    vetorPrincipal[i].qtd = 0;
    vetorPrincipal[i].tamanho = 0;
  }
}

int posicaoInvalida(int posicao){
    if (posicao < 1 || posicao > TAM)
        return 1;
    else
        return 0;
}


int criarEstruturaAuxiliar(int tamanho, int posicao){

  if (tamanho < 1 )
    return TAMANHO_INVALIDO;

  if (posicaoInvalida(posicao))
    return POSICAO_INVALIDA;

  posicao -= 1; // o vetor vai de 0 - 9

  if (vetorPrincipal[posicao].auxiliar != NULL)
    return JA_TEM_ESTRUTURA_AUXILIAR;

  vetorPrincipal[posicao].auxiliar = (int*)malloc(tamanho*sizeof(int)); // AUXILIAR É UM PONTEIRO DO TIPO INTEIRO

  if (vetorPrincipal[posicao].auxiliar == NULL)
      return SEM_ESPACO_DE_MEMORIA;

  vetorPrincipal[posicao].tamanho = tamanho;

  return SUCESSO;
}


int inserirNumeroEmEstrutura(int valor, int posicao){

    if (posicaoInvalida(posicao))
        return POSICAO_INVALIDA;

    posicao -= 1;

    if (vetorPrincipal[posicao].auxiliar == NULL )
        return SEM_ESTRUTURA_AUXILIAR;

    int qtd = vetorPrincipal[posicao].qtd;

    if (qtd >= vetorPrincipal[posicao].tamanho)
      return SEM_ESPACO;

    vetorPrincipal[posicao].auxiliar[qtd] = valor;
    vetorPrincipal[posicao].qtd ++; // ELE CONSEGUIU COLOCAR O VALOR NA ESTRUTURA

    return SUCESSO;
}


int excluirNumeroDoFinaldaEstrutura(int posicao){

    if (posicaoInvalida(posicao) == 1)
        return POSICAO_INVALIDA;

    posicao -= 1;

    if (vetorPrincipal[posicao].auxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].qtd == 0) // DEPOIS TENHO QUE VERIFICAR SE EXISTE OUTRA FORMA
        return ESTRUTURA_AUXILIAR_VAZIA;

    vetorPrincipal[posicao].qtd --; // EXCLUSÃO LÓGICA

  return SUCESSO;
}


int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){

    int i, j;
    int existe = 0;
    int aux;

    if (posicaoInvalida(posicao))
        return POSICAO_INVALIDA;

    posicao -= 1;

    if (vetorPrincipal[posicao].auxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    int qtd = vetorPrincipal[posicao].qtd;

    if (qtd == 1 && vetorPrincipal[posicao].auxiliar[0] == valor)
      existe = 1;

    else
      for (i = 0; i < qtd-1; i++)
        // Se for encontrado, ele vai ser colocado no final do vetor
        if (vetorPrincipal[posicao].auxiliar[i] == valor){
          aux = vetorPrincipal[posicao].auxiliar[i];
          vetorPrincipal[posicao].auxiliar[i] = vetorPrincipal[posicao].auxiliar[i+1];
          vetorPrincipal[posicao].auxiliar[i+1] = aux;

          existe = 1;
        }

    if (existe == 0)
        return NUMERO_INEXISTENTE;
    else
      vetorPrincipal[posicao].qtd --;

    return SUCESSO;
}



void getDadosAux(int posicao, int vetorAux[], int n){

    int i;
    for (i = 0; i < n; i++)
        vetorAux[i] = vetorPrincipal[posicao].auxiliar[i];
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    if (posicaoInvalida(posicao))
        return POSICAO_INVALIDA;

    posicao -= 1;

    if (vetorPrincipal[posicao].auxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int qtd = vetorPrincipal[posicao].qtd;

    getDadosAux(posicao,vetorAux, qtd);

    return SUCESSO;

}

void bubble(int vet[], int n){
    int i, j, aux;

    for (i = n -1; i > 0; i--)
        for (j = 0; j < i; j++)
            if(vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    if (posicaoInvalida(posicao))
        return POSICAO_INVALIDA;

    posicao -= 1;

    if (vetorPrincipal[posicao].auxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int qtd = vetorPrincipal[posicao].qtd;

    getDadosAux(posicao, vetorAux, qtd);
    bubble(vetorAux, qtd);

    return SUCESSO;
}


int todasEstruturasAuxiliaresVazias(){

    int vazia = 0;
    int i;

    for (i = 0; i < TAM; i++)
        if (vetorPrincipal[i].qtd == 0)
            vazia++;

    if (vazia == TAM)
        return 1;

    return 0;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    if (todasEstruturasAuxiliaresVazias())
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    int i, j;
    int qtd;
    int k = 0;

    for (i = 0; i < TAM; i++){

        if (vetorPrincipal[i].auxiliar != NULL){
            qtd = vetorPrincipal[i].qtd;

            for (j = 0; j < qtd; j++, k++)
                 vetorAux[k] = vetorPrincipal[i].auxiliar[j];
        }
    }

    return SUCESSO;
}


int getContadorTodasEstruturaAuxiiares(){

    int i,j;
    int contador = 0;

    for (i = 0; i < TAM; i++)
        if (vetorPrincipal[i].auxiliar != NULL)
            contador += vetorPrincipal[i].qtd;

    return contador;
}


int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    if (todasEstruturasAuxiliaresVazias() == 1)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    getDadosDeTodasEstruturasAuxiliares(vetorAux);

    int n = getContadorTodasEstruturaAuxiiares();

    bubble(vetorAux, n);

    return SUCESSO;
}


int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){

    if (posicaoInvalida(posicao))
        return POSICAO_INVALIDA;

    posicao -= 1;

    if (vetorPrincipal[posicao].auxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    novoTamanho += vetorPrincipal[posicao].tamanho;

    if (novoTamanho < 1)
        return NOVO_TAMANHO_INVALIDO;

    vetorPrincipal[posicao].auxiliar = (int*)realloc(vetorPrincipal[posicao].auxiliar, novoTamanho * sizeof(int));

    if (vetorPrincipal[posicao].auxiliar == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao].tamanho = novoTamanho;

    int qtd = vetorPrincipal[posicao].qtd;

    if (qtd > novoTamanho)
        vetorPrincipal[posicao].qtd = novoTamanho;
    else
        vetorPrincipal[posicao].qtd = qtd;

    return SUCESSO;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao){

    if (posicaoInvalida(posicao))
        return POSICAO_INVALIDA;

    posicao -= 1;

    if (vetorPrincipal[posicao].auxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    int qtd = vetorPrincipal[posicao].qtd;

    return qtd;

}


//Insere o novo valor no final da lista
int inserirNaLista(No *inicio, int valor){

    if (inicio == NULL) // Nao existe lista
        return 0;

    No *novo = (No*)malloc(sizeof(No)); // Alocando memória para novo

    if (novo == NULL) // Não conseguiu alocar memória
        return 0;

    novo->conteudo = valor;
    novo->prox = NULL;

    if (inicio->prox == NULL){ //Lista vazia, nsira no início
        inicio->prox = novo;
        return 1;
    }

    No *ultimo = inicio->prox;

    while (ultimo->prox != NULL)
        ultimo = ultimo->prox;

    ultimo->prox = novo;
}


No* montarListaEncadeadaComCabecote(){

    No *inicio = (No*)malloc(sizeof(No)); // Alocando memória para inicio

    if (inicio == NULL) // Não consegui alocar
        return NULL;

    inicio->prox = NULL; // início só vai servir para apontar para o próximo

    if (todasEstruturasAuxiliaresVazias()) // Se todas as estruturas auxiliares estiverem vazias, retorne NULL
        return NULL;

    int i, j;
    int qtd;

    for (i = 0; i < TAM; i++)
        if (vetorPrincipal[i].auxiliar != NULL){ // Se a estrutura auxiliar não estiver vazia, execute
            qtd = vetorPrincipal[i].qtd; // qtd vai estar sempre mudando o seu valor, pois ele depende de cada posicao da estrutura auxliar
            for (j = 0; j < qtd; j++)
                inserirNaLista(inicio, vetorPrincipal[i].auxiliar[j]);
        }

    return inicio;
}


void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){

    No *atual = inicio->prox;
    int i = 0;

    while (atual != NULL){
        vetorAux[i] = atual->conteudo; // Atribuindo o conteudo de atual para o vetorAux
        atual = atual->prox; // Atual passa a ser o próximo
        i++; // I passa a ocupar a próximo posicao
    }
}


void destruirListaEncadeadaComCabecote(No** inicio){

    if (inicio == NULL) // Lista não existe
        return;

    No *atual = (*inicio)->prox;

    while (*inicio != NULL){

        atual = (*inicio)->prox;

        free(*inicio);

        *inicio = atual;
    }

    *inicio = NULL;
}


void finalizar(){
    int i;
    for(i = 0; i < TAM; i++)
        free(vetorPrincipal[i].auxiliar);
}

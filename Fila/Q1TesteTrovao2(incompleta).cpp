//QUESTÃO 1 DO TESTE TROVÃO 2

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *prox;
}T_nodo;

typedef struct fila{
    T_nodo *inicio;
    T_nodo *fim;
    int tam;
}T_fila;

T_fila * inicializa_fila();
void insere_fila(int, T_fila *);
T_nodo * obtem_endereco();
void mostra_dados(T_fila *);

int main(){
    int i, n, op;
    system("cls");
    T_fila *pfila = inicializa_fila();
    insere_fila(5344, pfila);
    insere_fila(6578, pfila);
    insere_fila(3025, pfila);
    insere_fila(7842, pfila);
    insere_fila(4672, pfila);

    system("cls");
    printf("Programa encerrado de forma inesperada!\n\n");
    return 0;
}

T_fila * inicializa_fila(){
    T_fila *pfila = (T_fila *) malloc(sizeof(T_fila));
    if(pfila == NULL){
        system("cls");
        printf("Memoria insuficiente para alocar estrutura.\n\n");
        system("pause");
        exit(1);
    }
    pfila->inicio = NULL;
    pfila->fim = NULL;
    pfila->tam = 0;
    return pfila;
}

void insere_fila(int n, T_fila *pfila){
    T_nodo *nova_fila = obtem_endereco();
    if(pfila->inicio == NULL){//Tá vazia?
        pfila->inicio = nova_fila;
        pfila->fim = nova_fila;
    } else {//Não tá vazia
        pfila->fim->prox = nova_fila;
        pfila->fim = nova_fila;
    }
    pfila->tam++;
    nova_fila->prox = NULL;
    nova_fila->info = n;
    system("cls");
    printf("Elemento inserido.\n\n");
    system("pause");
}

T_nodo * obtem_endereco(){
    T_nodo *nova_fila = (T_nodo *) malloc(sizeof(T_nodo));
    if(nova_fila == NULL){
        system("cls");
        printf("Memoria insuficiente para alocar estrutura.\n\n");
        system("pause");
        exit(1);
    }
    return nova_fila;
}

void mostra_dados(T_fila *pfila){
    system("cls");
    if(pfila->inicio == NULL){//Tá vazia?
        printf("Pilha vazia!\n\n");
        system("pause");
        return;
    }
    T_nodo *aux = pfila->inicio;
    printf("Elementos da pilha:\n");
    while(aux != NULL){
        printf("\t%d\n", aux->info);
        aux = aux->prox;
    }
    printf("\n");
    system("pause");
}
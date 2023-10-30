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

typedef struct pilha{
    T_nodo *topo;
}T_pilha;

T_fila * inicializa_fila();
void insere_fila(int, T_fila *);
T_nodo * obtem_endereco();
void mostra_dados_fila(T_fila *);
T_pilha * inicializa_pilha();
void empilha(int, T_pilha *);
void mostra_dados_pilha(T_pilha *);
void q1(T_fila *);

int main(){
    system("cls");
    T_fila *pfila = inicializa_fila();
    insere_fila(5344, pfila);
    insere_fila(6578, pfila);
    insere_fila(3025, pfila);
    insere_fila(7842, pfila);
    insere_fila(4672, pfila);
    mostra_dados_fila(pfila);
    q1(pfila);
    system("cls");
    printf("Programa encerrado!\n\n");
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
}

T_nodo * obtem_endereco(){
    T_nodo *nova = (T_nodo *) malloc(sizeof(T_nodo));
    if(nova == NULL){
        system("cls");
        printf("Memoria insuficiente para alocar estrutura.\n\n");
        system("pause");
        exit(1);
    }
    return nova;
}

void mostra_dados_fila(T_fila *pfila){
    system("cls");
    if(pfila->inicio == NULL){//Tá vazia?
        printf("Pilha vazia!\n\n");
        system("pause");
        return;
    }
    T_nodo *aux = pfila->inicio;
    printf("Elementos da fila:\n");
    while(aux != NULL){
        printf("\t%d\n", aux->info);
        aux = aux->prox;
    }
    printf("\n");
    system("pause");
}

T_pilha * inicializa_pilha(){
    T_pilha *ppilha = (T_pilha *) malloc(sizeof(T_pilha));
    if(ppilha == NULL){
        system("cls");
        printf("Memoria insuficiente para alocar estrutura.\n\n");
        system("pause");
        exit(1);
    }
    ppilha->topo = NULL;
    return ppilha;
}

void empilha(int n, T_pilha *ppilha){
    T_nodo *nova_pilha = obtem_endereco();
    nova_pilha->info = n;
    nova_pilha->prox = ppilha->topo;
    ppilha->topo = nova_pilha;
}

void mostra_dados_pilha(T_pilha *ppilha){
    system("cls");
    if(ppilha->topo == NULL){//Tá vazia?
        printf("Pilha vazia!\n\n");
        system("pause");
        return;
    }
    T_nodo *aux = ppilha->topo;
    printf("Elementos que satisfazem a propriedade:\n");
    while(aux != NULL){
        printf("\t%d\n", aux->info);
        aux = aux->prox;
    }
    printf("\n");
    system("pause");
}

void q1(T_fila *pfila){
    T_pilha *ppilha = inicializa_pilha();
	T_nodo *aux = pfila->inicio;
	int soma;
	while(aux != NULL){
		soma = (aux->info / 100) + (aux->info % 100);
		if(soma * soma == aux->info){
			empilha(aux->info, ppilha);
		}
        aux = aux->prox;
	}
	if(ppilha->topo == NULL){
		system("cls");
		printf("Nenhum numero atende a propriedade.\n\n");
		system("pause");
	} else {
		mostra_dados_pilha(ppilha);
	}
}
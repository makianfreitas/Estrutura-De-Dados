//QUESTÃO 2 DO TESTE TROVÃO 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo{
    int info;
    struct nodo *prox;
}T_nodo;

typedef struct cab_lista{
    T_nodo *inicio;
    T_nodo *fim;
    int tam;
}T_cabeca;

typedef struct pilha{
    T_nodo *topo;
}T_pilha;

int cont;

T_cabeca * ini_cabeca();
void inserir(int, T_cabeca *);
T_nodo * obtem_endereco();
T_pilha * inicializa_pilha();
void empilha(int, T_pilha *);
void mostra_dados_pilha(T_pilha *);
void q2(T_cabeca *, T_cabeca *);

int main(){
    int i;
    system("cls");
    T_cabeca *listaA = ini_cabeca();
    T_cabeca *listaB = ini_cabeca();
    srand(time(NULL));
    for(i=0; i<5; i++){
        inserir(rand() % 100, listaA);
        inserir(rand() % 100, listaB);
    }
    q2(listaA, listaB);
    system("cls");
    printf("Programa encerrado!\n\n");
    return 0;
}

T_cabeca * ini_cabeca(){
    T_cabeca *lista = (T_cabeca *) malloc(sizeof(T_cabeca));
    if(lista == NULL){
        system("cls");
        printf("Memoria insuficiente para alocar estrutura.\n\n");
        system("pause");
        exit(1);
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
    return lista;
}

void inserir(int n, T_cabeca *lista){
    T_nodo *atual, *aux;
    T_nodo *novo = obtem_endereco();
    if(lista->inicio == NULL){//Tá vazio?
        lista->inicio = novo;
        lista->fim = novo;
        novo->prox = novo;
    } else {//Não tá vazio
        atual = lista->inicio;
        aux = lista->inicio;
        for(cont=0; cont < lista->tam && atual->info < n; cont++){
            aux = atual;
            atual = atual->prox;
        }
        if((cont < lista->tam) && (atual->info == n)){//Já existe?
            system("cls");
            printf("O elemento ja existe!\n\n");
            system("pause");
            return;
        } else if((atual == lista->inicio) && (cont == 0)){//Não existe / Tem que inserir no início?
            novo->prox = lista->inicio;
            lista->inicio = novo;
            lista->fim->prox = novo;
        } else if(cont == lista->tam){//Não tem que inserir no início / Tem que inserir no fim?
            novo->prox = lista->inicio;
            lista->fim->prox = novo;
            lista->fim = novo;
        } else {//Não tem que inserir no fim, e sim no meio
            novo->prox = atual;
            aux->prox = novo;
        }
    }
    lista->tam++;
    novo->info = n;
}

T_nodo * obtem_endereco(){
    T_nodo *novo = (T_nodo *) malloc(sizeof(T_nodo));
    if(novo == NULL){
        system("cls");
        printf("Memoria insuficiente para alocar estrutura.\n\n");
        system("pause");
        exit(1);
    }
    return novo;
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
    printf("Elementos da pilha:\n");
    while(aux != NULL){
        printf("\t%d\n", aux->info);
        aux = aux->prox;
    }
    printf("\n");
    system("pause");
}

void q2(T_cabeca *listaA, T_cabeca *listaB){
	T_nodo *auxA = listaA->inicio;
	T_nodo *auxB = listaB->inicio;
	T_pilha *ppilha = inicializa_pilha();
	int contA=1, contB=1;
	while(contA <= listaA->tam && contB <= listaB->tam){
		if(auxA->info <= auxB->info){
			empilha(auxA->info, ppilha);
			auxA = auxA->prox;
			contA++;
		} else {
			empilha(auxB->info, ppilha);
			auxB = auxB->prox;
			contB++;
		}
	}
	while(contA <= listaA->tam){
		empilha(auxA->info, ppilha);
		auxA = auxA->prox;
		contA++;	
	}
	while(contB <= listaB->tam){
		empilha(auxB->info, ppilha);
		auxB = auxB->prox;
		contB++;	
	}
	mostra_dados_pilha(ppilha);
}
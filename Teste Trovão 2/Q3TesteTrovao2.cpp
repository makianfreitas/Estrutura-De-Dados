//QUESTÃO 3 DO TESTE TROVÃO 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void q3(T_fila *, T_fila *);

int main(){
    int i;
    srand(time(NULL));
    system("cls");
    T_fila *igg = inicializa_fila();
    T_fila *igm = inicializa_fila();
    for(i=0; i<5; i++){
        insere_fila(rand() % 5, igg);
        insere_fila(rand() % 5, igm);
        insere_fila((rand() % 110) + 90, igg);
        insere_fila(0, igm);
        insere_fila((rand() % 110) + 90, igg);
        insere_fila((rand() % 99) + 1, igm);
    }
    mostra_dados(igg);
    mostra_dados(igm);
    q3(igg, igm);

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
        printf("Fila vazia!\n\n");
        system("pause");
        return;
    }
    T_nodo *aux = pfila->inicio;
    printf("Elementos da Fila:\n");
    while(aux != NULL){
        printf("\t%d\n", aux->info);
        aux = aux->prox;
    }
    printf("\n");
    system("pause");
}

void q3(T_fila *igg, T_fila *igm){
	T_nodo *auxIgg = igg->inicio;
	T_nodo *auxIgm = igm->inicio;
	int contA=0, contB=0, contC=0;
	while(auxIgg != NULL && auxIgm != NULL){
		if((auxIgm->info >= 1 && auxIgm->info <= 100) && auxIgg->info > 100){
			contC++;
		} else if(auxIgg->info > 100){
			contB++;
		} else if(auxIgm->info == 0 && auxIgg->info == 0){
			contA++;
		}
		auxIgg = auxIgg->prox;
		auxIgm = auxIgm->prox;
	}
	system("cls");
	printf("Quantidade de pacientes que nunca tiveram a doenca: %d\n", contA);
	printf("Quantidade de pacientes que estao com a doenca ativa: %d\n", contB);
	printf("Quantidade de pacientes que ja tiveram a doenca estao com ela ativa: %d\n\n", contC);
	system("pause");
}
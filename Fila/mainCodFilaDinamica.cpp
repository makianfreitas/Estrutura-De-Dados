//CÓDIGO BASE DE FILA EM ESTRUTURA DINÂMICA

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *prox;
}T_nodo;

typedef struct cab_lista{
    T_nodo *inicio;
    T_nodo *fim;
    int tam;
}T_fila;

T_fila * inicializa_fila();
void insere_fila(int, T_fila *);
T_nodo * obtem_endereco();
void retira_fila(T_fila *);
void mostra_dados(T_fila *);

int main(){
    int n, op;
    system("cls");
    T_fila *pfila = inicializa_fila();
    do{
        do{
            system("cls");
            printf("******************** MENU ********************\n");
            printf("\t1- Inserir\n");
            printf("\t2- Retirar\n");
            printf("\t3- Mostrar Dados\n");
            printf("\t0- Finalizar\n");
            scanf("\t%d", &op);
            switch(op){
                case 1:
                    system("cls");
                    printf("Digite a informacao: ");
                    scanf("%d", &n);
                    insere_fila(n, pfila);
                    break;
                
                case 2:
                    retira_fila(pfila);
                    break;
                
                case 3:
                    mostra_dados(pfila);
                    break;

                case 0:
                    system("cls");
                    printf("Programa finalizado!\n\n");
                    return 0;

                default:
                    system("cls");
                    printf("DIGITE UMA OPCAO VALIDA!\n\n");
                    system("pause");
            }
        }while(op < 0 || op > 3);
    }while(op != 0);

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
    T_nodo *novo = obtem_endereco();
    if(pfila->inicio == NULL){//Tá vazia?
        pfila->inicio = novo;
        pfila->fim = novo;
    } else {//Não tá vazia
        pfila->fim->prox = novo;
        pfila->fim = novo;
    }
    pfila->tam++;
    novo->prox = NULL;
    novo->info = n;
    system("cls");
    printf("Elemento inserido.\n\n");
    system("pause");
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

void retira_fila(T_fila *pfila){
    system("cls");
    if(pfila->inicio == NULL){//Tá fazia?
        printf("Fila vazia!\n\n");
        system("pause");
        return;
    } else if(pfila->inicio == pfila->fim){//Não tá vazia / É o único elemento?
        pfila->fim = NULL;
    }
    T_nodo *aux = pfila->inicio;
    pfila->inicio = pfila->inicio->prox;
    printf("O elemento %d foi retirado.\n\n", aux->info);
    free(aux);
    pfila->tam--;
    system("pause");
}

void mostra_dados(T_fila *pfila){
    system("cls");
    if(pfila->inicio == NULL){
        printf("Nao ha nenhum elemento na lista.\n\n");
        system("pause");
        return;
    }
    T_nodo *aux = pfila->inicio;
    printf("Elementos da lista:\n");
    while(aux != NULL){
        printf("\t%d\n", aux->info);
        aux = aux->prox;
    }
    printf("\n\n");
    system("pause");
}
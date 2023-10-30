//CÓDIGO BASE DE FILA EM ESTRUTURA DINÂMICA

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
void retira_fila(T_fila *);
void mostra_dados(T_fila *);

int main(){
    int n, op;
    system("cls");
    T_fila *ppilha = inicializa_fila();
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
                    insere_fila(n, ppilha);
                    break;
                
                case 2:
                    retira_fila(ppilha);
                    break;
                
                case 3:
                    mostra_dados(ppilha);
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
    T_fila *ppilha = (T_fila *) malloc(sizeof(T_fila));
    if(ppilha == NULL){
        system("cls");
        printf("Memoria insuficiente para alocar estrutura.\n\n");
        system("pause");
        exit(1);
    }
    ppilha->inicio = NULL;
    ppilha->fim = NULL;
    ppilha->tam = 0;
    return ppilha;
}

void insere_fila(int n, T_fila *ppilha){
    T_nodo *nova_fila = obtem_endereco();
    if(ppilha->inicio == NULL){//Tá vazia?
        ppilha->inicio = nova_fila;
        ppilha->fim = nova_fila;
    } else {//Não tá vazia
        ppilha->fim->prox = nova_fila;
        ppilha->fim = nova_fila;
    }
    ppilha->tam++;
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

void retira_fila(T_fila *ppilha){
    system("cls");
    if(ppilha->inicio == NULL){//Tá fazia?
        printf("Fila vazia!\n\n");
        system("pause");
        return;
    } else if(ppilha->inicio == ppilha->fim){//Não tá vazia / É o único elemento?
        ppilha->fim = NULL;
    }
    T_nodo *aux = ppilha->inicio;
    ppilha->inicio = ppilha->inicio->prox;
    printf("O elemento %d foi retirado.\n\n", aux->info);
    free(aux);
    ppilha->tam--;
    system("pause");
}

void mostra_dados(T_fila *ppilha){
    system("cls");
    if(ppilha->inicio == NULL){//Tá vazia?
        printf("Pilha vazia!\n\n");
        system("pause");
        return;
    }
    T_nodo *aux = ppilha->inicio;
    printf("Elementos da pilha:\n");
    while(aux != NULL){
        printf("\t%d\n", aux->info);
        aux = aux->prox;
    }
    printf("\n");
    system("pause");
}
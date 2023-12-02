//CÓDIGO BASE DE PILHA EM ESTRUTURA DINÂMICA

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *prox;
}T_nodo;

typedef struct pilha{
    T_nodo *topo;
}T_pilha;

T_pilha * inicializa_pilha();
void empilha(int, T_pilha *);
T_nodo * obtem_endereco();
void desempilha(T_pilha *);
void mostra_dados(T_pilha *);

int main(){
    int n, op;
    system("cls");
    T_pilha *ppilha = inicializa_pilha();
    do{
        do{
            system("cls");
            printf("******************** MENU ********************\n");
            printf("\t1- Empilhar\n");
            printf("\t2- Desempilhar\n");
            printf("\t3- Mostrar Dados\n");
            printf("\t0- Finalizar\n");
            scanf("\t%d", &op);
            switch(op){
                case 1:
                    system("cls");
                    printf("Digite a informacao: ");
                    scanf("%d", &n);
                    empilha(n, ppilha);
                    break;
                
                case 2:
                    desempilha(ppilha);
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
    system("cls");
    printf("Elemento inserido.\n\n");
    system("pause");
}

T_nodo * obtem_endereco(){
    T_nodo *nova_pilha = (T_nodo *) malloc(sizeof(T_nodo));
    if(nova_pilha == NULL){
        system("cls");
        printf("Memoria insuficiente para alocar estrutura.\n\n");
        system("pause");
        exit(1);
    }
    return nova_pilha;
}

void desempilha(T_pilha *ppilha){
    system("cls");
    if(ppilha->topo == NULL){//Tá fazia?
        printf("Pilha vazia!\n\n");
        system("pause");
        return;
    }
    T_nodo *aux = ppilha->topo;
    ppilha->topo = ppilha->topo->prox;
    printf("O elemento %d foi retirado.\n\n", aux->info);
    free(aux);
    system("pause");
}

void mostra_dados(T_pilha *ppilha){
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
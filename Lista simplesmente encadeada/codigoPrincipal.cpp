#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *prox;
}T_lista;

typedef struct cab_lista{
    T_lista *inicio;
    T_lista *fim;
    int qtd;
}T_cabeca;
T_cabeca *cabeca;

T_cabeca * ini_cabeca();
void inserir(int n);
T_lista * obtem_endereco();
int consultar(int n);
void excluir(int n);
void listar();

int main(){
    int n, op;
    system("cls");
    cabeca = ini_cabeca();
    do{
        do{
            system("cls");
            printf("******************** MENU ********************\n");
            printf("\t1- Inserir\n");
            printf("\t2- Consultar\n");
            printf("\t3- Excluir\n");
            printf("\t4- Listar\n");
            printf("\t0- Finalizar\n");
            scanf("\t%d", &op);
            switch(op){
                case 1:
                    system("cls");
                    printf("Digite a informacao: ");
                    scanf("%d", &n);
                    inserir(n);
                    break;
                
                case 2:
                    system("cls");
                    printf("Digite a informacao: ");
                    scanf("%d", &n);
                    if(consultar(n) != -1){
                        system("cls");
                        printf("Elemento encontrado.\n\n");
                        system("pause");
                    } else {
                        system("cls");
                        printf("Elemento nao encontrado.\n\n");
                        system("pause");
                    }
                    break;
                
                case 3:
                    system("cls");
                    printf("Digite a informacao: ");
                    scanf("%d", &n);
                    excluir(n);
                    break;
                
                case 4:
                    listar();
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
        }while(op < 0 || op > 4);
    }while(op != 0);

    system("cls");
    printf("Programa encerrado de forma inesperada!\n\n");
    return 0;
}

T_cabeca * ini_cabeca(){
    cabeca = (T_cabeca *) malloc(sizeof(T_cabeca));
    if(cabeca == NULL){
        system("cls");
        printf("Memoria insuficiente para alocar estrutura.\n\n");
        system("pause");
        exit(1);
    }
    cabeca->inicio = NULL;
    cabeca->fim = NULL;
    cabeca->qtd = 0;
    return cabeca;
}

void inserir(int n){
    T_lista *atual, *aux;
    T_lista *novo = obtem_endereco();
    if(cabeca->inicio == NULL){
        cabeca->inicio = novo;
        cabeca->fim = novo;
        novo->prox = NULL;
    } else {
        atual = cabeca->inicio;
        aux = cabeca->inicio;
        while((atual != NULL) && (atual->info < n)){
            aux = atual;
            atual = atual->prox;
        }
        if((atual != NULL) && (atual->info == n)){
            system("cls");
            printf("O elemento ja existe!\n\n");
            system("pause");
            return;
        } else if(atual == cabeca->inicio){
            novo->prox = cabeca->inicio;
            cabeca->inicio = novo;
        } else if(atual == NULL){
            novo->prox = NULL;
            cabeca->fim->prox = novo;
            cabeca->fim = novo;
        } else {
            novo->prox = atual;
            aux->prox = novo;
        }
    }
    cabeca->qtd++;
    novo->info = n;
    system("cls");
    printf("Elemento inserido.\n\n");
    system("pause");
}

T_lista * obtem_endereco(){
    T_lista *novo = (T_lista *) malloc(sizeof(T_lista));
    if(novo == NULL){
        system("cls");
        printf("Memoria insuficiente para alocar estrutura.\n\n");
        system("pause");
        exit(1);
    }
    return novo;
}

int consultar(int n){
    T_lista *atual = cabeca->inicio;
    while((atual != NULL) && (atual->info != n)){
        atual = atual->prox;
    }
    if(atual == NULL){
        return -1;
    } else {
        return atual->info;
    }
}

void excluir(int n){
    T_lista *aux = cabeca->inicio;
    T_lista *atual = cabeca->inicio;
    while((atual != NULL) && (atual->info != n)){
        aux = atual;
        atual = atual->prox;
    }
    if(atual == NULL){
        system("cls");
        printf("Elemento nao encontrado.\n\n");
        system("pause");
        return;
    }
    if(atual == cabeca->inicio){
        cabeca->inicio = atual->prox;
        if(atual == cabeca->fim){
            cabeca->fim = NULL;
        }
    } else if(atual == cabeca->fim){
        cabeca->fim = aux;
        cabeca->fim->prox = NULL;
    } else {
        aux->prox = atual->prox;
    }
    free(atual);
    cabeca->qtd--;
    system("cls");
    printf("Elemento excluido.\n\n");
    system("pause");
}

void listar(){
    system("cls");
    if(cabeca->inicio == NULL){
        printf("Nao ha nenhum elemento na lista.\n\n");
        system("pause");
        return;
    }
    T_lista *atual = cabeca->inicio;
    printf("Elementos da lista:\n");
    while(atual != NULL){
        printf("\t%d\n", atual->info);
        atual = atual->prox;
    }
    printf("\n\n");
    system("pause");
}
//CÓDIGO BASE DE FILA EM ESTRUTURA ESTÁTICA

#include <stdio.h>
#include <stdlib.h>

#define MAXFILA 10

typedef struct fila{
    int elemento[MAXFILA];
    int inicio;
    int fim;
} T_fila;

T_fila * inicializa_fila();
void insere_fila(int, T_fila *);
void retira_fila(T_fila *);
void mostra_dados(T_fila *);

int main(){
    int n, op;
    T_fila *pfila = inicializa_fila();
    system("cls");
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
    T_fila *nova_fila = (T_fila *) malloc(sizeof(T_fila));
    if(nova_fila == NULL){
        system("cls");
        printf("Memória insuficiente!\n\n");
        system("pause");
        exit(1);
    }
    nova_fila->inicio = 0;
    nova_fila->fim = 0;
    return nova_fila;
}

void insere_fila(int n, T_fila *pfila){
    system("cls");
    if(pfila->inicio == (pfila->fim + 1) % MAXFILA){
        printf("Fila cheia!\n\n");
        system("pause");
        return;
    }
    pfila->elemento[pfila->fim] = n;
    pfila->fim = (pfila->fim + 1) % MAXFILA;
    printf("Elemento inserido.\n\n");
    system("pause");
}

void retira_fila(T_fila *pfila){
    system("cls");
    if(pfila->inicio == pfila->fim){//Tá vazia?
        printf("Fila vazia!\n\n");
        system("pause");
        return;
    }
    printf("O elemento %d foi retirado.\n\n", pfila->elemento[pfila->inicio]);
    pfila->inicio = (pfila->inicio + 1) % MAXFILA;
    system("pause");

}

void mostra_dados(T_fila *pfila){
    int i;
    system("cls");
    if(pfila->inicio == pfila->fim){//Tá vazia
        printf("Fila vazia!\n\n");
        system("pause");
        return;
    }
    printf("Elementos da fila:\n");
    for(i=pfila->inicio; i != pfila->fim; i = (i+1)%MAXFILA){
        printf("\t%d\n", pfila->elemento[i]);
    }
    printf("\n");
    system("pause");
}
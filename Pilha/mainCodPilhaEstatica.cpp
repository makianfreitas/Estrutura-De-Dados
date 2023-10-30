//CÓDIGO BASE DE PILHA EM ESTRUTURA ESTÁTICA

#include <stdio.h>
#include <stdlib.h>

#define MAXPILHA 10

typedef struct pilha{
    int elemento[MAXPILHA];
    int topo;
} T_pilha;

T_pilha * inicializa_pilha();
void empilha(int, T_pilha *);
void desempilha(T_pilha *);
void mostra_dados(T_pilha *);

int main(){
    int n, op;
    T_pilha *ppilha = inicializa_pilha();
    system("cls");
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
    T_pilha *nova_pilha = (T_pilha *) malloc(sizeof(T_pilha));
    if(nova_pilha == NULL){
        system("cls");
        printf("Memória insuficiente!\n\n");
        system("pause");
        exit(1);
    }
    nova_pilha->topo = 0;
    return nova_pilha;
}

void empilha(int n, T_pilha *ppilha){
    system("cls");
    if(ppilha->topo >= MAXPILHA){
        printf("Pilha cheia!\n\n");
        system("pause");
        return;
    }
    ppilha->elemento[ppilha->topo] = n;
    ppilha->topo++;
    printf("Elemento inserido.\n\n");
    system("pause");
}

void desempilha(T_pilha *ppilha){
    system("cls");
    if(ppilha->topo == 0){//Tá vazia?
        printf("Pilha vazia!\n\n");
        system("pause");
        return;
    }
    printf("O elemento %d foi retirado.\n\n", ppilha->elemento[ppilha->topo-1]);
    ppilha->topo--;
    system("pause");

}

void mostra_dados(T_pilha *ppilha){
    int i;
    system("cls");
    if(ppilha->topo == 0){//Tá vazia?
        printf("Pilha vazia!\n\n");
        system("pause");
        return;
    }
    printf("Elementos da pilha:\n");
    for(i=ppilha->topo-1; i >= 0; i--){
        printf("\t%d\n", ppilha->elemento[i]);
    }
    printf("\n");
    system("pause");
}
//CÓDIGO BASE DE ÁRVORES BINÁRIAS

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *pai;
    struct nodo *f_esq;
    struct nodo *f_dir;
    char deletado;
} T_nodo;

typedef struct arvore{
    T_nodo *raiz;
    int qtd;
} T_arvore;

T_arvore * inicializa_arvore();
T_nodo * cria_nodo(int, T_nodo *);
void insere(int, T_arvore *);
void consulta(int, T_arvore *);
void ordem(T_nodo *);
void pre_ordem(T_nodo *);
void pos_ordem(T_nodo *);
void retira(int, T_arvore *);

int main(){
    int n, op;
    system("cls");
    T_arvore *parvore = inicializa_arvore();
    do{
        do{
            system("cls");
            printf("******************** MENU ********************\n");
            printf("\t1- Inserir\n");
            printf("\t2- Consultar\n");
            printf("\t3- Retirar\n");
            printf("\t4- Ordem\n");
            printf("\t5- Pre-Ordem\n");
            printf("\t6- Pos-Ordem\n");
            printf("\t0- Finalizar\n");
            scanf("\t%d", &op);
            switch(op){
                case 1:
                    system("cls");
                    printf("Digite a informacao: ");
                    scanf("%d", &n);
                    insere(n, parvore);
                    break;
                
                case 2:
                    system("cls");
                    if(parvore->raiz == NULL){
                        printf("Arvore vazia\n\n");
                        system("pause");
                    } else {
                        printf("Digite a informacao: ");
                        scanf("%d", &n);
                        consulta(n, parvore);
                    }
                    break;

                case 3:
                    system("cls");
                    printf("Digite a informacao: ");
                    scanf("%d", &n);
                    retira(n, parvore);
                    break;
                
                case 4:
                    system("cls");
                    if(parvore->raiz == NULL){
                        printf("Arvore vazia\n");
                    } else {
                        ordem(parvore->raiz);
                    }
                    printf("\n");
                    system("pause");
                    break;

                case 5:
                    system("cls");
                    if(parvore->raiz == NULL){
                        printf("Arvore vazia\n");
                    } else {
                        pre_ordem(parvore->raiz);
                    }
                    printf("\n");
                    system("pause");
                    break;

                case 6:
                    system("cls");
                    if(parvore->raiz == NULL){
                        printf("Arvore vazia\n");
                    } else {
                        pos_ordem(parvore->raiz);
                    }
                    printf("\n");
                    system("pause");
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
        }while(op < 0 || op > 6);
    }while(op != 0);

    system("cls");
    printf("Programa encerrado de forma inesperada!\n\n");
    return 0;
}

T_arvore * inicializa_arvore(){
    T_arvore *nova_arvore = (T_arvore *) malloc(sizeof(T_arvore));
    if(nova_arvore == NULL){
        system("cls");
        printf("Memoria insuficiente para alocar estrutura.\n\n");
        system("pause");
        exit(1);
    }
    nova_arvore->raiz = NULL;
    nova_arvore->qtd = 0;
    return nova_arvore;
}

T_nodo * cria_nodo(int n, T_nodo *p){
    T_nodo *novo = (T_nodo *) malloc(sizeof(T_nodo));
    if(novo == NULL){
        system("cls");
        printf("Memoria insuficiente para alocar estrutura.\n\n");
        system("pause");
        exit(1);
    }
    novo->info = n;
    novo->pai = p;
    novo->f_esq = NULL;
    novo->f_dir = NULL;
    novo->deletado = 'f';
    return novo;
}

void insere(int n, T_arvore *parvore){
    T_nodo *p, *aux;
    if(parvore->raiz == NULL){//Verifica se a árvore tá vazia
        parvore->raiz = cria_nodo(n, NULL);
    } else {//A árvore não tá vazia
        p = parvore->raiz;
        aux = parvore->raiz;
        while(n != p->info && aux != NULL){
            p = aux;
            if(n < p->info){
                aux = p->f_esq;
            } else {
                aux = p->f_dir;
            }
        }
        if(n == p->info){
            system("cls");
            printf("Numero repetido.\n\n");
            system("pause");
            return;
        } else if(n < p->info){
            p->f_esq = cria_nodo(n, p);
        } else {
            p->f_dir = cria_nodo(n ,p);
        }
    }
    parvore->qtd++;
    system("cls");
    printf("Numero inserido.\n\n");
    system("pause");
}

void consulta(int n, T_arvore *parvore){
    T_nodo *p, *aux;
    p = parvore->raiz;
    aux = parvore->raiz;
    while(n != p->info && aux != NULL){
        p = aux;
        if(n < p->info){
            aux = p->f_esq;
        } else {
            aux = p->f_dir;
        }
    }
    if(n == p->info){
        if(p->deletado != 'v'){//Verifica se o número não foi deletado logicamente
            system("cls");
            printf("Numero existente.\n\n");
            system("pause");
        } else {
            system("cls");
            printf("Numero deletado logicamente.\n\n");
            system("pause");
        }
    } else {
        system("cls");
        printf("Numero inexistente.\n\n");
        system("pause");
    }
}

void ordem(T_nodo *sub_raiz){
    if(sub_raiz != NULL){
        ordem(sub_raiz->f_esq);
        if(sub_raiz->deletado == 'v'){//Verifica se o número foi deletado logicamente
            printf("*%d\n", sub_raiz->info);
        } else {
            printf("%d\n", sub_raiz->info);
        }
        ordem(sub_raiz->f_dir);
    }
}

void pre_ordem(T_nodo *sub_raiz){
    if(sub_raiz != NULL){
        if(sub_raiz->deletado == 'v'){//Verifica se o número foi deletado logicamente
            printf("*%d\n", sub_raiz->info);
        } else {
            printf("%d\n", sub_raiz->info);
        }
        pre_ordem(sub_raiz->f_esq);
        pre_ordem(sub_raiz->f_dir);
    }
}

void pos_ordem(T_nodo *sub_raiz){
    if(sub_raiz != NULL){
        pos_ordem(sub_raiz->f_esq);
        pos_ordem(sub_raiz->f_dir);
        if(sub_raiz->deletado == 'v'){//Verifica se o número foi deletado logicamente
            printf("*%d\n", sub_raiz->info);
        } else {
            printf("%d\n", sub_raiz->info);
        }
    }
}

void retira(int n, T_arvore *parvore){
    T_nodo *aux, *remover;
    aux = parvore->raiz;
    remover = parvore->raiz;
    if(parvore->raiz == NULL){//Verifica se a árvore tá vazia
        system("cls");
        printf("Arvore vazia.\n\n");
        system("pause");
    } else {//A árvore não tá vazia
        while(n != remover->info && aux != NULL){
            remover = aux;
            if(n < remover->info){
                aux = remover->f_esq;
            } else {
                aux = remover->f_dir;
            }
        }
        if(n == remover->info){//Verifica se o número foi encontrado
            remover->deletado = 'v';//Remove logicamente o nó
            parvore->qtd--;
            system("cls");
            printf("Numero removido.\n\n");
            system("pause");
            /*
                >>>>> POR ALGUM MOTIVO KRONBAUER DEIXOU ESSA PARTE TODA ERRADA DO CÓDIGO NO SLIDE. TÁ FALTANDO UM MONTE DE COISA PRA FUNCIONAR. <<<<<

            while(remover != NULL && remover->deletado == 'v'){
                if(remover->f_esq == NULL && remover->f_dir == NULL){//Verifica se o nó a ser deletado não tem filhos nem na direita nem na esquerda
                    if(remover != parvore->raiz){//Verifica se o número a ser removido é diferente da raiz
                        aux = remover->pai;//Remove fisicamente o nó
                        if(aux->f_esq == remover){
                            aux->f_esq = NULL;
                        } else {
                            aux->f_dir = NULL;
                        }
                    } else {
                        parvore->raiz = NULL;//Remove fisicamente a raíz
                    }
                }
                aux = remover;
                free(aux);
                remover = remover->pai;
            }*/
        } else {
            system("cls");
            printf("Numero nao encontrado.\n\n");
            system("pause");
        }
    }
}
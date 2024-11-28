#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"

No *novoNo(int info)
{
    No *novo = (No*)malloc(sizeof(No));
    if(!novo) return NULL;
    novo->info = info;
    novo->dir=novo->esq=NULL;
    return novo;
}

No *inserirNo(No *raiz, int valor)
{
    if(raiz==NULL)
        return novoNo(valor);
    if(valor<raiz->info)
        return inserirNo(raiz->esq, valor);
    else if(valor>raiz->info)
        return inserirNo(raiz->dir, valor);
    return raiz;
}

int contarNo(No *raiz)
{
    if(raiz==NULL)
        return 0;
    return 1 + contarNo(raiz->esq) + contarNo(raiz->dir);
}

int buscarNo(No *raiz, int valor)
{
    if(raiz==NULL)
        return 0;
    if(raiz->info == valor)
        return 1;
    if(valor < raiz->info)
        return buscarNo(raiz->esq, valor);
    return buscarNo(raiz->dir, valor);
}

// Impressao de Percusos 

void preOrdem(No *raiz) // Nó -> Esq -> Dir
{
    if(raiz)
    {
        printf("%d ->", raiz->info);
        emOrdem(raiz->esq);
        emOrdem(raiz->dir);
    }
    printf("NULL\n");
}

void emOrdem(No *raiz)  // Esq -> Nó -> Dir
{
    if(raiz)
    {
        emOrdem(raiz->esq);
        printf("%d ->", raiz->info);
        emOrdem(raiz->dir);
    }
    printf("NULL\n");
}

void posOrdem(No *raiz) // Esq -> Dir -> Nó
{
    if(raiz)
    {
        emOrdem(raiz->esq);
        emOrdem(raiz->dir);
        printf("%d ->", raiz->info);
    }
    printf("NULL\n");
}

void liberarArv(No* raiz)
{
    if(raiz){
        liberarArv(raiz->esq);
        liberarArv(raiz->dir);
        free(raiz);
    }
}

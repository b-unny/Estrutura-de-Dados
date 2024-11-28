#include<stdio.h>
#include<stdlib.h>
#include"AvlTree.h"

int altura(No* raiz)
{
    if(raiz==NULL) 
        return 0;
    int altEsq = altura(raiz->esq);
    int altDir = altura(raiz->dir);

    return 1 + (altEsq > altDir ? altEsq : altDir);
}

int fatorBalanceamento(No *raiz)
{
    if(raiz==NULL)
        return 0;
    
    return altura(raiz->esq) - altura(raiz->dir);
}


No *rotacaoDir(No *pivo)
{
    No *novaRaiz  = pivo->esq;        // Filho a esquerda se torna nova raiz
    No *subArvDir = novaRaiz->dir;   

    novaRaiz->dir = pivo;
    pivo->esq = subArvDir;

    return novaRaiz;
}

No *rotacaoEsq(No *pivo)
{
    No *novaRaiz  = pivo->dir;
    No *subArvEsq = novaRaiz->esq;

    novaRaiz->esq = pivo;
    pivo->dir = subArvEsq;

    return novaRaiz;
}

No *balancear(No *raiz)
{
    int fb = fatorBalanceamento(raiz);

    //Rotacao simples a direita
    if(fb>1 && fatorBalanceamento(raiz->esq)>=0)
        return rotacaoDir(raiz);

    //Rotacao simples a esquerda
    if(fb<-1 && fatorBalanceamento(raiz->dir)<=0)
        return rotacaoEsq(raiz);

    //Rotacao dupla a direita
    if(fb>1 && fatorBalanceamento(raiz->esq)<0){
        raiz->esq = rotacaoEsq(raiz->esq);
        return rotacaoDir(raiz);
    }

    //Rotacao dupla a esquerda
    if(fb<-1 && fatorBalanceamento(raiz->dir)>0){
        raiz->dir = rotacaoDir(raiz->dir);
        return rotacaoEsq(raiz);
    }
}

No *inserirAVL(No *raiz, int valor)
{
    raiz = inserirNo(raiz, valor);
    return balancear(raiz);
}
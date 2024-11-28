#ifndef BINTREE_H
#define BINTREE_H

typedef struct tree{
    int info;
    struct tree *esq, *dir;
} No;

No *novoNo(int info);

No *inserirNo(No *raiz, int valor);

int contarNo(No *raiz);

int buscarNo(No *raiz, int valor);

// Impressao de Percusos 

void preOrdem(No *raiz); // Nó -> Esq -> Dir

void emOrdem(No *raiz);  // Esq -> Nó -> Dir

void posOrdem(No *raiz); // Esq -> Dir -> Nó

void liberarArv(No* raiz);

#endif
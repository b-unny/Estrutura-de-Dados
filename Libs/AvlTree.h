#ifndef AVLTREE_H
#define AVLTREE_H

#include "BinTree.h"

// Fuçoes especificas de arvores AVL

int altura(No* raiz);

int fatorBalanceamento(No *raiz);

No *rotacaoDir(No *pivo);

No *rotacaoEsq(No *pivo);

No *balancear(No *raiz);

No *inserirAVL(No *raiz, int valor);

#endif
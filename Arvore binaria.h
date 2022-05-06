#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct arvore
{
    char dado;
    char valor;
    struct arvore *esq;
    struct arvore *dir;
    struct arvore *pai;
} Arvore;

Arvore * searchdestroy (Arvore *no, char valor);
Arvore * recebeDado (Arvore *no,char valor );
Arvore * novaArvore( char valor );
Arvore * insereArvore( Arvore *no, char valor );
Arvore * searchArvore( Arvore *no, char procurado );
void removeArvore( Arvore *raiz, char valor);
void mostraOrdem( Arvore *no );
void mostraPreOrdem( Arvore *no );
void mostraPosOrdem( Arvore *no );
void mostraNivel( Arvore *no );



#endif


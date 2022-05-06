#include <iostream>
#include <queue>
#include "Arvore binaria.h"

using namespace std;

Arvore * novaArvore( char valor )
{
    Arvore * no = new Arvore;
    no->dado = valor;
    no->esq = nullptr;
    no->dir = nullptr;
    no->pai = nullptr;

    return no;
}

Arvore * recebeDado (Arvore *no, char valor)
{
    cout << "informe o dado a ser inserido na arvore \n";
    cin >> valor;
    insereArvore(no,valor);
}

Arvore * searchdestroy (Arvore *no, char valor)
{
    cout << "informe o dado a ser removido da arvore \n";
    cin >> valor;
    removeArvore(no, valor);
}
Arvore * insereArvore( Arvore *no, char valor )
{
    static Arvore *aux;

    /*SE ARVORE VAZIA INSERE NA RAIZ*/
    if( no == nullptr ) {
        Arvore *novo = novaArvore(valor);
        novo->pai = aux;
        return novo;
    }

    aux = no;
    if( valor < no->dado ) {
        no->esq = insereArvore( no->esq, valor);
    } else {
        no->dir = insereArvore( no->dir, valor);
    }
    return no;
}

Arvore * searchArvore( Arvore * no, char procurado)
{
    if( no == nullptr) {
        return nullptr;
    }

    if( no->dado == procurado) {

        return no;
    } else {

        if( procurado < no->dado ) {
            return searchArvore(no->esq, procurado);
        } else {
            return searchArvore(no->dir, procurado);
        }
    }
}

char maiorArvore(Arvore *no)
{
    while(no->dir) {
        no = no->dir;
    }
    return no->dado;
}

char predecessorEmOrdem(Arvore *no)
{

    if (no->esq)
        return maiorArvore(no->esq);

    Arvore *aux1 = no->pai;
    while(no == aux1->esq) {
        no = aux1;
        aux1 = no->pai;
    }

    return aux1->dado;
}

void removeArvore( Arvore *raiz, char valor)
{
    Arvore *no, *pai, *filho, *predecessor;

    no = searchArvore(raiz, valor);


    if(no->esq == nullptr && no->dir == nullptr) {

        if(no->pai)
            {pai = no->pai;}

        if(no == pai->esq) {
            pai->esq = nullptr;
        }
        else if(no == pai->dir) {
            pai->dir = nullptr;
        }
        delete no;
        return;
    }


    if( no->esq && no->dir) {
        char ch_predecessor = predecessorEmOrdem(no);
        predecessor = searchArvore(raiz, ch_predecessor);
        if(predecessor->pai->esq == predecessor) {
            predecessor->pai->esq = nullptr;
        } else if(predecessor->pai->dir == predecessor) {
            predecessor->pai->dir = nullptr;
        }
        no->dado = predecessor->dado;
        delete predecessor;
        return;
    }


    if(no->esq) {
        filho = no->esq;
    } else if(no->dir) {
        filho = no->dir;
    }
    pai = no->pai;
    if(pai->esq && pai->esq == no) {
        pai->esq = filho;
    } else if(pai->dir && pai->dir == no) {
        pai->dir = filho;
    }
    filho->pai = pai;
    delete no;
    return;
}


void mostraOrdem( Arvore *no )
{
    if( no == nullptr ) return;

    mostraOrdem( no->esq);
    cout << no->dado << "\n";
    mostraOrdem( no->dir);
}

void mostraPreOrdem( Arvore *no )
{
    if( no == nullptr ) return;

    cout << no->dado << "\n";
    mostraPreOrdem( no->esq);
    mostraPreOrdem( no->dir);
}

void mostraPosOrdem( Arvore *no )
{
    if( no == nullptr ) return;

    mostraPosOrdem( no->esq );
    mostraPosOrdem( no->dir );
    cout << no->dado << "\n";
}

void mostraNivel( Arvore *raiz )
{

    queue<Arvore*> fila;
    Arvore *no;

    if(raiz != nullptr){
        fila.push(raiz);

        while( !fila.empty() ) {
            no = fila.front();
            fila.pop();
            if( no->esq != nullptr) fila.push(no->esq);
            if( no->dir != nullptr) fila.push( no->dir );
            cout << no->dado << "\n";
        }
    }
}

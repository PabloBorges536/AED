#ifndef PILHA_H
#define PILHA_H

#include "elemento.h"
#include <iostream>


class Pilha {

    public:
        Pilha(int tamanho);


        void empilhar(Elemento* elemento);
        Elemente* desempilhar();

        bool isFull() const;
        bool isEmpty() const;
        int Size() const;
        
    private:
        Elemento** dados;
        int size;
        int topo;


};

#endif
#ifndef FILA_H
#define FILA_H

#include "elemento.h"
#include <iostream>


class Fila {

    public:
        Fila(int tamanho);
        void enfileirar(Elemento* elemento);
        bool isFull() const;
        bool isEmpty() const;
        int Size() const;
        Elemento* desenfileirar();
        
    private:
        Elemento** dados;
        int size;
        int front; // posicao para sair
        int back; // posicao de inserir
        int len;


};

#endif
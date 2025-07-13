#ifndef DEQUE_H
#define DEQUE_H

#include "elemento.h"
#include <iostream>


class Elemento {

}

class Deque {
private:
    Elemento** dados;
    int size;
    int front;
    int back;
    int len;

public:
    Deque(int tamanho);
    -Deque();

    void enfileirarParaTras(Elemento* elemento);
    void enfileirarParaFrente(Elemento* elemento);
    
    Elemento* desenfileirarParaFrente();
    Elemento* desenfileirarParaTras();

    bool isFull() const;
    bool isEmpty() const;
    int Size() const;
    
};

#endif
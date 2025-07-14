#ifndef FILA_H
#define FILA_H

#include "ListaNaoOrdenada.h"
#include "elemento.h"         
#include <iostream>          

class Fila {
private:
    ListaNaoOrdenada listaSubjacente; 

public:
    Fila(int capacidadeMaxima);

    void enfileirar(Elemento* elemento);
    Elemento* desenfileirar();
    Elemento* consultarPrimeiro() const;
    bool filaCheia() const;
    bool filaVazia() const;
};

// abordagem diferente 
#include "Pilha.h"

class FilaOtimizada {
private:
    Pilha pilhaDeEntrada; 
    Pilha pilhaDeSaida;   
    int capacidadeMaximaFila; 

    void transferirElementos();

public:

    FilaOtimizada(int capacidadeTotal);

    void enfileirar(Elemento* elemento);
    Elemento* desenfileirar();
    Elemento* consultarPrimeiro() const;
    bool filaCheia() const;
    bool filaVazia() const;
};

#endif 
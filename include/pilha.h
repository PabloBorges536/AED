#ifndef PILHA_H
#define PILHA_H

#include "ListaNaoOrdenada.h" 
#include "elemento.h"         
#include <iostream>       

class Pilha {
private:
    // A Pilha 'tem um' objet ListaNaoOrdenada 
    ListaNaoOrdenada listaSubjacente;

public:
    Pilha(int capacidadeMaxima);
    
    void empilhar(Elemento* elemento);
    Elemento* desempilhar();
    Elemento* consultarTopo() const;
    bool pilhaCheia() const;
    bool pilhaVazia() const;
};

#endif

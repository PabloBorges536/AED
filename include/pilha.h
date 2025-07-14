#ifndef PILHA_H
#define PILHA_H

#include "ListaNaoOrdenada.h" 
#include "elemento.h"         
#include <iostream>       

class Pilha {
private:
    // A Pilha 'tem um' objet ListaNaoOrdenada 

public:
    Pilha(int capacidadeMaxima);
    
    ListaNaoOrdenada listaSubjacente;
    void empilhar(Elemento* elemento);
    Elemento* desempilhar();
    Elemento* consultarTopo();
    bool pilhaCheia() const;
    bool pilhaVazia() const;
};

#endif

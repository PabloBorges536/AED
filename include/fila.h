#ifndef FILA_H
#define FILA_H

#include "elemento.h"
#include <iostream>


class Fila : public Elemento {

    public:
        Fila(int tamanho);

    

        
    private:
        Elemento* dados;
        int size;
        int front; // posicao para sair
        int back; // posicao de inserir
        int len;


    

};

#endif
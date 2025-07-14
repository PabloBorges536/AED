
#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H

#include <iostream>  
#include "elemento.h"

template <typename T> 
class ListaDuplamenteEncadeada {
private:

    class No {
    public:
        T dado;  
        No* proximo;  
        No* anterior;  

        No(T val) : dado(val), proximo(nullptr), anterior(nullptr) {}
    };

    No* head;        
    No* tail;        
    int tamanhoAtual; 

public:
    // Construtor e Destrutor
    ListaDuplamenteEncadeada();
    ~ListaDuplamenteEncadeada();

    void xInserirNoInicio(T elemento);
    void xInserirNoFinal(T elemento);
    T xRemoverPrimeiro();
    T xRemoverUltimo();
    T xRemoverPeloId(int id);
    T xBuscarPeloId(int id) const;
    void xAlterarPeloId(int id, T novoElemento);

    bool estaVazia() const;
    int getTamanho() const;
    T getPrimeiro() const;
    T getUltimo() const;
    void imprimirLista() const; 
};

#endif 
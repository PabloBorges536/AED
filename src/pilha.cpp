#include "Pilha.h"


Pilha::Pilha(int capacidadeMaxima) : listaSubjacente(capacidadeMaxima) {}


void Pilha::empilhar(Elemento* elemento) {
    if (pilhaCheia()) {
        std::cout << "Erro: Pilha cheia! Nao foi possivel empilhar o elemento (ID: " << elemento->getID() << ")." << std::endl;
        return;
    }
    listaSubjacente.InserirFim(elemento);
    // Complexidade: O(1) para InserirFim em sua ListaNaoOrdenada baseada em array
}

Elemento* Pilha::desempilhar() {
    if (pilhaVazia()) {
        std::cout << "Erro: Pilha vazia nao foi possivel desempilhar." << std::endl;
        return nullptr;
    }
   
    Elemento* topo = listaSubjacente.BuscarId(listaSubjacente.Size() - 1);

    Elemento* elementoRemovido = listaSubjacente.BuscarId(listaSubjacente.Size() -1); 
    if(elementoRemovido != nullptr){
         listaSubjacente.RemoverUltimo(); // Remove o último elemento
    }

    return elementoRemovido;
}

Elemento* Pilha::consultarTopo() const {
    if (pilhaVazia()) {
        std::cout << "Pilha vazia! Nao ha topo para consultar." << std::endl;
        return nullptr;
    }
   
    return listaSubjacente.BuscarId(listaSubjacente.Size() - 1);
    
}


bool Pilha::pilhaCheia() const {
    return listaSubjacente.isFull();
    
}


bool Pilha::pilhaVazia() const {
    return listaSubjacente.isEmpty();

}
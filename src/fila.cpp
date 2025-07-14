#include "Fila.h"

Fila::Fila(int capacidadeMaxima) : listaSubjacente(capacidadeMaxima) {}

void Fila::enfileirar(Elemento* elemento) {
    if (filaCheia()) {
        std::cout << "Erro: Fila cheia" << std::endl;
        return;
    }
    listaSubjacente.InserirFim(elemento);

}

Elemento* Fila::desenfileirar() {
    if (filaVazia()) {
        std::cout << "Erro: Fila vaziaNao foi possivel desenfileirar." << std::endl;
        return nullptr;
    }

    Elemento* primeiro = listaSubjacente.BuscarId(0); 

    if(primeiro != nullptr){
        listaSubjacente.RemoverIni(); 
    }

    return primeiro;
}

Elemento* Fila::consultarPrimeiro() const {
    if (filaVazia()) {
        std::cout << "Fila vazia. Não tem primeiro elemento para consultar." << std::endl;
        return nullptr;
    }

    return listaSubjacente.BuscarId(0);
 
}

bool Fila::filaCheia() const {
    return listaSubjacente.isFull();

}

bool Fila::filaVazia() const {
    return listaSubjacente.isEmpty();

}

//tentando melhorar a fila normal
FilaOtimizada::FilaOtimizada(int capacidadeTotal)
    : pilhaDeEntrada(capacidadeTotal), 
      pilhaDeSaida(capacidadeTotal),   
      capacidadeMaximaFila(capacidadeTotal) {}


void FilaOtimizada::transferirElementos() {

    while (!pilhaDeEntrada.pilhaVazia() && !pilhaDeSaida.pilhaCheia()) {
        pilhaDeSaida.empilhar(pilhaDeEntrada.desempilhar());
    }

}

void FilaOtimizada::enfileirar(Elemento* elemento) {
 
    if (pilhaDeEntrada.pilhaCheia() && pilhaDeSaida.pilhaCheia()) { 
                                                                   
        std::cout << "Erro: Fila otimizada cheia! ." << std::endl;
        return;
    }
    pilhaDeEntrada.empilhar(elemento);

}

Elemento* FilaOtimizada::desenfileirar() {
    if (filaVazia()) {
        std::cout << "Erro: Fila otimizada vazia!." << std::endl;
        return nullptr;
    }

    if (pilhaDeSaida.pilhaVazia()) {
        transferirElementos(); 
    }

 
    return pilhaDeSaida.desempilhar();
 
}

Elemento* FilaOtimizada::consultarPrimeiro() const {
    if (filaVazia()) {
        std::cout << "Fila otimizada vazia!." << std::endl;
        return nullptr;
    }

    if (pilhaDeSaida.pilhaVazia()) {
        
        if (!pilhaDeSaida.pilhaVazia()) {
            return pilhaDeSaida.consultarTopo();
        } else {
           
            std::cout << "Fila otimizada vazia " << std::endl;
            return nullptr;
        }
    }
}

bool FilaOtimizada::filaCheia() const {

    return (pilhaDeEntrada.listaSubjacente.Size() + pilhaDeSaida.listaSubjacente.Size()) >= capacidadeMaximaFila;
}

bool FilaOtimizada::filaVazia() const {
    return pilhaDeEntrada.pilhaVazia() && pilhaDeSaida.pilhaVazia();
  
}
#include "../include/pilha.h"
#include <iostream>

Pilha::Pilha(int tamanho): size(tamanho), topo(-1) // inicio com -1 e indica que esta vazia
{
    dados = new Elemento*[tamanho]; // e como se fosse o malloc
}

void Pilha::empilhar(Elemento* elemento) // O(1)
{
    if(isFull()){
        std::cout << "pilha cheia\n";
        return;
    }
    topo++;
    dados[topo] = elemento;
    
}

Elemento* Pilha::desempilhar() // O(n)
{
    if(isEmpty()){
        std::cout << "Pilha vazia\n";
        return nullptr;
    }

    Elemento* elemento = dados[topo];
    topo--;
    return elemento;
}

bool Pilha::isFull() const
{
    return topo == size -1;

}

bool Pilha::isEmpty() const 
{
    return topo  == -1;
}

int Pilha::Size() const
{
    return topo + 1;
}

Pilha::~Pilha() {
    delete[] dados; // aqui libera a memórria
}
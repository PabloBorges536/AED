#include "../include/fila.h"
#include <iostream>

Fila::Fila(int tamanho): size(tamanho), front(0), back(-1), len(0)
{
    dados = new Elemento*[tamanho]; // e como se fosse o malloc
}

void Fila::enfileirar(Elemento* elemento)
{
    if(isFull()){
        std::cout << "Fila cheia\n";
        return;
    }
    back = (back + 1 ) % size;
    dados[back] = elemento;
    len++;
}

Elemento* Fila::desenfileirar()
{
    if(isEmpty()){
        std::cout << "Fila vazia\n";
        return nullptr;
    }

    Elemento* elemento = dados[front];
    front = (front + 1) % size; // retorna a posicao correta do elemento
    len--;
    return elemento;
}

bool Fila::isFull() const
{
    return len == size;

}

bool Fila::isEmpty() const 
{
    return len == 0;
}

int Fila::Size() const
{
    return len;
}
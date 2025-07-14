#include "../include/Deque.h"
#include <iostream>

Deque::Deque(int tamanho): size(tamanho), front(0), back(-1), len(0)
{
    dados = new Elemento*[tamanho]; // e como se fosse o malloc
}

Deque::~Deque() {
    delete[] dados;
}

void Deque::enfileirarParaTras(Elemento* elemento) // O(1)
{
    if(isFull()){
        std::cout << "Deque cheia\n";
        return;
    }
    back = (back + 1 ) % size;
    dados[back] = elemento;
    len++;
}
void Deque::enfileirarParaFrente(Elemento* elemento) // O(1)
{
     if(isFull()){
        std::cout << "Deque cheio\n";
        return;
    }

     // Move 'front' para a posição anterior de forma circular.
    front = (front - 1 + size) % size;
    dados[front] = elemento; 
    len--;
}

Elemento* Fila::desenfileirarParaFrente() // O(n)
{
    if (isEmpty()) {
        std::cout << "Deque vazio\n";
        return nullptr;
    }
    Elemento* elemento = dados[front];
    // Move 'front' para a próxima posição de forma circular.
    front = (front + 1) % size;
    len--;
    return elemento;
}

Elemento* Deque::desenfileirarTras() {
    if (isEmpty()) {
        std::cout << "Deque vazio\n";
        return nullptr;
    }
    Elemento* elemento = dados[back];
    // Move 'back' para a posição anterior de forma circular.
    back = (back - 1 + size) % size;
    len--;
    return elemento;
}

bool Deque::isFull() const
{
    return len == size;

}

bool Deque::isEmpty() const 
{
    return len == 0;
}

int Deque::Size() const
{
    return len;
}
#include "../include/ListaNaoOrdenada.h"
#include "ListaNaoOrdenada.h"
#include <iostream>



ListaNaoOrdenada::ListaNaoOrdenada(int tamanho): size(tamanho) , len(0), front(0), back(0)
{
    dados = new Elemento*[tamanho];
    for(int i=0; i<tamanho; i++){
        dados[i] = nullptr;
   }
}

bool ListaNaoOrdenada::isFull() const 
{
    return len == size;
} 

bool ListaNaoOrdenada::isEmpty() const
{
    return len == 0;

}

void ListaNaoOrdenada::movedir()
{
    for(int pos = len-1; pos >= 0; pos--){
        Elemento* aux = dados[pos];
        dados[pos+1] = aux;
    }
}

void ListaNaoOrdenada::moveesq(int index) // so vai ser usado ao remover um item no início
{
    for(int pos = index; pos < len-1; pos++){
        dados[pos] = dados[pos+1];
    }
    dados[len-1] = nullptr; // Limpa o último ponteiro
}

void ListaNaoOrdenada::InserirIni(Elemento* item)
{
    if(isFull()){
        std::cout << "a lista esta cheia";
        return;
    }
    if (len > 0)
        movedir(); // move todos os itens um indece para frente
    dados[0] = item;
    len++;

}

void ListaNaoOrdenada::InserirFim(Elemento* item) // complexidade: O(1)
{
    if(isFull()){
        std::cout << "a lista esta cheia";
        return;
    }
    dados[len] = item;
    len++;
}


void ListaNaoOrdenada::RemoverIni() // complexidade: O(n)
{
    if(isEmpty()){
        std::cout << "Lista vazia, não é possível remover!" << std::endl;
        return;
    }   
    moveesq(0);
    len--;
    dados[len] = nullptr;    
    // Limpa o ponteiro do último elemento
}

void ListaNaoOrdenada::RemoverUltimo() // complexidade: O(1)
{
    if(isEmpty()){
        std::cout << "Lista vazia, não é possível remover!" << std::endl;
        return;
    }   
    dados[len-1] = nullptr;
    len --;
}

Elemento* ListaNaoOrdenada::BuscarId(int id) // complexidade: O(n)
{
    for(int i = 0 ; i < len; i++)
    {
        if(dados[i]->getID() == id){
            return dados[i];
        }
    }
}

void ListaNaoOrdenada::RemoverId(int id) // complexidade: O(n)
{
    int index;
    for(int i = 0; i < len; i++)
    {
        if(dados[i]->getID() == id)
            index = i;
    }

    moveesq(index);
    dados[len-1] = nullptr;
    len --;
    
}

void ListaNaoOrdenada::Aleterar(int id, Elemento* item)
{    
    int index;
    for(int i = 0; i < len; i++)
    {
        if(dados[i]->getID() == id){
            index = i;
        }

    }
    dados[index] = item;

}

int ListaNaoOrdenada::Size() const
{
    return len;
}

void ListaNaoOrdenada::PrintDados() // complexidade: O(n)
{
    if(isEmpty()){
        std::cout << "Lista vazia!" << std::endl;
        return;
    }
    
    std::cout << "=== Dados da Lista ===" << std::endl;
    for(int i = 0; i <= len-1 ; i++){
        std::cout << "Elemento " << (i+1) << ":" << std::endl;
        dados[i]->imprimirInfo();  // Chama o método virtual da classe Elemento
        std::cout << "---" << std::endl;
    }
}

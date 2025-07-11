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

void ListaNaoOrdenada::move()
{
    for(int pos = len-1; pos >= 0; pos--){
        Elemento* aux = dados[pos];
        dados[pos+1] = aux;
    }
}

void ListaNaoOrdenada::InserirIni(Elemento* item)
{
    if(isFull()){
        std::cout << "a lista esta cheia";
        return;
    }
    if (len > 0)
        move(); // move todos os itens um indece para frente
    dados[0] = item;
    len++;

}

void ListaNaoOrdenada::InserirFim(Elemento* item)
{
    if(isFull()){
        std::cout << "a lista esta cheia";
        return;
    }
    dados[len] = item;
    len++;


}


int ListaNaoOrdenada::Size() const
{
    return len;
}

void ListaNaoOrdenada::PrintDados()
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

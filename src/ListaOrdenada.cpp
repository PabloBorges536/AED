#include "../include/ListaOrdenada.h"
#include <iostream>



ListaOrdenada::ListaOrdenada(int tamanho): size(tamanho) , len(0) 
{
    dados = new Elemento*[tamanho];
    for(int i=0; i<tamanho; i++){
        dados[i] = nullptr;
    }   
}

bool ListaOrdenada::isFull() const 
{
    return len == size;
} 

bool ListaOrdenada::isEmpty() const
{
    return len == 0;
}


void ListaOrdenada::Inserir(Elemento* item)
{
    if(isFull()){
        std::cout << "Lista cheia" << std::endl;
        return ;
    }

    int i = len-1;
    while(i>=0 && dados[i]->getID() > item->getID())
    {
        dados[i+1] = dados[i]; // movendo para direita 
        i--;
    }
    dados[i+1] = item;
    len++;
}

void ListaOrdenada::moveesq(int index) // so vai ser usado ao remover um item no início
{
    for(int pos = index; pos < len-1; pos++){
        dados[pos] = dados[pos+1];
    }
    dados[len-1] = nullptr; // Limpa o último ponteiro
}


void ListaOrdenada::RemoverIni() // complexidade: O(n)
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

void ListaOrdenada::RemoverUltimo() // complexidade: O(1)
{
    if(isEmpty()){
        std::cout << "Lista vazia, não é possível remover!" << std::endl;
        return;
    }   
    dados[len-1] = nullptr;
    len --;
}

Elemento* ListaOrdenada::BuscarId(int id) // complexidade: O(n)
{
    int ini = 0;
    int fim = size-1;

    while (ini<=fim){
        int meio = (ini+fim )/ 2;
        if(dados[meio]->getID() == id){
            return dados[meio]; 
        }else if(dados[meio]->getID() < id){
            ini = meio + 1 ;
        }else {
            fim = meio - 1;
        }
    }
    return nullptr;
}

void ListaOrdenada::RemoverId(int id) // complexidade: O(n)
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

void ListaOrdenada::Aleterar(int id, Elemento* item)
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

int ListaOrdenada::Size() const
{
    return len;
}

void ListaOrdenada::PrintDados() // complexidade: O(n)
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


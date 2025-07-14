#include  "../include/ListaEncadeada.h"
#include <iostream>
#include "ListaEncadeada.h"

ListaEncadeada::ListaEncadeada():size(0){
    head = nullptr;
}

ListaEncadeada::~ListaEncadeada(){}

void ListaEncadeada::InserirIni(Elemento* item){
    No* novo = new No(item);
    novo->prox = head;
    head = novo;
    size++;
}
void ListaEncadeada::InserirFim(Elemento* item){
    No* novo = new No(item);
    if (head == nullptr) {
            head = novo;
            return;
        }
        No* atual = head;
        while (atual->prox != nullptr) {
            atual = atual->prox;
        }
        atual->prox = novo;
}

void ListaEncadeada::removerIni()
{
    if(head== nullptr){
        return;
    }
    No* aux = head;
    head = head->prox;
    delete aux;
    return;
}

void ListaEncadeada::removerFim()
{
     if(head== nullptr){
        return;
    }     

    if (head->prox == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    No* aux = head;
    while(aux->prox->prox != nullptr){
        aux = aux->prox;
    }
    delete aux->prox;
    aux->prox = nullptr;
}

void ListaEncadeada::alterarID(int id, Elemento* item){
    No* aux = head;
    while(aux->dado->getID() != id && aux->prox != nullptr){
        aux =aux->prox;
    }
    aux->dado = item;
}

void ListaEncadeada::removerID(int id)
{
    if(head == nullptr){
        return ;
    }

    // Se for o primeiro
    if (head->dado->getID() == id) {
        No* temp = head;
        head = head->prox;
        delete temp;
        return;
    }

    No* aux =head;
    while(head->prox != nullptr && aux->prox->dado->getID() != id)
    {
        aux = aux->prox;
    }

    if(aux->prox == nullptr) return;

    No* temp = aux->prox;
    aux->prox = temp->prox;
    delete temp;
    return ; 

}
Elemento* ListaEncadeada::buscarID(int id){
    No* aux = head;
    while(aux != nullptr){
        if(aux->dado->getID() != id){
            return aux->dado;
        }
        else{
            aux = aux->prox;
        }
    }
}

void ListaEncadeada::PrintDados(){
    No* aux = head;
    while(aux != nullptr){
        aux->dado->imprimirInfo();
        aux = aux->prox;
    }
    std::cout << std::endl;
}

ListaEncadeada::~ListaEncadeada(){
    while(head!=nullptr){
        No* temp = head;
        head = head->prox;
        delete temp;
    }
}



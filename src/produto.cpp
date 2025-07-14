#include "../include/produto.h"
#include <iostream>
#include <string>


Produto::Produto(int id, std::string& item_nome, int preco, std::string& tipo) 
: Elemento(id), item_nome(item_nome) , preco(preco), tipo(tipo) {} 


Produto::~Produto(){}

void Produto::imprimirInfo() const 
{
    std::cout << "Classe Produto:" << "id: " << ID << "\n" <<"Nome: " << item_nome << "\n" <<"preco" << preco << "\n" << "Tipo: "  << tipo << std::endl;
}

std::string Produto::getProdutoNome(){
    return item_nome;
}
int Produto::getPreco(){
    return preco;
}




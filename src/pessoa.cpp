#include "../include/pessoa.h"
#include <iostream>

Pessoa::Pessoa(int id, const std::string &nome, int idade) 
: Elemento(id) , nome(nome) , idade(idade) {}

Pessoa::~Pessoa(){}

void Pessoa::imprimirInfo() const
{
    std::cout << "Classe Pessoa:" << "id: " << ID << "\n" <<"Nome: " << nome << "\n" <<"Idade: " << idade << std::endl;
}

std::string Pessoa::getNome() const
{
    return std::string(nome);
}

int Pessoa::getIdade() const
{
    return idade;
}

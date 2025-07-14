#ifndef PESSOA_H
#define PESSOA_H

#include "elemento.h"
#include <string>

class Pessoa : public Elemento {
    private:
        std::string nome;
        int idade;

    public:
        Pessoa(int id, const std::string& nome, int idade);
        ~Pessoa() override;
        
        void imprimirInfo() const override;
        
        
        std::string getNome() const; //(funcao const) garante que a funcao nao vai mudar o atributo da classe
        int getIdade() const;
};

#endif

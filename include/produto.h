#ifndef PRODUTO_H
#define PRODUTO_H


#include "elemento.h"
#include <string>

class Produto: public Elemento {
private: 
    std::string item_nome;
    int preco;
    std::string tipo;
        
public:
    Produto(int id,std::string& item_nome, int preco, std::string& tipo);
    ~Produto() override;
    void imprimirInfo() const override;
    std::string getProdutoNome();
    int getPreco();
    
};

#endif

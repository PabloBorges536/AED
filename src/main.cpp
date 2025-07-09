#include <iostream>
#include "../include/pessoa.h"
#include "../include/fila.h"

int main(){
    Fila fila(10);
    
    // Criar objetos Pessoa
    Pessoa breno(1, "Breno", 20);
    Pessoa joao(2, "João", 25);
    Pessoa maria(3, "Maria", 30);
    
    // Enfileirar usando endereços dos objetos (&)
    fila.enfileirar(&breno);
    fila.enfileirar(&joao);
    fila.enfileirar(&maria);
    
    std::cout << "Tamanho da fila: " << fila.Size() << std::endl;
    
    // Desenfileirar e imprimir informações
    std::cout << "\n=== Desenfileirando ===" << std::endl;
    while (!fila.isEmpty()) {
        Elemento* elemento = fila.desenfileirar();
        if (elemento != nullptr) {
            elemento->imprimirInfo();
            std::cout << "---" << std::endl;
        }
    }
    
    return 0;
}




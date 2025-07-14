#include <iostream>
#include "../include/pessoa.h"
#include "../include/ListaNaoOrdenada.h"
#include "../include/ListaOrdenada.h"
int main(){
   
    std::cout << "iniciando" << std::endl;
    ListaOrdenada lista(10);    


    // Criar objetos Pessoa
    Pessoa breno(1, "Breno", 20);
    Pessoa joao(2, "Joao", 25);
    Pessoa jose(3, "jose", 30);
    Pessoa Pedro(5, "Pedro", 30);
    
    std::cout << "inserindo" << std::endl;
    lista.Inserir(&Pedro);
    lista.Inserir(&breno);
    lista.Inserir(&jose);
    lista.Inserir(&joao);
    std::cout << "inseri" << std::endl;


    lista.PrintDados();

    lista.RemoverId(3);

    lista.PrintDados();
   




    
    return 0;
}




#include <iostream>
#include "../include/pessoa.h"
#include "../include/ListaNaoOrdenada.h"
#include "../include/ListaOrdenada.h"
#include "../include/ListaEncadeada.h"
#include "../include/ListaDuplamenteEncadeada.h"



int main(){
   
    std::cout << "iniciando" << std::endl;
    ListaEncadeada lista; 


    // Criar objetos Pessoa
    Pessoa breno(1, "Breno", 20);
    Pessoa joao(2, "Joao", 25);
    Pessoa jose(3, "jose", 30);
    Pessoa Pedro(5, "Pedro", 30);
    
    std::cout << "inserindo" << std::endl;
    lista.InserirIni(&breno); 
    lista.InserirIni(&joao);
    lista.InserirFim(&Pedro);

    lista.PrintDados();

    std::cout << "funciona" << std::endl;

    
    return 0;
}

//ALGUEM FINALIZA A MAIN ass Pablo :)


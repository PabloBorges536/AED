#include <iostream>
#include "../include/pessoa.h"
#include "../include/ListaNaoOrdenada.h"

int main(){
   
    std::cout << "iniciando" << std::endl;
    ListaNaoOrdenada lista(10);    


    // Criar objetos Pessoa
    Pessoa breno(1, "Breno", 20);
    Pessoa joao(2, "Joao", 25);
    Pessoa jose(3, "jose", 30);
    Pessoa Pedro(3, "Pedro", 30);
    
    lista.InserirIni(&breno);
    lista.InserirIni(&joao);
    lista.InserirFim(&jose);






    std::cout << lista.Size()<< std::endl;

    lista.PrintDados();

   
    lista.Aleterar(2, &Pedro);

    lista.PrintDados();



    
    return 0;
}




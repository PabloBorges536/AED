#ifndef LISTANAOORDENADA_H
#define LISTANAOORDENADA_H

#include <vector>
#include <elemento.h>

class ListaNaoOrdenada
{ 
	public:
    
		ListaNaoOrdenada(int tamanho);
		bool isFull() const;
		bool isEmpty() const;
		void move();
		void InserirIni(Elemento* item);
		void InserirFim(Elemento* item);
		void PrintDados();
		int Size() const;

		private:
		Elemento** dados;
		int size;
		int front; // usar para remover e nao precisar mover todos para frente
		int back; // posicao do ultimo item
		int len;


};   






#endif
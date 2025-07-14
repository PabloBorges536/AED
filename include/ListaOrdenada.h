#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include <elemento.h>

class ListaOrdenada
{
    ListaOrdenada(int tamanho);
    bool isFull()const;
    bool isEmpty() const;
    void InserirIni(Elemento* item);
    void InserirFim(Elemento* item);
    void RemoverIni();
    void RemoverUltimo();
    Elemento* BuscarId(int id);
    void RemoverId(int id);
    void Aleterar(int id, Elemento* item);
    void PrintDados();
    int Size() const;
    

    private:
    Elemento* dados;
    int size;
    int front


}




#endif
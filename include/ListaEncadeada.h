#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H
#include <elemento.h>

class ListaEncadeada
{
    private:
        class No{
            public:

            protected:
                Elemento* dado;
                No* prox;
                No* ant;
            
            No(Elemento* item) : dado(item), prox(nullptr), ant(nullptr) {}
        };

        No* head;
        int size;
    public:
        ListaEncadeada();
        ~ListaEncadeada();

        void InserirIni(Elemento* item);
        void InserirFim(Elemento* item);
        void removerIni();
        void removerFim();
        void alterarID();
        void removerID(int id);
        Elemento* buscarID(int id);




};

#endif 
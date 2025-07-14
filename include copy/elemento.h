#ifndef ELEMENTO_H
#define ELEMENTO_H

class Elemento {
    public:
        Elemento(int id);
        virtual ~Elemento();
        int getID();
        virtual void imprimirInfo() const = 0;
       
    protected:
        int ID;
};

#endif 
#include "../include/elemento.h"
#include <iostream>
#include "elemento.h"

// Implementação do método não virtual

Elemento::Elemento(int id): ID(id) {}

int Elemento::getID() {
    return ID;
}

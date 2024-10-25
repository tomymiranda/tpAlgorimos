#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include "nodo.h"  // Asegúrate de que también tenga guardas
#include "../clases/proyectoCientifico.h"

class Lista {
private:
    Nodo* primero;
    int largo;

public:
    Lista();
    void alta(ProyectoCientifico d, int pos);
    void baja(int pos);
    ProyectoCientifico consulta(int pos);
    bool vacia();
    virtual ~Lista();
    int obtener_largo();
    void mostrar();
private:
    Nodo* obtener_nodo(int pos);
};

#endif // LISTA_H_INCLUDED

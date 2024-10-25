#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "../clases/proyectoCientifico.h"  // Incluir el archivo de ProyectoCientifico

class Nodo {
private:
    // Atributos
    ProyectoCientifico dato;
    Nodo* siguiente;

public:
    // Constructor
    // PRE:
    // POS: Crea un nodo con dato = d y siguiente = nullptr
    Nodo(ProyectoCientifico d);

    // Métodos para modificar el dato y el puntero siguiente
    void cambiar_dato(ProyectoCientifico d);
    void cambiar_siguiente(Nodo* s);

    // Métodos para obtener el dato y el siguiente nodo
    ProyectoCientifico obtener_dato();
    Nodo* obtener_siguiente();
};

#endif // NODO_H_INCLUDED

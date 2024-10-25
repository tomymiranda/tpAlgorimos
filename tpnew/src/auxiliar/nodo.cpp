#include "nodo.h"
#include "../clases/proyectoCientifico.h"
Nodo::Nodo(ProyectoCientifico d) {
    dato = d;
    siguiente = nullptr;
}

// Cambia el dato almacenado en el nodo
void Nodo::cambiar_dato(ProyectoCientifico d) {
    dato = d;
}

// Cambia el puntero al siguiente nodo
void Nodo::cambiar_siguiente(Nodo* s) {
    siguiente = s;
}

// Retorna el dato almacenado en el nodo
ProyectoCientifico Nodo::obtener_dato() {
    return dato;
}

// Retorna el puntero al siguiente nodo
Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}

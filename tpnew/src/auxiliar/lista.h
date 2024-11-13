#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include "nodo.h"
#include "../clases/centroDeInvestigacion.h"
#include "../clases/proyectoCientifico.h"

template <typename T>
class Lista {
private:
    Nodo<T>* primero;  // Puntero al primer nodo
    int largo;         // Tamaño de la lista

public:
    Lista();                               // Constructor
    void alta(T d, int pos);               // Alta en la lista
    void baja(int pos);                    // Baja en la lista
    T consulta(int pos) const;             // Consulta un elemento en la lista
    bool vacia() const;                    // Verifica si la lista está vacía
    virtual ~Lista();                      // Destructor
    int obtener_largo() const;             // Obtiene el tamaño de la lista
    void mostrar() const;                  // Muestra los elementos de la lista

private:
    Nodo<T>* obtener_nodo(int pos) const;  // Obtiene un nodo en una posición específica
};

// Implementación de métodos

// Constructor
template <typename T>
Lista<T>::Lista() : primero(nullptr), largo(0) {}

// Método para agregar un Nodo a la lista
template <typename T>
void Lista<T>::alta(T d, int pos) {
    Nodo<T>* nuevo = new Nodo<T>(d);
    if (pos == 0) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    } else {
        Nodo<T>* anterior = obtener_nodo(pos - 1);
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(nuevo);
    }
    largo++;
}

// Método para dar de baja un Nodo de la lista
template <typename T>
void Lista<T>::baja(int pos) {
    if (pos == 0) {
        Nodo<T>* eliminar = primero;
        primero = primero->obtener_siguiente();
        delete eliminar;
    } else {
        Nodo<T>* anterior = obtener_nodo(pos - 1);
        Nodo<T>* eliminar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(eliminar->obtener_siguiente());
        delete eliminar;
    }
    largo--;
}

// Método que devuelve un el dato de un Nodo, en una posicion especifica
template <typename T>
T Lista<T>::consulta(int pos) const {
    return obtener_nodo(pos)->obtener_dato();
}

// Método que devuelve si la lista está vacía
template <typename T>
bool Lista<T>::vacia() const {
    return largo == 0;
}

// Método destructor para liberar la memoria ocupada por los Nodos de la lista cuando el objeto Lista es destruido
template <typename T>
Lista<T>::~Lista() {
    while (!vacia()) {
        baja(0);
    }
}

// Método para obtener el largo de la Lista
template <typename T>
int Lista<T>::obtener_largo() const {
    return largo;
}

// Método que imprime los datos de todos los proyectos del grafo
template <typename T>
void Lista<T>::mostrar() const {
    Nodo<T>* actual = primero;
    while (actual != nullptr) {
        T proyecto = actual->obtener_dato();  // Obtenemos el dato del nodo (ProyectoCientifico)

        // Accede e imprime los atributos de ProyectoCientifico
        std::cout << "Proyecto: " << proyecto.getCentroOrigen()
                  << " a " << proyecto.getCentroDestino()
                  << ", Costo: " << proyecto.getCosto() << " miles de pesos, "
                  << "Duración: " << proyecto.getDuracion() << " meses\n";

        actual = actual->obtener_siguiente();
    }
    std::cout << std::endl;
}

// Método que devuelve un puntero al Nodo en la posición específica
template <typename T>
Nodo<T>* Lista<T>::obtener_nodo(int pos) const {
    Nodo<T>* actual = primero;
    for (int i = 0; i < pos; ++i) {
        actual = actual->obtener_siguiente();
    }
    return actual;
}

#endif // LISTA_H_INCLUDED

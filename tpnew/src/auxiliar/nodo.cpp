#include "nodo.h"
#include "../clases/centroDeInvestigacion.h"
#include "../clases/proyectoCientifico.h"
// Definición del constructor
template <typename T>
Nodo<T>::Nodo(T d) : dato(d), siguiente(nullptr) {}

// Definición del método para cambiar el dato
template <typename T>
void Nodo<T>::cambiar_dato(T d) {
    dato = d;
}

// Definición del método para cambiar el siguiente nodo
template <typename T>
void Nodo<T>::cambiar_siguiente(Nodo<T>* s) {
    siguiente = s;
}

// Definición del método para obtener el dato
template <typename T>
T Nodo<T>::obtener_dato() const {
    return dato;
}

// Definición del método para obtener el siguiente nodo
template <typename T>
Nodo<T>* Nodo<T>::obtener_siguiente() const {
    return siguiente;
}

// Para que las implementaciones de las plantillas sean visibles, incluye el archivo de cabecera aquí.
template class Nodo<CentroInvestigacion>;  // Ejemplo de instanciación para CentroInvestigacion
template class Nodo<ProyectoCientifico>;   // Ejemplo de instanciación para ProyectoCientifico

#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <iostream>
#include <vector>
#include <string>
#include "lista.h"

template <typename T>
class TablaHash {
private:
    std::vector<Lista<T>> tabla; // Tabla de hash usando Lista con tipo genérico T
    int capacidad;  // Capacidad de la tabla de hash

    // Función de hash para obtener el índice basado en el código del centro
    int hashFunction(const std::string& codigo);

public:
    // Constructor de la tabla de hash
    TablaHash(int cap);

    // Método para insertar un elemento en la tabla de hash
    void insertar(const std::string& codigo, const T& elemento);

    // Método para buscar un elemento por su código
    bool existe(const std::string& codigo);

    // Método para buscar
    T buscar(const std::string& codigo);

    // Método para eliminar un elemento por su código
    bool eliminar(const std::string& codigo);

    // Método para mostrar todos los elementos, ordenados por el criterio dado
    void mostrarTodos(const std::string& criterio);
};

#endif // TABLAHASH_H

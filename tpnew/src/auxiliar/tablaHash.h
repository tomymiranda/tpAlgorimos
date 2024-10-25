#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "../clases/centroDeInvestigacion.h"

class TablaHash {
private:
    std::vector<std::list<CentroInvestigacion>> tabla;  // Tabla de hash con listas enlazadas
    int capacidad;  // Capacidad de la tabla de hash

    // Función de hash para obtener el índice basado en el código del centro
    int hashFunction(const std::string& codigo);

public:
    // Constructor de la tabla de hash
    TablaHash(int cap);

    // Método para insertar un centro en la tabla de hash
    void insertar(const CentroInvestigacion& centro);

    // Método para buscar un centro de investigación por su código
    bool buscar(const std::string& codigo);

    // Método para eliminar un centro de la tabla de hash por su código
    bool eliminar(const std::string& codigo);

    // Método para mostrar todos los centros, ordenados por el criterio dado
    void mostrarTodos(const std::string& criterio);
};

#endif

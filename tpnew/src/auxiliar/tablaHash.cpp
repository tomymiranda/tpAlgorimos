#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "tablaHash.h"

// Constructor de TablaHash
template <typename T>
TablaHash<T>::TablaHash(int cap) : capacidad(cap) {
    tabla.resize(capacidad);  // Inicializa con instancias de Lista de tipo T
}

// Función de hash para la tabla
template <typename T>
int TablaHash<T>::hashFunction(const std::string& codigo) {
    int hashValue = 0;
    int base = 128;
    for (size_t i = 0; i < codigo.size(); i++) {
        hashValue = hashValue * base + codigo[i];
    }
    return hashValue % capacidad;
}

// Método para insertar un elemento
template <typename T>
void TablaHash<T>::insertar(const std::string& codigo, const T& elemento) {
    int index = hashFunction(codigo);
    tabla[index].alta(elemento, tabla[index].obtener_largo());  // Inserta el elemento en la lista
}

template <typename T>
T TablaHash<T>::buscar(const std::string& codigo) {
    int index = hashFunction(codigo);  // Usa la función de hash correcta
    Lista<T>& lista = tabla[index];    // Accede a la lista en el índice calculado

    // Itera sobre la lista en la posición index para encontrar el elemento
    for (int i = 0; i < lista.obtener_largo(); ++i) {
        T elemento = lista.consulta(i);  // Obtiene una copia del elemento en la posición `i`
        if (elemento.getCodigo() == codigo) {
            return elemento;  // Devuelve una copia del objeto encontrado
        }
    }

    // Si no se encuentra, podrías lanzar una excepción o definir un objeto nulo de T
    throw std::runtime_error("Elemento no encontrado");
}



// Método para buscar si existe un elemento
template <typename T>
bool TablaHash<T>::existe(const std::string& codigo) {
    int index = hashFunction(codigo);
    Lista<T>& lista = tabla[index];  // Especifica el tipo como T

    for (int i = 0; i < lista.obtener_largo(); ++i) {
        if (lista.consulta(i).getCodigo() == codigo) {  // Asegúrate de que T tenga el método getCodigo()
            std::cout << "Código: " << lista.consulta(i).getCodigo() << std::endl;
            return true;
        }
    }
    return false;
}

// Método para eliminar un elemento
template <typename T>
bool TablaHash<T>::eliminar(const std::string& codigo) {
    int index = hashFunction(codigo);
    Lista<T>& lista = tabla[index];

    for (int i = 0; i < lista.obtener_largo(); ++i) {
        if (lista.consulta(i).getCodigo() == codigo) {
            lista.baja(i);  // Elimina el elemento
            return true;
        }
    }
    return false;
}

// Método para mostrar todos los elementos ordenados por un criterio
template <typename T>
void TablaHash<T>::mostrarTodos(const std::string& criterio) {
    std::vector<T> todosElementos;

    // Recopilar todos los elementos de la tabla hash
    for (auto& lista : tabla) {
        for (int i = 0; i < lista.obtener_largo(); ++i) {
            T centro = lista.consulta(i);

            todosElementos.push_back(centro);
        }
    }

    // Ordenar según el criterio indicado, tiene q ser una sola palabra
    if (criterio == "nombre") {
        std::sort(todosElementos.begin(), todosElementos.end(), [](const T& a, const T& b) {
            return a.getNombre() < b.getNombre();
        });
    } else if (criterio == "pais") {
        std::sort(todosElementos.begin(), todosElementos.end(), [](const T& a, const T& b) {
            return a.getPais() < b.getPais();
        });
    } else if (criterio == "superficie") {
        std::sort(todosElementos.begin(), todosElementos.end(), [](const T& a, const T& b) {
            return a.getSuperficie() < b.getSuperficie();
        });
    } else if (criterio == "laboratorio") {
        std::sort(todosElementos.begin(), todosElementos.end(), [](const T& a, const T& b) {
            return a.getNumLaboratorios() < b.getNumLaboratorios();
        });
    } else if (criterio == "nacionales") {
        std::sort(todosElementos.begin(), todosElementos.end(), [](const T& a, const T& b) {
            return a.getProyectosNacionales() < b.getProyectosNacionales();
        });
    } else if (criterio == "internacionales") {
        std::sort(todosElementos.begin(), todosElementos.end(), [](const T& a, const T& b) {
            return a.getProyectosInternacionales() < b.getProyectosInternacionales();
        });
    }

    // Mostrar todos los elementos ordenados con todos los atributos
    for (const auto& elemento : todosElementos) {
        std::cout << "Código: " << elemento.getCodigo() << ", "
                  << "Nombre: " << elemento.getNombre() << ", "
                  << "País: " << elemento.getPais() << ", "
                  << "Superficie: " << elemento.getSuperficie() << ", "
                  << "Laboratorios: " << elemento.getNumLaboratorios() << ", "
                  << "Proyectos Nacionales: " << elemento.getProyectosNacionales() << ", "
                  << "Proyectos Internacionales: " << elemento.getProyectosInternacionales()
                  << std::endl;
    }
}

// Necesario para que el compilador vea las implementaciones de la plantilla
template class TablaHash<CentroInvestigacion>;

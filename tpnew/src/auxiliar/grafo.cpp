/*
 * #include "grafo.h"
#include <iostream>
#include <vector>
#include <limits>
#include "../clases/proyectoCientifico.h"  // Asegúrate de incluir el archivo correspondiente

// Agregar un proyecto de colaboración entre centros
template <typename T>
void Grafo<T>::agregar_proyecto(const std::string& centro_origen, const std::string& centro_destino, float costo, float duracion) {
    T nuevoProyecto(centro_origen, centro_destino, costo, duracion);
    adyacencias[centro_origen].alta(nuevoProyecto, adyacencias[centro_origen].obtener_largo());
}

// Mostrar todas las colaboraciones de un centro en particular
template <typename T>
void Grafo<T>::mostrar_colaboraciones(const std::string& centro_origen) {
    if (adyacencias.find(centro_origen) == adyacencias.end()) {
        std::cout << "El centro no tiene colaboraciones registradas.\n";
        return;
    }

    std::cout << "Colaboraciones del centro " << centro_origen << ":\n";
    adyacencias[centro_origen].mostrar();  // Usamos el método mostrar() de tu Lista
}

// Buscar colaboración más económica entre dos centros
template <typename T>
void Grafo<T>::colaboracion_mas_economica(const std::string& origen, const std::string& destino) {
    if (adyacencias.find(origen) == adyacencias.end()) {
        std::cout << "No se encontraron colaboraciones para el centro de origen " << origen << ".\n";
        return;
    }

    float costoMinimo = std::numeric_limits<float>::max();
    std::vector<T> proyectosOptimos;

    // Recolectar todos los proyectos que coinciden con el centro de destino
    for (int i = 0; i < adyacencias[origen].obtener_largo(); ++i) {
        T actual = adyacencias[origen].consulta(i);
        if (actual.getCentroDestino() == destino) {
            float costoActual = actual.getCosto();
            if (costoActual < costoMinimo) {
                costoMinimo = costoActual;
                proyectosOptimos.clear(); // Limpiar proyectos óptimos anteriores
                proyectosOptimos.push_back(actual); // Agregar nuevo proyecto óptimo
            } else if (costoActual == costoMinimo) {
                proyectosOptimos.push_back(actual); // Agregar proyecto si tiene el mismo costo
            }
        }
    }

    // Mostrar resultados
    if (proyectosOptimos.empty()) {
        std::cout << "No se encontraron colaboraciones entre " << origen << " y " << destino << ".\n";
    } else {
        std::cout << "Colaboraciones más económicas encontradas:\n";
        for (const auto& proyecto : proyectosOptimos) {
            std::cout << "Proyecto: " << proyecto.getCentroOrigen() << " a " << proyecto.getCentroDestino()
                      << ", Costo: " << proyecto.getCosto() << " miles de pesos\n";
        }
        std::cout << "Costo total de la colaboración más económica: " << costoMinimo << " miles de pesos\n";
    }
}

// Buscar colaboración más rápida entre dos centros
template <typename T>
void Grafo<T>::colaboracion_mas_rapida(const std::string& origen, const std::string& destino) {
    if (adyacencias.find(origen) == adyacencias.end()) {
        std::cout << "No se encontraron colaboraciones para el centro de origen " << origen << ".\n";
        return;
    }

    float duracionMinima = std::numeric_limits<float>::max();
    std::vector<T> proyectosOptimos;

    // Recolectar todos los proyectos que coinciden con el centro de destino
    for (int i = 0; i < adyacencias[origen].obtener_largo(); ++i) {
        T actual = adyacencias[origen].consulta(i);
        if (actual.getCentroDestino() == destino) {
            float duracionActual = actual.getDuracion();
            if (duracionActual < duracionMinima) {
                duracionMinima = duracionActual;
                proyectosOptimos.clear(); // Limpiar proyectos óptimos anteriores
                proyectosOptimos.push_back(actual); // Agregar nuevo proyecto óptimo
            } else if (duracionActual == duracionMinima) {
                proyectosOptimos.push_back(actual); // Agregar proyecto si tiene la misma duración
            }
        }
    }

    // Mostrar resultados
    if (proyectosOptimos.empty()) {
        std::cout << "No se encontraron colaboraciones entre " << origen << " y " << destino << ".\n";
    } else {
        std::cout << "Colaboraciones más rápidas encontradas:\n";
        for (const auto& proyecto : proyectosOptimos) {
            std::cout << "Proyecto: " << proyecto.getCentroOrigen() << " a " << proyecto.getCentroDestino()
                      << ", Duración: " << proyecto.getDuracion() << " meses\n";
        }
        std::cout << "Duración total de la colaboración más rápida: " << duracionMinima << " meses\n";
    }
}
 * */



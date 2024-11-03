#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "lista.h"
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <queue>
#include <unordered_set>
#include "../clases/proyectoCientifico.h"

template <typename T>
class Grafo {
private:
    std::unordered_map<std::string, Lista<T>> adyacencias;  // Mapa de adyacencias

public:
    // Constructor sin parámetros
    Grafo() {}  // Constructor sin hacer nada, pero necesario

    void agregar_proyecto(const std::string& centro_origen, const std::string& centro_destino, float costo, float duracion) {
        T nuevoProyecto(centro_origen, centro_destino, costo, duracion);
        adyacencias[centro_origen].alta(nuevoProyecto, adyacencias[centro_origen].obtener_largo());
    }

    void mostrar_colaboraciones(const std::string& centro_origen) {
        if (adyacencias.find(centro_origen) == adyacencias.end()) {
            std::cout << "El centro no tiene colaboraciones registradas.\n";
            return;
        }

        std::cout << "Colaboraciones del centro " << centro_origen << ":\n";
        adyacencias[centro_origen].mostrar();  // Usamos el método mostrar() de tu Lista
    }

    void colaboracion_mas_economica(const std::string& origen, const std::string& destino) {
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
                    proyectosOptimos.clear();  // Limpiar proyectos óptimos anteriores
                    proyectosOptimos.push_back(actual);  // Agregar nuevo proyecto óptimo
                } else if (costoActual == costoMinimo) {
                    proyectosOptimos.push_back(actual);  // Agregar proyecto si tiene el mismo costo
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

    void colaboracion_mas_rapida(const std::string& origen, const std::string& destino) {
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
                    proyectosOptimos.clear();  // Limpiar proyectos óptimos anteriores
                    proyectosOptimos.push_back(actual);  // Agregar nuevo proyecto óptimo
                } else if (duracionActual == duracionMinima) {
                    proyectosOptimos.push_back(actual);  // Agregar proyecto si tiene la misma duración
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

    // Método BFS para verificar si existe un camino entre dos centros
    bool existe_camino_bfs(const std::string& origen, const std::string& destino) {
        if (adyacencias.find(origen) == adyacencias.end()) {
            return false;  // No hay colaboraciones desde el centro de origen
        }

        std::queue<std::string> cola;  // Cola para el recorrido BFS
        std::unordered_set<std::string> visitados;  // Conjunto para marcar los centros ya visitados

        cola.push(origen);           // Iniciar desde el nodo de origen
        visitados.insert(origen);    // Marcar el origen como visitado

        while (!cola.empty()) {
            std::string actual = cola.front();
            cola.pop();

            // Si el centro actual es el destino, encontramos un camino
            if (actual == destino) {
                return true;
            }

            // Obtener todos los centros conectados al centro actual
            for (int i = 0; i < adyacencias[actual].obtener_largo(); ++i) {
                T proyecto = adyacencias[actual].consulta(i);
                std::string siguienteCentro = proyecto.getCentroDestino();

                // Si no hemos visitado el centro siguiente, lo agregamos a la cola
                if (visitados.find(siguienteCentro) == visitados.end()) {
                    cola.push(siguienteCentro);
                    visitados.insert(siguienteCentro);  // Marcar como visitado
                }
            }
        }

        return false;  // No se encontró un camino al destino
    }
};

#endif // GRAFO_H_INCLUDED

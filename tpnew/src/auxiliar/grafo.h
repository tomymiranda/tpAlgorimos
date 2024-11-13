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
#include <functional>

template <typename T>
class Grafo {
private:
    std::unordered_map<std::string, Lista<T>> adyacencias;  // Mapa de adyacencias

public:
    // Constructor sin parámetros
    Grafo() {}


    // Método para agregar un proyecto al grafo, se crea un objeto del tipo proyecto y lo agrega
    void agregar_proyecto(const std::string& centro_origen, const std::string& centro_destino, float costo, float duracion) {
        T nuevoProyecto(centro_origen, centro_destino, costo, duracion);
        adyacencias[centro_origen].alta(nuevoProyecto, adyacencias[centro_origen].obtener_largo());
    }

    // Método que muestra todas las colaboracioes de un centro
    void mostrar_colaboraciones(const std::string& centro_origen) {
        if (adyacencias.find(centro_origen) == adyacencias.end()) {
            std::cout << "El centro no tiene colaboraciones registradas.\n";
            return;
        }
        std::cout << "Colaboraciones del centro " << centro_origen << ":\n";
        adyacencias[centro_origen].mostrar();
    }

    // Método para encontrar el camino de colaboración más económico
    void colaboracion_mas_economica(const std::string& origen, const std::string& destino) {
        if (adyacencias.find(origen) == adyacencias.end()) {
            std::cout << "No se encontraron colaboraciones para el centro de origen " << origen << ".\n";
            return;
        }

        // Cola de prioridad, que almacena (costoAcumulado, centroActual, camino).
        using Estado = std::tuple<float, std::string, std::vector<T>>;
        std::priority_queue<Estado, std::vector<Estado>, std::greater<>> cola;

        // Mapa para almacenar el menor costo acumulado a cada centro.
        std::unordered_map<std::string, float> costoMinimo;
        costoMinimo[origen] = 0.0;

        // Insertamos el nodo inicial en la cola.
        cola.push({0.0, origen, {}});

        // Variable para guardar el camino óptimo final
        std::vector<T> caminoOptimo;

        while (!cola.empty()) {
            auto [costoAcumulado, centroActual, camino] = cola.top();
            cola.pop();

            // Si llegamos al destino, guardamos el camino óptimo y terminamos.
            if (centroActual == destino) {
                caminoOptimo = camino;
                break;
            }

            // Explorar los proyectos adyacentes del centro actual
            for (int i = 0; i < adyacencias[centroActual].obtener_largo(); ++i) {
                T proyecto = adyacencias[centroActual].consulta(i);
                std::string siguienteCentro = proyecto.getCentroDestino();
                float nuevoCostoAcumulado = costoAcumulado + proyecto.getCosto();

                // Verificar si encontramos un camino más económico al siguiente centro
                if (costoMinimo.find(siguienteCentro) == costoMinimo.end() || nuevoCostoAcumulado < costoMinimo[siguienteCentro]) {
                    costoMinimo[siguienteCentro] = nuevoCostoAcumulado;
                    std::vector<T> nuevoCamino = camino;
                    nuevoCamino.push_back(proyecto);
                    cola.push({nuevoCostoAcumulado, siguienteCentro, nuevoCamino});
                }
            }
        }

        // Mostrar el resultado
        if (caminoOptimo.empty()) {
            std::cout << "No se encontraron colaboraciones entre " << origen << " y " << destino << ".\n";
        } else {
            std::cout << "Camino de colaboración más económico encontrado:\n";
            for (const auto& proyecto : caminoOptimo) {
                std::cout << "Proyecto: " << proyecto.getCentroOrigen() << " a " << proyecto.getCentroDestino()
                          << ", Costo: " << proyecto.getCosto() << " miles de pesos\n";
            }
            std::cout << "Costo total de la colaboración más económica: " << costoMinimo[destino] << " miles de pesos\n";
        }
    }
    // Método para encontrar el camino de colaboración más rápida
    void colaboracion_mas_rapida(const std::string& origen, const std::string& destino) {
        if (adyacencias.find(origen) == adyacencias.end()) {
            std::cout << "No se encontraron colaboraciones para el centro de origen " << origen << ".\n";
            return;
        }

        // Cola de prioridad que almacena (duracionAcumulada, centroActual, camino).
        using Estado = std::tuple<float, std::string, std::vector<T>>;
        std::priority_queue<Estado, std::vector<Estado>, std::greater<>> cola;

        // Mapa para almacenar la menor duración acumulada a cada centro.
        std::unordered_map<std::string, float> duracionMinima;
        duracionMinima[origen] = 0.0;

        // Insertamos el nodo inicial en la cola.
        cola.push({0.0, origen, {}});

        // Variable para guardar el camino óptimo final.
        std::vector<T> caminoOptimo;

        while (!cola.empty()) {
            auto [duracionAcumulada, centroActual, camino] = cola.top();
            cola.pop();

            // Si llegamos al destino, guardamos el camino óptimo y terminamos.
            if (centroActual == destino) {
                caminoOptimo = camino;
                break;
            }

            // Explorar los proyectos adyacentes del centro actual.
            for (int i = 0; i < adyacencias[centroActual].obtener_largo(); ++i) {
                T proyecto = adyacencias[centroActual].consulta(i);
                std::string siguienteCentro = proyecto.getCentroDestino();
                float nuevaDuracionAcumulada = duracionAcumulada + proyecto.getDuracion();

                // Verificar si encontramos un camino más rápido al siguiente centro.
                if (duracionMinima.find(siguienteCentro) == duracionMinima.end() || nuevaDuracionAcumulada < duracionMinima[siguienteCentro]) {
                    duracionMinima[siguienteCentro] = nuevaDuracionAcumulada;
                    std::vector<T> nuevoCamino = camino;
                    nuevoCamino.push_back(proyecto);
                    cola.push({nuevaDuracionAcumulada, siguienteCentro, nuevoCamino});
                }
            }
        }

        // Mostrar el resultado.
        if (caminoOptimo.empty()) {
            std::cout << "No se encontraron colaboraciones entre " << origen << " y " << destino << ".\n";
        } else {
            std::cout << "Camino de colaboración más rápida encontrado:\n";
            for (const auto& proyecto : caminoOptimo) {
                std::cout << "Proyecto: " << proyecto.getCentroOrigen() << " a " << proyecto.getCentroDestino()
                          << ", Duración: " << proyecto.getDuracion() << " meses\n";
            }
            std::cout << "Duración total de la colaboración más rápida: " << duracionMinima[destino] << " meses\n";
        }
    }

    // Método BFS para verificar si existe un camino entre dos centros
    bool existe_camino_bfs(const std::string& origen, const std::string& destino) {
        if (adyacencias.find(origen) == adyacencias.end()) {
            return false;
        }

        std::queue<std::string> cola;
        std::unordered_set<std::string> visitados;

        cola.push(origen);
        visitados.insert(origen);

        while (!cola.empty()) {
            std::string actual = cola.front();
            cola.pop();

            if (actual == destino) {
                return true;
            }

            for (int i = 0; i < adyacencias[actual].obtener_largo(); ++i) {
                T proyecto = adyacencias[actual].consulta(i);
                std::string siguienteCentro = proyecto.getCentroDestino();

                if (visitados.find(siguienteCentro) == visitados.end()) {
                    cola.push(siguienteCentro);
                    visitados.insert(siguienteCentro);
                }
            }
        }

        return false;
    }
};

#endif // GRAFO_H_INCLUDED

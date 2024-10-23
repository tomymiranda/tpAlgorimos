#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <unordered_map>
#include "lista.h"  
#include "proyectoCientifico.h" 
class Grafo {
private:
    std::unordered_map<std::string, Lista> adyacencias; // Cada centro tiene una lista de proyectos

public:
    // Constructor
    Grafo();

    // Agregar un proyecto de colaboración entre centros
    void agregar_proyecto(const std::string& centro_origen, const std::string& centro_destino, float costo, float duracion);

    // Mostrar todas las colaboraciones de un centro en particular
    void mostrar_colaboraciones(const std::string& centro_origen);

    // Buscar colaboración más económica entre dos centros
    void colaboracion_mas_economica(const std::string& origen, const std::string& destino);

    // Buscar colaboración más rápida entre dos centros
    void colaboracion_mas_rapida(const std::string& origen, const std::string& destino);
};

#endif // GRAFO_H

#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "lista.h"  // Esto debe estar bien definido
#include <string>
#include <unordered_map>

class Grafo {
private:
    std::unordered_map<std::string, Lista> adyacencias;

public:
    Grafo();
    void agregar_proyecto(const std::string& centro_origen, const std::string& centro_destino, float costo, float duracion);
    void mostrar_colaboraciones(const std::string& centro_origen);
    void colaboracion_mas_economica(const std::string& origen, const std::string& destino);
    void colaboracion_mas_rapida(const std::string& origen, const std::string& destino);
};

#endif // GRAFO_H_INCLUDED

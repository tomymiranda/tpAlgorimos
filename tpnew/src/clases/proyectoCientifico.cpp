#include "proyecto_cientifico.h"
#include <iostream>

// Constructor por defecto
ProyectoCientifico::ProyectoCientifico() : centro_origen(""), centro_destino(""), costo(0), duracion(0) {}

// Constructor con parámetros
ProyectoCientifico::ProyectoCientifico(const std::string& origen, const std::string& destino, float costo, float duracion)
    : centro_origen(origen), centro_destino(destino), costo(costo), duracion(duracion) {}

// Getters
std::string ProyectoCientifico::obtener_centro_origen() const {
    return centro_origen;
}

std::string ProyectoCientifico::obtener_centro_destino() const {
    return centro_destino;
}

float ProyectoCientifico::obtener_costo() const {
    return costo;
}

float ProyectoCientifico::obtener_duracion() const {
    return duracion;
}

// Setters
void ProyectoCientifico::establecer_centro_origen(const std::string& origen) {
    centro_origen = origen;
}

void ProyectoCientifico::establecer_centro_destino(const std::string& destino) {
    centro_destino = destino;
}

void ProyectoCientifico::establecer_costo(float nuevo_costo) {
    costo = nuevo_costo;
}

void ProyectoCientifico::establecer_duracion(float nueva_duracion) {
    duracion = nueva_duracion;
}

// Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& out, const ProyectoCientifico& proyecto) {
    out << "Centro Origen: " << proyecto.centro_origen << "\n"
        << "Centro Destino: " << proyecto.centro_destino << "\n"
        << "Costo: " << proyecto.costo << " miles de pesos\n"
        << "Duración: " << proyecto.duracion << " meses\n";
    return out;
}

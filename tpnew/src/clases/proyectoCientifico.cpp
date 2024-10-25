#include "proyectoCientifico.h"
#include <iostream>

// Constructor por defecto
ProyectoCientifico::ProyectoCientifico() : centro_origen(""), centro_destino(""), costo(0), duracion(0) {}

// Constructor con parámetros
ProyectoCientifico::ProyectoCientifico(const std::string& origen, const std::string& destino, float costo, float duracion)
    : centro_origen(origen), centro_destino(destino), costo(costo), duracion(duracion) {}

// Getters
std::string ProyectoCientifico::getCentroOrigen() const {
    return centro_origen;
}

std::string ProyectoCientifico::getCentroDestino() const {
    return centro_destino;
}

float ProyectoCientifico::getCosto() const {
    return costo;
}

float ProyectoCientifico::getDuracion() const {
    return duracion;
}

// Setters
void ProyectoCientifico::setCentroOrigen(const std::string& origen) {
    centro_origen = origen;
}

void ProyectoCientifico::setCentroDestino(const std::string& destino) {
    centro_destino = destino;
}

void ProyectoCientifico::setCosto(float nuevo_costo) {
    costo = nuevo_costo;
}

void ProyectoCientifico::setDuracion(float nueva_duracion) {
    duracion = nueva_duracion;
}

// Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& out, const ProyectoCientifico& proyecto) {
    out << "Centro Origen: " << proyecto.getCentroOrigen() << "\n"
        << "Centro Destino: " << proyecto.getCentroDestino() << "\n"
        << "Costo: " << proyecto.getCosto() << " miles de pesos\n"
        << "Duración: " << proyecto.getDuracion() << " meses\n";
    return out;
}

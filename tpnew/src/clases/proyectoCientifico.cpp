#include "proyectoCientifico.h"
#include <iostream>

// Constructor de Proyecto Científico
ProyectoCientifico::ProyectoCientifico(const std::string& origen, const std::string& destino, float costo, float duracion)
    : centro_origen(origen), centro_destino(destino), costo(costo), duracion(duracion) {}

// Método para obtener centro de origen
std::string ProyectoCientifico::getCentroOrigen() const {
    return centro_origen;
}
// Método para obtener centro de destino
std::string ProyectoCientifico::getCentroDestino() const {
    return centro_destino;
}

// Método para obtener el costo del proyecto
float ProyectoCientifico::getCosto() const {
    return costo;
}
// Método para obtener la duración del proyecto
float ProyectoCientifico::getDuracion() const {
    return duracion;
}

// Método para settear el centro de origen del proyecto
void ProyectoCientifico::setCentroOrigen(const std::string& origen) {
    centro_origen = origen;
}
// Método para settear el centro de destino del proyecto
void ProyectoCientifico::setCentroDestino(const std::string& destino) {
    centro_destino = destino;
}
// Método para settear el costo del proyecto
void ProyectoCientifico::setCosto(float nuevo_costo) {
    costo = nuevo_costo;
}
// Método para settear la duración del proyecto
void ProyectoCientifico::setDuracion(float nueva_duracion) {
    duracion = nueva_duracion;
}
// Método para comparar y ordenar por duración
bool ProyectoCientifico::operator<(const ProyectoCientifico& otro) const {
    return this->getDuracion() > otro.getDuracion();  // Ordenar por duración de menor a mayor
}

// Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& out, const ProyectoCientifico& proyecto) {
    out << "Centro Origen: " << proyecto.getCentroOrigen() << "\n"
        << "Centro Destino: " << proyecto.getCentroDestino() << "\n"
        << "Costo: " << proyecto.getCosto() << " miles de pesos\n"
        << "Duración: " << proyecto.getDuracion() << " meses\n";
    return out;
}

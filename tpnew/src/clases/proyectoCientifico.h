#ifndef PROYECTO_CIENTIFICO_H
#define PROYECTO_CIENTIFICO_H

#include <string>
#include <ostream>

class ProyectoCientifico {
private:
    std::string centro_origen;    // Código del centro de origen
    std::string centro_destino;   // Código del centro de destino
    float costo;                  // Costo del proyecto en miles de pesos
    float duracion;               // Duración del proyecto en meses

public:
    // Constructor por defecto
    ProyectoCientifico();

    // Constructor con parámetros
    ProyectoCientifico(const std::string& origen, const std::string& destino, float costo, float duracion);

    // Getters
    std::string getCentroOrigen() const;
    std::string getCentroDestino() const;
    float getCosto() const;
    float getDuracion() const;

    // Setters
    void setCentroOrigen(const std::string& origen);
    void setCentroDestino(const std::string& destino);
    void setCosto(float nuevo_costo);
    void setDuracion(float nueva_duracion);

    // Sobrecarga del operador de salida para imprimir el proyecto
    friend std::ostream& operator<<(std::ostream& out, const ProyectoCientifico& proyecto);
};

#endif  // PROYECTO_CIENTIFICO_H

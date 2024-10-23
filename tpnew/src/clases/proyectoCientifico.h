#ifndef PROYECTO_CIENTIFICO_H
#define PROYECTO_CIENTIFICO_H

#include <string>
#include <iostream>

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
    std::string obtener_centro_origen() const;
    std::string obtener_centro_destino() const;
    float obtener_costo() const;
    float obtener_duracion() const;

    // Setters
    void establecer_centro_origen(const std::string& origen);
    void establecer_centro_destino(const std::string& destino);
    void establecer_costo(float nuevo_costo);
    void establecer_duracion(float nueva_duracion);

    // Sobrecarga del operador de salida para imprimir el proyecto
    friend std::ostream& operator<<(std::ostream& out, const ProyectoCientifico& proyecto);
};

#endif  // PROYECTO_CIENTIFICO_H

#ifndef CENTRO_DE_INVESTIGACION_H
#define CENTRO_DE_INVESTIGACION_H

#include <string>
#include <ostream>  // Incluir para usar std::ostream

class CentroInvestigacion {
private:
    std::string codigo;
    std::string nombre;
    std::string pais;
    float superficie;
    int num_laboratorios;
    int proyectos_nacionales;
    int proyectos_internacionales;

public:
    CentroInvestigacion(const std::string& codigo, const std::string& nombre,
                        const std::string& pais,
                        float superficie, int num_laboratorios,
                        int proyectos_nacionales, int proyectos_internacionales);

    // Getters
    std::string getCodigo() const;
    std::string getNombre() const;
    std::string getPais() const;
    float getSuperficie() const;
    int getNumLaboratorios() const;
    int getProyectosNacionales() const;
    int getProyectosInternacionales() const;

    // Sobrecarga del operador de salida para imprimir un centro
    friend std::ostream& operator<<(std::ostream& out, const CentroInvestigacion& centro);
};

#endif  // CENTRO_DE_INVESTIGACION_H

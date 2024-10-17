#ifndef CENTRO_DE_INVESTIGACION_H
#define CENTRO_DE_INVESTIGACION_H

#include <string>

class CentroInvestigacion {
private:
    std::string codigo;
    std::string nombre;
    std::string ciudad;
    std::string pais;
    float superficie;
    int num_laboratorios;
    int proyectos_nacionales;
    int proyectos_internacionales;

public:
    CentroInvestigacion(const std::string& codigo, const std::string& nombre,
                        const std::string& ciudad, const std::string& pais,
                        float superficie, int num_laboratorios,
                        int proyectos_nacionales, int proyectos_internacionales);

    std::string getCodigo() const;
    std::string getNombre() const;
    std::string getCiudad() const;
    std::string getPais() const;
    float getSuperficie() const;
    int getNumLaboratorios() const;
    int getProyectosNacionales() const;
    int getProyectosInternacionales() const;
};

#endif  // CENTRO_DE_INVESTIGACION_H

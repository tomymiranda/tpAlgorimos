#include "centroDeInvestigacion.h"
#include <iostream>

// Constructor de Centro de Investigación
CentroInvestigacion::CentroInvestigacion(const std::string& codigo, const std::string& nombre,
                                          const std::string& pais,
                                         float superficie, int num_laboratorios,
                                         int proyectos_nacionales, int proyectos_internacionales)
    : codigo(codigo), nombre(nombre), pais(pais), superficie(superficie),
      num_laboratorios(num_laboratorios), proyectos_nacionales(proyectos_nacionales),
      proyectos_internacionales(proyectos_internacionales) {}

// Métodos getters de Centro de Investigación
std::string CentroInvestigacion::getCodigo() const { return codigo; }
std::string CentroInvestigacion::getNombre() const { return nombre; }
std::string CentroInvestigacion::getPais() const { return pais; }
float CentroInvestigacion::getSuperficie() const { return superficie; }
int CentroInvestigacion::getNumLaboratorios() const { return num_laboratorios; }
int CentroInvestigacion::getProyectosNacionales() const { return proyectos_nacionales; }
int CentroInvestigacion::getProyectosInternacionales() const { return proyectos_internacionales; }

// Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& out, const CentroInvestigacion& centro) {
    out << "Código: " << centro.codigo << "\n"
        << "Nombre: " << centro.nombre << "\n"
        << "País: " << centro.pais << "\n"
        << "Superficie: " << centro.superficie << " m²\n"
        << "Número de Laboratorios: " << centro.num_laboratorios << "\n"
        << "Proyectos Nacionales: " << centro.proyectos_nacionales << "\n"
        << "Proyectos Internacionales: " << centro.proyectos_internacionales << "\n";
    return out;
}

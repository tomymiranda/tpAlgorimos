#include "lector.h"
#include <fstream>
#include <iostream>
#include <sstream>

LectorArchivo::LectorArchivo(const std::string& archivo)
    : nombreArchivo(archivo) {}

std::vector<CentroInvestigacion> LectorArchivo::leerArchivo() {
    std::ifstream archivo(nombreArchivo);
    std::vector<CentroInvestigacion> centros;

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return centros;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        CentroInvestigacion centro = crearCentroDesdeLinea(linea);
        centros.emplace_back(centro);
    }

    archivo.close();
    return centros;
}

CentroInvestigacion LectorArchivo::crearCentroDesdeLinea(const std::string& linea) {
    std::istringstream ss(linea);
    std::string codigo, nombre, ciudad, pais;
    float superficie;
    int num_laboratorios, proyectos_nacionales, proyectos_internacionales;

    ss >> codigo >> nombre >> ciudad >> pais >> superficie
       >> num_laboratorios >> proyectos_nacionales >> proyectos_internacionales;

    return CentroInvestigacion(codigo, nombre, ciudad, pais, superficie,
                               num_laboratorios, proyectos_nacionales,
                               proyectos_internacionales);
}

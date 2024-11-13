#include "lector.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Constructor
LectorArchivo::LectorArchivo(const std::string& archivo)
    : nombreArchivo(archivo) {}

void LectorArchivo::imprimirNombreArchivo() const {
    std::cout << "Nombre del archivo: " << nombreArchivo << std::endl;
}

// Leer archivos de centros
std::vector<CentroInvestigacion> LectorArchivo::leerArchivoCentros() {
    std::vector<CentroInvestigacion> centros;

    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return centros;
    }

    std::cout << "Archivo " << nombreArchivo << " abierto correctamente." << std::endl;

    std::string linea;
    bool hayDatos = false;
    while (std::getline(archivo, linea)) {
        if (!linea.empty()) {
            hayDatos = true;
            CentroInvestigacion centro = crearCentroDesdeLinea(linea);
            centros.emplace_back(centro);
        }
    }

    archivo.close();

    if (hayDatos) {
        std::cout << "Se leyeron " << centros.size() << " centros del archivo." << std::endl;
    } else {
        std::cout << "El archivo está vacío o no contiene datos válidos." << std::endl;
    }

    return centros;
}

// Leer archivos de proyectos
std::vector<ProyectoCientifico> LectorArchivo::leerArchivoProyectos() {
    std::vector<ProyectoCientifico> proyectos;

    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return proyectos;
    }

    std::cout << "Archivo de proyectos " << nombreArchivo << " abierto correctamente." << std::endl;

    std::string linea;
    bool hayDatos = false;
    while (std::getline(archivo, linea)) {
        if (!linea.empty()) {
            hayDatos = true;
            ProyectoCientifico proyecto = crearProyectoDesdeLinea(linea);
            proyectos.emplace_back(proyecto);
        }
    }

    archivo.close();

    if (hayDatos) {
        std::cout << "Se leyeron " << proyectos.size() << " proyectos del archivo." << std::endl;
    } else {
        std::cout << "El archivo está vacío o no contiene datos válidos." << std::endl;
    }

    return proyectos;
}

// Crear un objeto CentroInvestigacion a partir de una línea
CentroInvestigacion LectorArchivo::crearCentroDesdeLinea(const std::string& linea) {
    std::istringstream ss(linea);
    std::string codigo, nombre, ciudad, pais;
    float superficie;
    int num_laboratorios, proyectos_nacionales, proyectos_internacionales;

    // Leer los campos usando ';' como delimitador
    std::getline(ss, codigo, ';');
    std::getline(ss, nombre, ';');
    std::getline(ss, pais, ';');
    ss >> superficie;
    ss.ignore(1, ';');  // Ignorar el punto y coma
    ss >> num_laboratorios;
    ss.ignore(1, ';');
    ss >> proyectos_nacionales;
    ss.ignore(1, ';');
    ss >> proyectos_internacionales;

    // Limpiar posibles espacios en blanco al inicio o final de los campos
    nombre.erase(0, nombre.find_first_not_of(" "));
    nombre.erase(nombre.find_last_not_of(" ") + 1);
    pais.erase(0, pais.find_first_not_of(" "));
    pais.erase(pais.find_last_not_of(" ") + 1);

    return CentroInvestigacion(codigo, nombre, pais, superficie,
                               num_laboratorios, proyectos_nacionales,
                               proyectos_internacionales);
}


// Crear un objeto ProyectoCientifico a partir de una línea
ProyectoCientifico LectorArchivo::crearProyectoDesdeLinea(const std::string& linea) {
    std::istringstream ss(linea);
    std::string origen, destino, costoStr, duracionStr;
    float costo = 0.0, duracion = 0.0;

    // Leer origen y destino usando punto y coma como delimitador
    std::getline(ss, origen, ';');
    std::getline(ss, destino, ';');
    std::getline(ss, costoStr, ';');   // Leer costo como string
    std::getline(ss, duracionStr, ';'); // Leer duracion como string

    // Convertir costo y duracion de string a float
    try {
        costo = std::stof(costoStr);
        duracion = std::stof(duracionStr);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Conversión inválida en la línea: " << linea << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Valor fuera de rango en la línea: " << linea << std::endl;
    }

    // Limpiar espacios adicionales al principio y al final de origen y destino
    origen.erase(0, origen.find_first_not_of(" "));
    origen.erase(origen.find_last_not_of(" ") + 1);
    destino.erase(0, destino.find_first_not_of(" "));
    destino.erase(destino.find_last_not_of(" ") + 1);

    return ProyectoCientifico(origen, destino, costo, duracion);
}


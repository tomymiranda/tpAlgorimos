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

    // Verificar si el archivo se abre correctamente
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return centros;
    }

    std::cout << "Archivo " << nombreArchivo << " abierto correctamente." << std::endl; // Mensaje de éxito

    // Leer líneas del archivo y verificar si hay contenido
    std::string linea;
    bool hayDatos = false; // Variable para verificar si hay datos
    while (std::getline(archivo, linea)) {
        if (!linea.empty()) { // Solo procesar líneas no vacías
            hayDatos = true; // Marcamos que hay datos
            CentroInvestigacion centro = crearCentroDesdeLinea(linea);
            centros.emplace_back(centro);
        }
    }

    archivo.close();

    // Comprobación de datos leídos
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

    // Verificar si el archivo se abre correctamente
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return proyectos;
    }

    std::cout << "Archivo de proyectos " << nombreArchivo << " abierto correctamente." << std::endl;

    std::string linea;
    bool hayDatos = false; // Variable para verificar si hay datos
    while (std::getline(archivo, linea)) {
        if (!linea.empty()) { // Solo procesar líneas no vacías
            hayDatos = true; // Marcamos que hay datos
            ProyectoCientifico proyecto = crearProyectoDesdeLinea(linea);
            proyectos.emplace_back(proyecto);
        }
    }

    archivo.close();

    // Comprobación de datos leídos
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

    ss >> codigo;
    std::getline(ss, nombre, ';'); // Leer el nombre completo hasta el siguiente punto y coma
    ss >> ciudad >> pais >> superficie
       >> num_laboratorios >> proyectos_nacionales >> proyectos_internacionales;

    // Asegúrate de que el nombre no tenga un espacio adicional al principio
    nombre.erase(0, nombre.find_first_not_of(" ")); // Eliminar espacios en blanco al principio

    return CentroInvestigacion(codigo, nombre, ciudad, pais, superficie,
                               num_laboratorios, proyectos_nacionales,
                               proyectos_internacionales);
}


// Crear un objeto ProyectoCientifico a partir de una línea
ProyectoCientifico LectorArchivo::crearProyectoDesdeLinea(const std::string& linea) {
    std::istringstream ss(linea);
    std::string origen, destino;
    float costo, duracion;

    // Leer los dos primeros campos (origen y destino) usando getline
    std::getline(ss, origen, ';'); // Usar punto y coma como delimitador
    std::getline(ss, destino, ';'); // Usar punto y coma como delimitador
    ss >> costo >> duracion; // Leer costo y duración

    // Asegúrate de que 'origen' y 'destino' no tengan espacios en blanco al principio
    origen.erase(0, origen.find_first_not_of(" "));
    destino.erase(0, destino.find_first_not_of(" "));

    return ProyectoCientifico(origen, destino, costo, duracion);
}


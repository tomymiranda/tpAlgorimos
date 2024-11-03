#include "menu.h"
#include "../auxiliar/grafo.h"
#include "../auxiliar/tablaHash.h"
#include "../lector/lector.h"
#include <vector>
#include <fstream>
#include <sstream>

// Constructor: inicializa el grafo y carga los datos de los archivos
Menu::Menu(const std::string& archivo_centros, const std::string& archivo_proyectos)
    : grafo(),    // Inicialización de grafo sin parámetros, asumiendo que tiene un constructor sin parámetros
      tabla(10) { // Inicialización de tabla con una capacidad de 10
    cargar_centros(archivo_centros);
    cargar_proyectos(archivo_proyectos);
}

// Método principal para iniciar el menú interactivo
void Menu::iniciar() {
    int opcion;
    do {
        mostrar_menu();
        std::cin >> opcion;
        procesar_opcion(opcion);
    } while (opcion != 0);
}

// Mostrar el menú de opciones
void Menu::mostrar_menu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Mostrar colaboraciones de un centro\n";
    std::cout << "2. Buscar colaboración más económica\n";
    std::cout << "3. Buscar colaboración más rápida\n";
    std::cout << "0. Salir\n";
    std::cout << "Elija una opción: ";
}

// Procesar la opción elegida por el usuario
void Menu::procesar_opcion(int opcion) {
    switch (opcion) {
        case 1: {
            std::string centro;
            std::cout << "Ingrese el código del centro: ";
            std::cin >> centro;
            grafo.mostrar_colaboraciones(centro);
            break;
        }
        case 2: {
            std::string origen, destino;
            std::cout << "Ingrese el centro de origen: ";
            std::cin >> origen;
            std::cout << "Ingrese el centro de destino: ";
            std::cin >> destino;
            grafo.colaboracion_mas_economica(origen, destino);
            break;
        }
        case 3: {
            std::string origen, destino;
            std::cout << "Ingrese el centro de origen: ";
            std::cin >> origen;
            std::cout << "Ingrese el centro de destino: ";
            std::cin >> destino;
            grafo.colaboracion_mas_rapida(origen, destino);
            break;
        }
        case 0:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opción no válida. Por favor, intente nuevamente.\n";
            break;
    }
}

// Cargar centros desde el archivo utilizando LectorArchivo
void Menu::cargar_centros(const std::string& archivo_centros) {
    LectorArchivo lector(archivo_centros);
    lector.imprimirNombreArchivo();  // Muestra el nombre del archivo si es necesario

    for (const auto& centro : lector.leerArchivoCentros()) {  // Itera directamente sobre los centros leídos
    	tabla.insertar(centro.getCodigo(), centro);  // Agrega cada centro a la tabla de hash
        std::cout << "Centro cargado: " << centro.getCodigo() << " - " << centro.getNombre()
                  << " en " << centro.getCiudad() << ", " << centro.getPais() << "\n";
    }
}


void Menu::cargar_proyectos(const std::string& archivo_proyectos) {
    LectorArchivo lector(archivo_proyectos); // Crear una instancia de LectorArchivo

    for (const auto& proyecto : lector.leerArchivoProyectos()) { // Itera directamente sobre los proyectos leídos
        grafo.agregar_proyecto(proyecto.getCentroOrigen(), proyecto.getCentroDestino(),
                               proyecto.getCosto(), proyecto.getDuracion()); // Agregar el proyecto al grafo
        std::cout << "Proyecto cargado: " << proyecto.getCentroOrigen() << " -> " << proyecto.getCentroDestino()
                  << " con costo: " << proyecto.getCosto() << " y duración: " << proyecto.getDuracion() << "\n";
    }
}


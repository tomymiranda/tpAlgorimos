#include "menu.h"  // Asegúrate de incluir el encabezado correspondiente
#include "../auxiliar/grafo.h"
#include "../lector/lector.h"
#include <vector>
#include <fstream>
#include <sstream>

// Constructor: inicializa el grafo y carga los datos de los archivos
Menu::Menu(const std::string& archivo_centros, const std::string& archivo_proyectos) {
    cargar_centros(archivo_centros);  // Esta función sigue siendo necesaria para cargar centros si se utiliza
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
    lector.imprimirNombreArchivo();// Crear una instancia de LectorArchivo
    std::vector<CentroInvestigacion> centros = lector.leerArchivoCentros(); // Leer los centros

    for (const auto& centro : centros) {
        std::cout << "Centro cargado: " << centro.getCodigo() << " - " << centro.getNombre()
                  << " en " << centro.getCiudad() << ", " << centro.getPais() << "\n";
    }
}

// Cargar proyectos desde el archivo utilizando LectorArchivo
void Menu::cargar_proyectos(const std::string& archivo_proyectos) {
    LectorArchivo lector(archivo_proyectos); // Crear una instancia de LectorArchivo
    std::vector<ProyectoCientifico> proyectos = lector.leerArchivoProyectos(); // Leer los proyectos

    for (const auto& proyecto : proyectos) {
        grafo.agregar_proyecto(proyecto.getCentroOrigen(), proyecto.getCentroDestino(), proyecto.getCosto(), proyecto.getDuracion()); // Agregar el proyecto al grafo
        std::cout << "Proyecto cargado: " << proyecto.getCentroOrigen() << " -> " << proyecto.getCentroDestino()
                  << " con costo: " << proyecto.getCosto() << " y duración: " << proyecto.getDuracion() << "\n";
    }
}

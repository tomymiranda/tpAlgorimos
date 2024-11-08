#include "menu.h"
#include "../auxiliar/grafo.h"
#include "../auxiliar/tablaHash.h"
#include "../lector/lector.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

bool Menu::esPrimo(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Función para encontrar el siguiente número primo mayor o igual a un número dado
int Menu::siguientePrimo(int num) {
    while (!esPrimo(num)) {
        ++num;
    }
    return num;
}

// Función para contar la cantidad de centros en el archivo
int Menu::contar_centros(const std::string& archivo_centros) {
    std::ifstream archivo(archivo_centros);
    int contador = 0;
    std::string linea;
    while (std::getline(archivo, linea)) {
        if (!linea.empty()) {
            ++contador;
        }
    }
    return contador;
}
// Constructor: inicializa el grafo y carga los datos de los archivos
Menu::Menu(const std::string& archivo_centros, const std::string& archivo_proyectos)
    : grafo(),
      tabla(siguientePrimo(contar_centros(archivo_centros))) { // Inicializa con el primo mayor o igual a la cantidad de centros
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
    std::cout << "1. Consultar por un centro de investigación\n";
    std::cout << "2. Agregar un nuevo centro de investigación\n";
    std::cout << "3. Eliminar un centro de investigación\n";
    std::cout << "4. Mostrar todos los centros de investigación ordenados\n";
    std::cout << "5. Mostrar colaboraciones de un centro\n";
    std::cout << "6. Buscar colaboración más económica\n";
    std::cout << "7. Buscar colaboración más rápida\n";
    std::cout << "0. Salir\n";
    std::cout << "Elija una opción: ";
}

// Procesar la opción elegida por el usuario
void Menu::procesar_opcion(int opcion) {
    switch (opcion) {
        case 1:
            consultar_centro();
            break;
        case 2:
            agregar_centro();
            break;
        case 3:
            eliminar_centro();
            break;
        case 4:
            mostrar_todos_los_centros();
            break;
        case 5: {
            std::string centro;
            std::cout << "Ingrese el código del centro: ";
            std::cin >> centro;
            grafo.mostrar_colaboraciones(centro);
            break;
        }
        case 6: {
            std::string origen, destino;
            std::cout << "Ingrese el centro de origen: ";
            std::cin >> origen;
            std::cout << "Ingrese el centro de destino: ";
            std::cin >> destino;
            grafo.colaboracion_mas_economica(origen, destino);
            break;
        }
        case 7: {
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

// Consultar un centro de investigación en particular
void Menu::consultar_centro() {
    std::string codigo;
    std::cout << "Ingrese el código del centro de investigación: ";
    std::cin >> codigo;

    try {
        CentroInvestigacion centro = tabla.buscar(codigo);  // Llamada a `buscar` devuelve un objeto temporal

        std::cout << "Centro encontrado:\n";
        std::cout << "Código: " << centro.getCodigo() << "\n"
                  << "Nombre: " << centro.getNombre() << "\n"
                  << "País: " << centro.getPais() << "\n"
                  << "Superficie: " << centro.getSuperficie() << "\n"
                  << "Laboratorios: " << centro.getNumLaboratorios() << "\n"
                  << "Proyectos Nacionales: " << centro.getProyectosNacionales() << "\n"
                  << "Proyectos Internacionales: " << centro.getProyectosInternacionales() << "\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Centro no encontrado: " << e.what() << std::endl;
    }
}

// Agregar un nuevo centro de investigación
void Menu::agregar_centro() {
    std::string codigo, nombre, pais;
    float superficie;
    int num_laboratorios, proyectos_nacionales, proyectos_internacionales;

    std::cout << "Ingrese el código del centro: ";
    std::cin >> codigo;
    std::cout << "Ingrese el nombre del centro: ";
    std::cin.ignore();  // Limpiar el buffer
    std::getline(std::cin, nombre);
    std::cout << "Ingrese el país del centro: ";
    std::getline(std::cin, pais);
    std::cout << "Ingrese la superficie del centro (en m2): ";
    std::cin >> superficie;
    std::cout << "Ingrese el número de laboratorios: ";
    std::cin >> num_laboratorios;
    std::cout << "Ingrese el número de proyectos nacionales: ";
    std::cin >> proyectos_nacionales;
    std::cout << "Ingrese el número de proyectos internacionales: ";
    std::cin >> proyectos_internacionales;

    // Crear el nuevo centro de investigación con todos los datos proporcionados
    CentroInvestigacion nuevo_centro(codigo, nombre, pais, superficie, num_laboratorios, proyectos_nacionales, proyectos_internacionales);

    // Insertar el nuevo centro en la tabla hash
    tabla.insertar(codigo, nuevo_centro);
    std::cout << "Centro agregado exitosamente.\n";
}

// Eliminar un centro de investigación
void Menu::eliminar_centro() {
    std::string codigo;
    std::cout << "Ingrese el código del centro de investigación a eliminar: ";
    std::cin >> codigo;

    if (tabla.eliminar(codigo)) {
        std::cout << "Centro eliminado exitosamente.\n";
    } else {
        std::cout << "Centro no encontrado.\n";
    }
}

// Mostrar todos los centros de investigación ordenados
void Menu::mostrar_todos_los_centros() {
    std::string criterio;
    std::cout << "Ingrese el criterio de ordenamiento (nombre, pais, superficie): ";
    std::cin >> criterio;

    tabla.mostrarTodos(criterio);
}

// Cargar centros desde el archivo utilizando LectorArchivo
void Menu::cargar_centros(const std::string& archivo_centros) {
    LectorArchivo lector(archivo_centros);
    lector.imprimirNombreArchivo();  // Muestra el nombre del archivo si es necesario

    for (const auto& centro : lector.leerArchivoCentros()) {  // Itera directamente sobre los centros leídos
        // Verificación de los valores del centro antes de insertarlo
        std::cout << "Depuración: Leyendo centro: "
                  << "Código: " << centro.getCodigo() << ", "
                  << "Nombre: " << centro.getNombre() << ", "
                  << "País: " << centro.getPais() << ", "
                  << "Superficie: " << centro.getSuperficie() << std::endl;

        tabla.insertar(centro.getCodigo(), centro);  // Agrega cada centro a la tabla de hash

        // Verificación de los datos después de la inserción
        std::cout << "Centro insertado en la tabla: "
                  << "Código: " << centro.getCodigo() << ", "
                  << "Nombre: " << centro.getNombre() << ", "
                  << "País: " << centro.getPais() << ", "
                  << "Superficie: " << centro.getSuperficie() << std::endl;

        std::cout << "Centro cargado: " << centro.getCodigo() << " - " << centro.getNombre()
                   << ", " << centro.getPais() << "\n";
    }
}

// Cargar proyectos desde el archivo utilizando LectorArchivo
void Menu::cargar_proyectos(const std::string& archivo_proyectos) {
    LectorArchivo lector(archivo_proyectos); // Crear una instancia de LectorArchivo

    for (const auto& proyecto : lector.leerArchivoProyectos()) { // Itera directamente sobre los proyectos leídos
        grafo.agregar_proyecto(proyecto.getCentroOrigen(), proyecto.getCentroDestino(),
                               proyecto.getCosto(), proyecto.getDuracion()); // Agregar el proyecto al grafo
        std::cout << "Proyecto cargado: " << proyecto.getCentroOrigen() << " -> " << proyecto.getCentroDestino()
                  << " con costo: " << proyecto.getCosto() << " y duración: " << proyecto.getDuracion() << "\n";
    }
}

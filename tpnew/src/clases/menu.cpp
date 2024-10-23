#include "grafo.h"  // Asegúrate de tener la clase Grafo y sus métodos definidos
#include "lector.h" // Incluir la clase LectorArchivo
#include <vector>

class Menu {
private:
    Grafo grafo;  // Instancia de la clase Grafo para gestionar centros y proyectos

public:
    // Constructor: inicializa el grafo y carga los datos de los archivos
    Menu(const std::string& archivo_centros, const std::string& archivo_proyectos) {
        cargar_centros(archivo_centros);
        cargar_proyectos(archivo_proyectos);
    }

    // Método principal para iniciar el menú interactivo
    void iniciar() {
        int opcion;
        do {
            mostrar_menu();
            std::cin >> opcion;
            procesar_opcion(opcion);
        } while (opcion != 0);
    }

private:
    // Mostrar el menú de opciones
    void mostrar_menu() {
        std::cout << "\nMenu:\n";
        std::cout << "1. Mostrar colaboraciones de un centro\n";
        std::cout << "2. Buscar colaboración más económica\n";
        std::cout << "3. Buscar colaboración más rápida\n";
        std::cout << "0. Salir\n";
        std::cout << "Elija una opción: ";
    }

    // Procesar la opción elegida por el usuario
    void procesar_opcion(int opcion) {
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
    void cargar_centros(const std::string& archivo_centros) {
        LectorArchivo lector(archivo_centros); // Crear una instancia de LectorArchivo
        std::vector<CentroInvestigacion> centros = lector.leerArchivo(); // Leer los centros

        for (const auto& centro : centros) {
            // Aquí podrías almacenar los centros en el grafo si es necesario
            // Por ejemplo, grafo.agregarCentro(centro);
            std::cout << "Centro cargado: " << centro.getCodigo() << " - " << centro.getNombre() 
                      << " en " << centro.getCiudad() << ", " << centro.getPais() << "\n";
        }
    }

    // Cargar proyectos desde el archivo
    void cargar_proyectos(const std::string& archivo_proyectos) {
        std::ifstream archivo(archivo_proyectos);
        std::string linea;

        if (!archivo.is_open()) {
            std::cout << "No se pudo abrir el archivo de proyectos.\n";
            return;
        }

        while (std::getline(archivo, linea)) {
            std::istringstream stream(linea);
            std::string origen, destino;
            float costo, duracion;

            stream >> origen >> destino >> costo >> duracion;

            grafo.agregar_proyecto(origen, destino, costo, duracion);
        }

        std::cout << "Proyectos cargados con éxito.\n";
    }
};

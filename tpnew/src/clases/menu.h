#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../auxiliar/grafo.h"
#include "../auxiliar/tablaHash.h"
#include "../lector/lector.h"
#include "../clases/proyectoCientifico.h"
#include "../clases/centroDeInvestigacion.h"

class Menu {
private:
    Grafo<ProyectoCientifico> grafo;  // Especifica que el grafo almacena objetos de ProyectoCientifico
    TablaHash<CentroInvestigacion> tabla; // Especifica que la tabla hash almacena objetos de CentroInvestigacion

public:
    // Constructor que inicializa el menú y carga los centros y proyectos
    Menu(const std::string& archivo_centros, const std::string& archivo_proyectos);

    // Método para iniciar el menú interactivo
    void iniciar();

private:
    // Mostrar las opciones del menú
    void mostrar_menu();

    // Procesar la opción seleccionada por el usuario
    void procesar_opcion(int opcion);

    // Cargar los datos de centros desde el archivo de texto
    void cargar_centros(const std::string& archivo_centros);

    // Cargar los datos de proyectos desde el archivo de texto
    void cargar_proyectos(const std::string& archivo_proyectos);

    // Consultar un centro de investigación en particular
    void consultar_centro();

    // Agregar un nuevo centro de investigación
    void agregar_centro();

    // Eliminar un centro de investigación
    void eliminar_centro();

    // Mostrar todos los centros de investigación ordenados
    void mostrar_todos_los_centros();

    // Función para verificar si un número es primo
    bool esPrimo(int n);

    // Función para encontrar el siguiente número primo mayor o igual a un número dado
    int siguientePrimo(int num);

   // Función para contar la cantidad de centros en el archivo
    int contar_centros(const std::string& archivo_centros);
};

#endif  // MENU_H

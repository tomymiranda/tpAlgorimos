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
};

#endif  // MENU_H

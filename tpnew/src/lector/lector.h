#ifndef LECTOR_H
#define LECTOR_H

#include <vector>
#include <string>
#include "../clases/centroDeInvestigacion.h"  // Ruta relativa para centroDeInvestigacion.h
#include "../clases/proyectoCientifico.h"      // Ruta relativa para proyectoCientifico.h

class LectorArchivo {
private:
    std::string nombreArchivo;

public:
    // Constructor
    LectorArchivo(const std::string& archivo);

    // Método para imprimir el nombre del archivo
    void imprimirNombreArchivo() const;

    // Métodos para leer archivos de centros y proyectos
    std::vector<CentroInvestigacion> leerArchivoCentros();
    std::vector<ProyectoCientifico> leerArchivoProyectos();

private:
    // Métodos para crear objetos a partir de líneas de texto
    CentroInvestigacion crearCentroDesdeLinea(const std::string& linea);
    ProyectoCientifico crearProyectoDesdeLinea(const std::string& linea);
};

#endif // LECTOR_H

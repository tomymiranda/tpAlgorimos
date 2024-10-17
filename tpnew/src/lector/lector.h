#ifndef LECTOR_H
#define LECTOR_H

#include <vector>
#include <string>
#include "../clases/centroDeInvestigacion.h"  // RUTA RELATIVA para centroDeInvestigacion.h

class LectorArchivo {
private:
    std::string nombreArchivo;

public:
    LectorArchivo(const std::string& archivo);

    std::vector<CentroInvestigacion> leerArchivo();

private:
    CentroInvestigacion crearCentroDesdeLinea(const std::string& linea);
};

#endif // LECTOR_H

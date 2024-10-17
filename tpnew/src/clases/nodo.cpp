#include "centroDeInvestigacion.h"

class Nodo {
private:
	CentroInvestigacion centro;
    Nodo* siguiente;

public:

    Nodo(const CentroInvestigacion& centro) : centro(centro), siguiente(nullptr) {}

    CentroInvestigacion getCentro() const { return centro; }
    Nodo* getSiguiente() const { return siguiente; }

    void setSiguiente(Nodo* nodo) { siguiente = nodo; }
};



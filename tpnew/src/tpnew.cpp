//============================================================================
// Name        : tpnew.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "clases/menu.h"
using namespace std;
/*
 * int main() {
	cout << "!!!Hello World papa see!!!" << endl;
	return 0;
}
 * */

// HAY Q PASAR SI O SI LA RUTA PORQ SINO NO LO LEVANTA
int main() {
    string archivo_centros = "src/centros.txt";
    string archivo_proyectos = "src/proyectos.txt";

    // Crear una instancia del menú
    Menu menu(archivo_centros, archivo_proyectos); // Pasa las rutas

    // Iniciar el menú
    menu.iniciar();

    return 0;
}

//============================================================================
// Name        : tpnew.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl;
	return 0;
}

/*
 * void mostrarMenu();
void consultarCentro(const vector<CentroInvestigacion>& centros);
void agregarCentro(vector<CentroInvestigacion>& centros);
void eliminarCentro(vector<CentroInvestigacion>& centros);
void mostrarCentrosOrdenados(const vector<CentroInvestigacion>& centros);

int main() {
    LectorArchivo lector("centros.txt");
    vector<CentroInvestigacion> centros = lector.leerArchivo();
    int opcion;

    do {
        mostrarMenu();
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                consultarCentro(centros);
                break;
            case 2:
                agregarCentro(centros);
                break;
            case 3:
                eliminarCentro(centros);
                break;
            case 4:
                mostrarCentrosOrdenados(centros);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 0);

    return 0;
}

void mostrarMenu() {
    cout << "\n--- Menú de Opciones ---\n";
    cout << "1. Consultar por un centro de investigación\n";
    cout << "2. Agregar un nuevo centro de investigación\n";
    cout << "3. Eliminar un centro de investigación\n";
    cout << "4. Mostrar todos los centros (ordenados)\n";
    cout << "0. Salir\n";
}

void consultarCentro(const vector<CentroInvestigacion>& centros) {
    string codigo;
    cout << "Ingrese el código del centro a consultar: ";
    cin >> codigo;

    auto it = find_if(centros.begin(), centros.end(),
                      [&codigo](const CentroInvestigacion& c) { return c.getCodigo() == codigo; });

    if (it != centros.end()) {
        cout << "Centro encontrado:\n";
        cout << "Nombre: " << it->getNombre() << ", Ciudad: " << it->getCiudad()
             << ", País: " << it->getPais() << ", Superficie: " << it->getSuperficie() << endl;
    } else {
        cout << "Centro no encontrado." << endl;
    }
}

void agregarCentro(vector<CentroInvestigacion>& centros) {
    string codigo, nombre, ciudad, pais;
    float superficie;
    int num_lab, proyectos_nac, proyectos_int;

    cout << "Ingrese los datos del nuevo centro:\n";
    cout << "Código: "; cin >> codigo;
    cout << "Nombre: "; cin >> nombre;
    cout << "Ciudad: "; cin >> ciudad;
    cout << "País: "; cin >> pais;
    cout << "Superficie: "; cin >> superficie;
    cout << "Número de laboratorios: "; cin >> num_lab;
    cout << "Proyectos nacionales: "; cin >> proyectos_nac;
    cout << "Proyectos internacionales: "; cin >> proyectos_int;

    centros.emplace_back(codigo, nombre, ciudad, pais, superficie, num_lab, proyectos_nac, proyectos_int);
    cout << "Centro agregado con éxito.\n";
}

void eliminarCentro(vector<CentroInvestigacion>& centros) {
    string codigo;
    cout << "Ingrese el código del centro a eliminar: ";
    cin >> codigo;

    auto it = remove_if(centros.begin(), centros.end(),
                        [&codigo](const CentroInvestigacion& c) { return c.getCodigo() == codigo; });

    if (it != centros.end()) {
        centros.erase(it, centros.end());
        cout << "Centro eliminado con éxito.\n";
    } else {
        cout << "Centro no encontrado.\n";
    }
}

void mostrarCentrosOrdenados(const vector<CentroInvestigacion>& centros) {
    cout << "Ordenar por:\n";
    cout << "1. Nombre\n2. País\n3. Superficie\n";
    int criterio;
    cin >> criterio;

    vector<CentroInvestigacion> copia = centros;  // Crear una copia para no modificar el original

    switch (criterio) {
        case 1:
            sort(copia.begin(), copia.end(),
                 [](const CentroInvestigacion& a, const CentroInvestigacion& b) {
                     return a.getNombre() < b.getNombre();
                 });
            break;
        case 2:
            sort(copia.begin(), copia.end(),
                 [](const CentroInvestigacion& a, const CentroInvestigacion& b) {
                     return a.getPais() < b.getPais();
                 });
            break;
        case 3:
            sort(copia.begin(), copia.end(),
                 [](const CentroInvestigacion& a, const CentroInvestigacion& b) {
                     return a.getSuperficie() < b.getSuperficie();
                 });
            break;
        default:
            cout << "Criterio no válido. Mostrando sin ordenar." << endl;
            return;
    }

    for (const auto& centro : copia) {
        cout << "Nombre: " << centro.getNombre() << ", País: " << centro.getPais()
             << ", Superficie: " << centro.getSuperficie() << endl;
    }
}
 *
 * */

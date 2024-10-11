#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LectorArchivo {
private:
    string nombreArchivo;

public:

    LectorArchivo(const string& archivo) : nombreArchivo(archivo) {}

    void leerArchivo() {
        ifstream archivo(nombreArchivo);

        if (!archivo.is_open()) {
            cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
            return;
        }

        string linea;
        // aca iria para crear el objeto
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    }
};

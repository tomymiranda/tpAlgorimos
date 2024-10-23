#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm> 

class TablaHash {
private:
    std::vector<std::list<CentroInvestigacion>> tabla;
    int capacidad;

    // Función de hash para convertir el código a índice
    int hashFunction(const std::string& codigo) {
        int hashValue = 0;
        for (char c : codigo) {
            hashValue += c;  // Suma los valores ASCII de los caracteres
        }
        return hashValue % capacidad;
    }

public:
    // Constructor para inicializar la tabla con una capacidad dada
    TablaHash(int cap) : capacidad(cap) {
        tabla.resize(capacidad);
    }

    // Método para insertar un centro en la tabla de hash
    void insertar(const CentroInvestigacion& centro) {
        int index = hashFunction(centro.codigo);
        tabla[index].push_back(centro);
    }

    // Método para buscar un centro en la tabla de hash usando su código
    bool buscar(const std::string& codigo) {
        int index = hashFunction(codigo);
        for (const auto& centro : tabla[index]) {
            if (centro.codigo == codigo) {
                std::cout << centro << std::endl;  // Muestra los detalles del centro encontrado
                return true;
            }
        }
        return false;  // No encontrado
    }

    // Método para eliminar un centro de la tabla usando su código
    bool eliminar(const std::string& codigo) {
        int index = hashFunction(codigo);
        auto& lista = tabla[index];
        for (auto it = lista.begin(); it != lista.end(); ++it) {
            if (it->codigo == codigo) {
                lista.erase(it);  // Elimina el centro
                return true;
            }
        }
        return false;  // No encontrado
    }

    // Método para mostrar todos los centros, con opción de ordenar por un atributo específico
    void mostrarTodos(const std::string& criterio) {
        std::vector<CentroInvestigacion> todosCentros;

        // Recopilar todos los centros de investigación
        for (const auto& lista : tabla) {
            for (const auto& centro : lista) {
                todosCentros.push_back(centro);
            }
        }

        // Ordenar según el criterio indicado
        if (criterio == "nombre") {
            std::sort(todosCentros.begin(), todosCentros.end(), [](const CentroInvestigacion& a, const CentroInvestigacion& b) {
                return a.nombre < b.nombre;
            });
        } else if (criterio == "pais") {
            std::sort(todosCentros.begin(), todosCentros.end(), [](const CentroInvestigacion& a, const CentroInvestigacion& b) {
                return a.pais < b.pais;
            });
        } else if (criterio == "superficie") {
            std::sort(todosCentros.begin(), todosCentros.end(), [](const CentroInvestigacion& a, const CentroInvestigacion& b) {
                return a.superficie < b.superficie;
            });
        }

        // Mostrar todos los centros ordenados
        for (const auto& centro : todosCentros) {
            std::cout << centro << std::endl;
        }
    }
};

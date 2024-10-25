#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm> 
#include "../clases/centroDeInvestigacion.h"

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
        int index = hashFunction(centro.getCodigo());
        tabla[index].push_back(centro);
    }

    // Método para buscar un centro en la tabla de hash usando su código
    bool buscar(const std::string& codigo) {
        int index = hashFunction(codigo);
        auto& lista = tabla[index];

        for (const auto& centro : lista) {
            if (centro.getCodigo() == codigo) {
                // Imprimir detalles del centro usando sus getters
                std::cout << "Código: " << centro.getCodigo() << std::endl;
                // Si tienes otros atributos, imprímelos aquí, por ejemplo:
                // std::cout << "Otro Atributo: " << centro.getOtroAtributo() << std::endl;
                return true;  // Centro encontrado
            }
        }
        return false;  // No encontrado
    }
    // Método para eliminar un centro de la tabla usando su código
    bool eliminar(const std::string& codigo) {
        int index = hashFunction(codigo);
        auto& lista = tabla[index];
        for (auto it = lista.begin(); it != lista.end(); ++it) {
            if (it->getCodigo() == codigo) {
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
                return a.getNombre() < b.getNombre();
            });
        } else if (criterio == "pais") {
            std::sort(todosCentros.begin(), todosCentros.end(), [](const CentroInvestigacion& a, const CentroInvestigacion& b) {
                return a.getPais() < b.getPais();
            });
        } else if (criterio == "superficie") {
            std::sort(todosCentros.begin(), todosCentros.end(), [](const CentroInvestigacion& a, const CentroInvestigacion& b) {
                return a.getSuperficie() < b.getSuperficie();
            });
        }

        // Mostrar todos los centros ordenados
        for (const auto& centro : todosCentros) {
            std::cout << "Código: " << centro.getCodigo() << ", "
                      << "Nombre: " << centro.getNombre() << ", "
                      << "País: " << centro.getPais() << ", "
                      << "Superficie: " << centro.getSuperficie() << std::endl;
        }
    }
};

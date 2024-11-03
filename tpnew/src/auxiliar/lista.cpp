/*
 * #include "lista.h"

// Constructor
template <typename T>
Lista<T>::Lista() : primero(nullptr), largo(0) {}

// Método para insertar un elemento en una posición específica
template <typename T>
void Lista<T>::alta(T d, int pos) {
    Nodo<T>* nuevo = new Nodo<T>(d);
    if (pos == 0) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    } else {
        Nodo<T>* anterior = obtener_nodo(pos - 1);
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(nuevo);
    }
    largo++;
}

// Método para eliminar un elemento en una posición específica
template <typename T>
void Lista<T>::baja(int pos) {
    if (pos == 0) {
        Nodo<T>* eliminar = primero;
        primero = primero->obtener_siguiente();
        delete eliminar;
    } else {
        Nodo<T>* anterior = obtener_nodo(pos - 1);
        Nodo<T>* eliminar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(eliminar->obtener_siguiente());
        delete eliminar;
    }
    largo--;
}

// Método para consultar el elemento en una posición específica
template <typename T>
T Lista<T>::consulta(int pos) const {
    return obtener_nodo(pos)->obtener_dato();
}

// Método para verificar si la lista está vacía
template <typename T>
bool Lista<T>::vacia() const {
    return largo == 0;
}

// Destructor para liberar memoria de todos los nodos
template <typename T>
Lista<T>::~Lista() {
    while (!vacia()) {
        baja(0);
    }
}

// Método para obtener el largo de la lista
template <typename T>
int Lista<T>::obtener_largo() const {
    return largo;
}

// Método para mostrar todos los elementos de la lista
template <typename T>
void Lista<T>::mostrar() const {
    Nodo<T>* actual = primero;
    while (actual != nullptr) {
        T proyecto = actual->obtener_dato();  // Obtenemos el dato del nodo (ProyectoCientifico)

        // Accede e imprime los atributos de ProyectoCientifico
        std::cout << "Proyecto: " << proyecto.getCentroOrigen()
                  << " a " << proyecto.getCentroDestino()
                  << ", Costo: " << proyecto.getCosto() << " miles de pesos, "
                  << "Duración: " << proyecto.getDuracion() << " meses\n";

        actual = actual->obtener_siguiente();
    }
    std::cout << std::endl;
}

// Método privado para obtener un nodo en una posición específica
template <typename T>
Nodo<T>* Lista<T>::obtener_nodo(int pos) const {
    Nodo<T>* actual = primero;
    for (int i = 0; i < pos; ++i) {
        actual = actual->obtener_siguiente();
    }
    return actual;
}

// Para que las implementaciones de las plantillas sean visibles, incluye el archivo de cabecera aquí.
template class Lista<CentroInvestigacion>;  // Instanciación para CentroInvestigacion
template class Lista<ProyectoCientifico>;   // Instanciación para ProyectoCientifico
 *
 * */

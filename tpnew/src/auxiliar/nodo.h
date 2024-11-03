#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

template <typename T>
class Nodo {
private:
    T dato;           // Almacena el dato genérico
    Nodo* siguiente;  // Puntero al siguiente nodo

public:
    // Constructor que acepta un dato del tipo T
    Nodo(T d);

    // Método para cambiar el dato
    void cambiar_dato(T d);

    // Método para cambiar el siguiente nodo
    void cambiar_siguiente(Nodo* s);

    // Método para obtener el dato
    T obtener_dato() const;

    // Método para obtener el siguiente nodo
    Nodo* obtener_siguiente() const;
};

#endif // NODO_H_INCLUDED

#ifndef LISTA_H
#define LISTA_H

#include <string>
#include "mascota.h"

using namespace std;

// Nodo de la lista doblemente ligada: guarda una mascota y apuntadores al nodo anterior y al siguiente.
struct Nodo {
    Mascota dato;
    Nodo* anterior;
    Nodo* siguiente;

    Nodo();
    Nodo(Mascota m);
};

// Lista doblemente ligada de mascotas (estructura lineal).
class ListaDoble {

private:
    Nodo* inicio;   // primer nodo
    Nodo* fin;      // ultimo nodo (permite agregar al final en O(1))
    int tamano;

public:
    ListaDoble();
    ~ListaDoble();

    // Agrega una mascota al final.
    void agregarAlFinal(Mascota m);

    void vaciar();

    bool estaVacia();   
    int getTamano();    
    Nodo* getInicio();  

    // Recibe el primer nodo que dejo el ordenamiento y reconstruye
    void reconstruirDesde(Nodo* nuevoInicio);
};

#endif
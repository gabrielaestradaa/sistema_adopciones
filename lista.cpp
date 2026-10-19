#include "lista.h"

Nodo::Nodo() {
    anterior = NULL;
    siguiente = NULL;
}

Nodo::Nodo(Mascota m) {
    dato = m;
    anterior = NULL;
    siguiente = NULL;
}

ListaDoble::ListaDoble() {
    inicio = NULL;
    fin = NULL;
    tamano = 0;
}

// El destructor libera la memoria de todos los nodos.
ListaDoble::~ListaDoble() {
    vaciar();
}

void ListaDoble::vaciar() {
    Nodo* actual = inicio;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    inicio = NULL;
    fin = NULL;
    tamano = 0;
}

void ListaDoble::agregarAlFinal(Mascota m) {
    Nodo* nuevo = new Nodo(m);

    if (inicio == NULL) {// lista vacia
        inicio = nuevo;
        fin = nuevo;
    } else {
        nuevo->anterior = fin;
        fin->siguiente = nuevo;
        fin = nuevo;
    }
    tamano++;
}

bool ListaDoble::estaVacia() {
    return tamano == 0;
}

int ListaDoble::getTamano() {
    return tamano;
}

Nodo* ListaDoble::getInicio() {
    return inicio;
}

void ListaDoble::reconstruirDesde(Nodo* nuevoInicio) {
    inicio = nuevoInicio;

    Nodo* previo = NULL;
    Nodo* actual = inicio;
    while (actual != NULL) {
        actual->anterior = previo;
        previo = actual;
        actual = actual->siguiente;
    }
    fin = previo;
}
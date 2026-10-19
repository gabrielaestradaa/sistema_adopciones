#include "ordenamiento.h"

// Criterios de ordenamiento:
// 1 = nombre, 2 = edad, 3 = especie, 4 = raza

// Regresa true si a va antes (o igual) que b segun el criterio. O(1).
bool menorIgual(Mascota& a, Mascota& b, int criterio) {
    if (criterio == 1) return a.getNombre() <= b.getNombre();
    if (criterio == 2) return a.getEdad() <= b.getEdad();
    if (criterio == 3) return a.getEspecie() <= b.getEspecie();
    return a.getRaza() <= b.getRaza();
}

// Parte la lista en dos mitades con apuntador lento y rapido.
Nodo* dividir(Nodo* cabeza) {
    Nodo* lento = cabeza;
    Nodo* rapido = cabeza->siguiente;

    while (rapido != NULL && rapido->siguiente != NULL) {
        lento = lento->siguiente;
        rapido = rapido->siguiente->siguiente;
    }

    Nodo* segunda = lento->siguiente;
    lento->siguiente = NULL;
    return segunda;
}

// Mezcla dos listas ya ordenadas cambiando enlaces. 
// En empate se toma el nodo de la izquierda  (por eso es estable).
Nodo* mezclar(Nodo* a, Nodo* b, int criterio) {

    Nodo ficticio;              
    Nodo* cola = &ficticio;

    while (a != NULL && b != NULL) {
        if (menorIgual(a->dato, b->dato, criterio)) {
            cola->siguiente = a;
            a = a->siguiente;
        } else {
            cola->siguiente = b;
            b = b->siguiente;
        }
        cola = cola->siguiente;
    }

    // Lo que sobra de alguna mitad ya esta ordenado.
    if (a != NULL) {
        cola->siguiente = a;
    } else {
        cola->siguiente = b;
    }
    return ficticio.siguiente;
}

Nodo* mergeSortNodos(Nodo* cabeza, int criterio) {

    if (cabeza == NULL || cabeza->siguiente == NULL) {
        return cabeza;
    }

    Nodo* segunda = dividir(cabeza);
    Nodo* izquierda = mergeSortNodos(cabeza, criterio);
    Nodo* derecha = mergeSortNodos(segunda, criterio);
    return mezclar(izquierda, derecha, criterio);
}

// Ordea la lista y reconstruye los apuntadores anterior y fin.
void ordenarLista(ListaDoble& lista, int criterio) {
    if (lista.getTamano() < 2) return;
    lista.reconstruirDesde(mergeSortNodos(lista.getInicio(), criterio));
}

void mergeSortNombre(ListaDoble& lista) {
    ordenarLista(lista, 1);
}

void mergeSortEdad(ListaDoble& lista) {
    ordenarLista(lista, 2);
}

void mergeSortEspecie(ListaDoble& lista) {
    ordenarLista(lista, 3);
}

void mergeSortRaza(ListaDoble& lista) {
    ordenarLista(lista, 4);
}
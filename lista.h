#ifndef LISTA_H
#define LISTA_H

#include "mascota.h"

using namespace std;

// cada nodo guarda una mascota y apunta al siguiente
struct Nodo {
    Mascota dato;
    Nodo* siguiente;

    Nodo() {
        siguiente = NULL;
    }

    Nodo(Mascota m) {
        dato = m;
        siguiente = NULL;
    }
};

// lista ligada de mascotas (n = numero de mascotas)
class ListaLigada {

private:
    Nodo* inicio;
    Nodo* fin;      // ultimo nodo, para agregar al final sin recorrer
    int tamano;

    // true si a va antes o igual que b
    // criterio: 1 nombre, 2 edad, 3 especie, 4 raza. O(1)
    bool menorIgual(Mascota& a, Mascota& b, int criterio) {
        if (criterio == 1) {
            return a.getNombre() <= b.getNombre();
        } else if (criterio == 2) {
            return a.getEdad() <= b.getEdad();
        } else if (criterio == 3) {
            return a.getEspecie() <= b.getEspecie();
        } else {
            return a.getRaza() <= b.getRaza();
        }
    }

    // parte la lista en dos y regresa el inicio de la segunda mitad
    // el rapido avanza de 2 en 2 y el lento de 1 en 1,
    // cuando el rapido llega al final el lento esta en la mitad. O(n)
    Nodo* dividir(Nodo* cabeza) {
        Nodo* lento = cabeza;
        Nodo* rapido = cabeza->siguiente;

        while (rapido != NULL && rapido->siguiente != NULL) {
            lento = lento->siguiente;
            rapido = rapido->siguiente->siguiente;
        }

        Nodo* segunda = lento->siguiente;
        lento->siguiente = NULL;   // aqui se corta
        return segunda;
    }

    // junta dos listas ya ordenadas en una sola. O(n)
    // el nodo ficticio es para no tener que tratar el primer nodo aparte
    // si hay empate se toma el de la izquierda (estable)
    Nodo* mezclar(Nodo* a, Nodo* b, int criterio) {
        Nodo ficticio;
        Nodo* cola = &ficticio;   // ultimo nodo de la lista nueva

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

        // lo que sobra ya esta ordenado
        if (a != NULL) {
            cola->siguiente = a;
        } else {
            cola->siguiente = b;
        }

        return ficticio.siguiente;
    }

    Nodo* mergeSort(Nodo* cabeza, int criterio) {
        // con 0 o 1 nodos ya esta ordenada
        if (cabeza == NULL || cabeza->siguiente == NULL) {
            return cabeza;
        }

        Nodo* segunda = dividir(cabeza);
        Nodo* izquierda = mergeSort(cabeza, criterio);
        Nodo* derecha = mergeSort(segunda, criterio);
        return mezclar(izquierda, derecha, criterio);
    }

public:
    // O(1)
    ListaLigada() {
        inicio = NULL;
        fin = NULL;
        tamano = 0;
    }

    // O(n)
    ~ListaLigada() {
        vaciar();
    }

    // borra todos los nodos. O(n)
    void vaciar() {
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

    // agrega al final con el apuntador fin. O(1)
    void agregarAlFinal(Mascota m) {
        Nodo* nuevo = new Nodo(m);

        if (inicio == NULL) {
            inicio = nuevo;
        } else {
            fin->siguiente = nuevo;
        }
        fin = nuevo;
        tamano++;
    }

    // busca el id mas grande y regresa ese + 1. O(n)
    int siguienteId() {
        int mayor = 0;
        Nodo* actual = inicio;
        while (actual != NULL) {
            if (actual->dato.getId() > mayor) {
                mayor = actual->dato.getId();
            }
            actual = actual->siguiente;
        }
        return mayor + 1;
    }

    // ordena la lista. O(n log n)
    // despues hay que volver a buscar el ultimo nodo (fin), es O(n)
    // y no cambia el total
    void ordenar(int criterio) {
        if (tamano < 2) return;

        inicio = mergeSort(inicio, criterio);

        fin = inicio;
        while (fin->siguiente != NULL) {
            fin = fin->siguiente;
        }
    }

    // O(1)
    bool estaVacia() { return tamano == 0; }

    // O(1)
    int getTamano() { return tamano; }

    // O(1)
    Nodo* getInicio() { return inicio; }
};

#endif
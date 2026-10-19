#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "mascota.h"
#include "lista.h"
#include "ordenamiento.h"

using namespace std;

// Lee mascotas.csv y llena la lista.
void cargarMascotas(const string& archivo, ListaDoble& mascotas) {

    ifstream entrada(archivo);

    if (!entrada.is_open()) {
        cout << "No se pudo abrir el archivo: " << archivo << endl;
        return;
    }

    string linea;
    while (getline(entrada, linea)) {

        if (linea.empty()) continue;

        stringstream ss(linea);
        string campo;
        vector<string> campos;

        while (getline(ss, campo, ',')) {
            campos.push_back(campo);
        }

        if (campos.size() < 6) continue;

        int id = stoi(campos[0]);
        string nombre = campos[1];
        string especie = campos[2];
        string raza = campos[3];
        int edad = stoi(campos[4]);
        string tamano = campos[5];

        mascotas.agregarAlFinal(Mascota(id, nombre, especie, raza, edad, tamano));
    }

    entrada.close();
}

// Muestra la lista en su orden actual.
void mostrarTodas(ListaDoble& mascotas) {
    Nodo* actual = mascotas.getInicio();
    while (actual != NULL) {
        actual->dato.mostrar();
        actual = actual->siguiente;
    }
}

// Guarda la lista en su orden actual en un archivo CSV. 
void guardarMascotas(ListaDoble& mascotas, const string& archivo) {

    ofstream salida(archivo);

    if (!salida.is_open()) {
        cout << "No se pudo crear/abrir el archivo: " << archivo << endl;
        return;
    }

    Nodo* actual = mascotas.getInicio();
    while (actual != NULL) {
        salida << actual->dato.getId() << ","
               << actual->dato.getNombre() << ","
               << actual->dato.getEspecie() << ","
               << actual->dato.getRaza() << ","
               << actual->dato.getEdad() << ","
               << actual->dato.getTamano() << "\n";
        actual = actual->siguiente;
    }

    salida.close();
    cout << "Datos guardados en " << archivo << endl;
}

int main() {

    ListaDoble mascotas;
    cargarMascotas("mascotas.csv", mascotas);

    if (mascotas.estaVacia()) {
        cout << "No se cargaron mascotas. Verifica el archivo mascotas.csv" << endl;
        return 1;
    }

    int opcion = -1;

    while (opcion != 0) {
        cout << "\n ORDENAR MASCOTAS \n";
        cout << "1. Ordenar por Nombre\n";
        cout << "2. Ordenar por Edad\n";
        cout << "3. Ordenar por Especie\n";
        cout << "4. Ordenar por Raza\n";
        cout << "5. Mostrar sin ordenar\n";
        cout << "6. Guardar orden actual en mascotas_ordenado.csv\n";
        cout << "7. Mostrar con el orden actual\n";
        cout << "0. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mergeSortNombre(mascotas);
                mostrarTodas(mascotas);
                break;
            case 2:
                mergeSortEdad(mascotas);
                mostrarTodas(mascotas);
                break;
            case 3:
                mergeSortEspecie(mascotas);
                mostrarTodas(mascotas);
                break;
            case 4:
                mergeSortRaza(mascotas);
                mostrarTodas(mascotas);
                break;
            case 5:
                mascotas.vaciar();
                cargarMascotas("mascotas.csv", mascotas);
                mostrarTodas(mascotas);
                break;
            case 6:
                guardarMascotas(mascotas, "mascotas_ordenado.csv");
                break;
            case 7:
                mostrarTodas(mascotas);
                break;
            case 0:
                cout << "Gracias por usar el sistema de adopciones.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    }

    return 0;
}
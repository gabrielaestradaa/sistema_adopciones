#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include "lista.h"

using namespace std;

// lee el csv y mete cada mascota a la lista. O(n)
void cargarMascotas(const string& archivo, ListaLigada& mascotas) {
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

        // convierte el id y la edad de texto a numero
        // si no son numeros, el stringstream falla y se salta la linea
        int id, edad;
        stringstream convId(campos[0]);
        stringstream convEdad(campos[4]);

        if (!(convId >> id) || !(convEdad >> edad)) {
            cout << "Se encontro un registro incorrecto: " << linea << endl;
            continue;
        }

        mascotas.agregarAlFinal(Mascota(id, campos[1], campos[2],
                                        campos[3], edad, campos[5]));
    }
}

// muetra la lista como esta en ese momento. O(n)
void mostrarTodas(ListaLigada& mascotas) {
    cout << "\nID | Nombre | Especie | Raza | Edad | Tamano\n";

    Nodo* actual = mascotas.getInicio();
    while (actual != NULL) {
        actual->dato.mostrar();
        actual = actual->siguiente;
    }
}

// guarda la lista en un csv. O(n)
void guardarMascotas(ListaLigada& mascotas, const string& archivo) {
    ofstream salida(archivo);

    if (!salida.is_open()) {
        cout << "No se pudo crear el archivo: " << archivo << endl;
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

    cout << "Datos guardados en " << archivo << endl;
}

// pide los datos, agrega la mascota a la lista y tambien al csv
// O(n) por siguienteId (agregar al final es O(1))
void agregarMascota(ListaLigada& mascotas, const string& archivo) {
    string nombre, especie, raza, tamano;
    int edad;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Especie: ";
    getline(cin, especie);
    cout << "Raza: ";
    getline(cin, raza);
    cout << "Tamano (Pequeno/Mediano/Grande): ";
    getline(cin, tamano);

    cout << "Edad: ";
    while (!(cin >> edad) || edad < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingresa una edad valida: ";
    }

    Mascota nueva(mascotas.siguienteId(), nombre, especie, raza, edad, tamano);
    mascotas.agregarAlFinal(nueva);

    ofstream salida(archivo, ios::app);
    salida << nueva.getId() << "," << nombre << "," << especie << ","
           << raza << "," << edad << "," << tamano << "\n";

    cout << "Mascota agregada con id " << nueva.getId() << endl;
}

int main() {
    ListaLigada mascotas;
    cargarMascotas("mascotas.csv", mascotas);

    if (mascotas.estaVacia()) {
        cout << "No se cargaron mascotas. Verifica el archivo mascotas.csv" << endl;
        return 1;
    }

    int opcion = -1;

    while (opcion != 0) {
        cout << "\n--- SISTEMA DE ADOPCIONES ---\n";
        cout << "1. Ordenar por Nombre\n";
        cout << "2. Ordenar por Edad\n";
        cout << "3. Ordenar por Especie\n";
        cout << "4. Ordenar por Raza\n";
        cout << "5. Mostrar sin ordenar\n";
        cout << "6. Guardar orden actual en mascotas_ordenado.csv\n";
        cout << "7. Mostrar orden actual\n";
        cout << "8. Agregar nueva mascota\n";
        cout << "0. Salir\n";
        cout << "Elige una opcion: ";

        // si escribe letras en vez de numero
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = -1;
        }

        if (opcion >= 1 && opcion <= 4) {
            mascotas.ordenar(opcion);
            mostrarTodas(mascotas);
        } else if (opcion == 5) {
            mascotas.vaciar();
            cargarMascotas("mascotas.csv", mascotas);
            mostrarTodas(mascotas);
        } else if (opcion == 6) {
            guardarMascotas(mascotas, "mascotas_ordenado.csv");
        } else if (opcion == 7) {
            mostrarTodas(mascotas);
        } else if (opcion == 8) {
            agregarMascota(mascotas, "mascotas.csv");
        } else if (opcion == 0) {
            cout << "Gracias por usar el sistema de adopciones.\n";
        } else {
            cout << "Opcion invalida.\n";
        }
    }

    return 0;
}
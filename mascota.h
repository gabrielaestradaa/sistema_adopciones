#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <string>

using namespace std;

// una mascota del refugio, todos los metodos son O(1)
class Mascota {

private:
    int id;
    string nombre;
    string especie;
    string raza;
    int edad;
    string tamano;

public:
    Mascota() {
        id = 0;
        edad = 0;
    }

    Mascota(int id, string nombre, string especie,
            string raza, int edad, string tamano) {
        this->id = id;
        this->nombre = nombre;
        this->especie = especie;
        this->raza = raza;
        this->edad = edad;
        this->tamano = tamano;
    }

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getEspecie() const { return especie; }
    string getRaza() const { return raza; }
    int getEdad() const { return edad; }
    string getTamano() const { return tamano; }

    // imprime la mascota en una linea
    void mostrar() const {
        cout << id << " | " << nombre << " | " << especie << " | "
             << raza << " | " << edad << " | " << tamano << endl;
    }
};

#endif
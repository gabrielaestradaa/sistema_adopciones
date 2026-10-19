#include "mascota.h"
#include <iostream>

using namespace std;

// Constructor 
Mascota::Mascota() {

    id = 0;
    nombre = "";
    especie = "";
    raza = "";
    edad = 0;
    tamano = "";
}

// Constructor con tods los atributos.
Mascota::Mascota(int id, string nombre, string especie,
                 string raza, int edad, string tamano) {

    this->id = id;
    this->nombre = nombre;
    this->especie = especie;
    this->raza = raza;
    this->edad = edad;
    this->tamano = tamano;
}

int Mascota::getId() {
    return id;
}

string Mascota::getNombre() {
    return nombre;
}

string Mascota::getEspecie() {
    return especie;
}

string Mascota::getRaza() {
    return raza;
}

int Mascota::getEdad() {
    return edad;
}

string Mascota::getTamano() {
    return tamano;
}


void Mascota::mostrar() {

    cout << id << " | "
         << nombre << " | "
         << especie << " | "
         << raza << " | "
         << edad << " | "
         << tamano << endl;
}
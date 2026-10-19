#ifndef MASCOTA_H
#define MASCOTA_H

#include <string>

using namespace std;

// Representa a una mascota del refugio.
class Mascota {

private:
    int id;
    string nombre;
    string especie;
    string raza;
    int edad;
    string tamano;

public:
    Mascota();

    Mascota(int id, string nombre, string especie,
            string raza, int edad, string tamano);

    // Getters
    int getId();
    string getNombre();
    string getEspecie();
    string getRaza();
    int getEdad();
    string getTamano();

    // Imprime la mascota en una linea.
    void mostrar();
};

#endif
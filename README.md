# Proyecto: Sistema de Ordenamiento de Mascotas en Refugio

## Descripción

Este proyecto es un programa en C++ para organizar la información de las mascotas de un refugio. El programa carga los datos desde un archivo CSV, muestra las mascotas, las ordena por diferentes características y permite agregar mascotas nuevas. Los datos se guardan en una lista ligada y se ordenan con Merge Sort.

## Problema que resuelve

Un refugio recibe muchas mascotas y su información puede volverse difícil de organizar o de encontrar. Este programa mantiene esos datos ordenados y permite verlos por nombre, edad, especie o raza, para que sea más fácil consultarlos y ayudar a que cada mascota encuentre un hogar más rápido.

## Archivos

- `mascota.h`: clase Mascota.
- `lista.h`: lista ligada y Merge Sort.
- `main.cpp`: menú y manejo del archivo CSV.
- `mascotas.csv`: datos de las mascotas (id, nombre, especie, raza, edad, tamaño).

## Menú

1. Ordenar por nombre
2. Ordenar por edad
3. Ordenar por especie
4. Ordenar por raza
5. Mostrar sin ordenar
6. Guardar el orden actual en `mascotas_ordenado.csv`
7. Mostrar el orden actual
8. Agregar una mascota nueva
0. Salir

Al agregar una mascota se piden nombre, especie, raza, tamaño y edad. El id se asigna solo y la mascota también se guarda en `mascotas.csv`.

## Por qué esta estructura y este algoritmo

Elegí una **lista ligada** porque las mascotas se van agregando de una en una y así no hay que mover ni copiar las demás. Con el apuntador `fin`, agregar al final es O(1). Como solo recorro la lista de principio a fin, no hizo falta que fuera doble.

Escogí **Merge Sort** porque se lleva muy bien con las listas ligadas. En una lista no se puede brincar directo a una posición, y este algoritmo no lo necesita: solo va partiendo la lista a la mitad y después la junta cambiando a dónde apunta cada nodo. Siempre tarda O(n log n), aunque los datos estén revueltos o ya casi ordenados, y es estable, o sea que si dos mascotas empatan se queda primero la que ya estaba antes.

## Complejidad

n = número de mascotas.

| Función | Complejidad |
|---|---|
| Constructores, getters y `mostrar` de Mascota | O(1) |
| Constructor de la lista | O(1) |
| `vaciar` y destructor | O(n) |
| `agregarAlFinal` | O(1) |
| `siguienteId` | O(n) |
| `estaVacia`, `getTamano`, `getInicio` | O(1) |
| `menorIgual` | O(1) |
| `dividir` | O(n) |
| `mezclar` | O(n) |
| `mergeSort` | O(n log n) |
| `ordenar` | O(n log n) |
| `cargarMascotas` | O(n) |
| `mostrarTodas` | O(n) |
| `guardarMascotas` | O(n) |
| `agregarMascota` | O(n) |

Notas:
- `mergeSort` divide la lista a la mitad cada vez (log n niveles) y en cada nivel `dividir` y `mezclar` recorren n nodos. Por eso sale O(n log n).
- `ordenar` hace el Merge Sort y luego recorre la lista una vez para encontrar el nuevo último nodo (`fin`), pero eso es O(n) y no cambia el total.
- `agregarMascota` es O(n) por `siguienteId`, que recorre la lista para buscar el id más grande. Agregar al final en sí es O(1).

## Cómo compilarlo y correrlo

Desde la carpeta donde están los archivos:

```
g++ main.cpp -o adopciones
./adopciones
```

El archivo `mascotas.csv` tiene que estar en la misma carpeta que el programa.

## Autor

[Tu nombre] - [Tu matrícula]

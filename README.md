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

## Cómo correrlo

```
g++ main.cpp -o adopciones
./adopciones
```

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

Usé una **lista ligada** porque se pueden ir agregando mascotas al final sin mover nada (con el apuntador `fin` es O(1)) y solo necesito recorrerla de principio a fin, así que no hace falta que sea doble.

Para ordenar elegí Merge Sort porque se adapta bien a las listas ligada no ocupa entrar a los datos por posición y, para juntar las mitades, solo cambia los enlaces de los nodos. Además su complejidad es O(n log n) sin importar cómo vengan los datos, y es estable: si dos mascotas empatan en el criterio, se queda primero la que ya iba antes.

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

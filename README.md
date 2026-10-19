# sistema-adopciones

# Proyecto: Sistema de Ordenamiento de Mascotas en Refugio

## Descripción

Este proyecto es un programa en C++ para organizar la información de las mascotas de un refugio. El programa lee los datos desde un archivo, los guarda en una lista doblemente ligada, muestra las mascotas, las ordena por diferentes características con Merge Sort y guarda el resultado en otro archivo.

## Problema que resuelve

Un refugio puede tener información de muchas mascotas y a veces es difícil organizarla o encontrar lo que se busca, el programa mantiene los datos ordenados por nombre, edad, especie o raza para que sea más fácil consultarlos.

## Estructura de datos utilizada

Para guardar las mascotas se utiliza una lista doblemente ligada. Es una estructura lineal: las mascotas están una después de otra, y cada nodo guarda una mascota y dos apuntadores, uno al nodo anterior y otro al siguiente.

Se eligió porque en un refugio llegan mascotas nuevas y la lista permite agregarlas al final sin mover las demás. Además, Merge Sort funciona bien con listas: para ordenar solo se cambian los enlaces entre los nodos, sin copiar datos.

También se utiliza la clase `Mascota`, que guarda los datos de cada mascota: ID, nombre, especie, raza, edad y tamaño.

Complejidad de la estructura:

- Agregar una mascota al final: **O(1)**, porque la lista ya sabe dónde está el último nodo (`fin`) y no tiene que recorrer nada.
- Saber cuántas mascotas hay: **O(1)**, porque la lista guarda el tamaño y solo lo regresa.
- Recorrer toda la lista: **O(n)**, porque se pasa por cada mascota una vez.
- Buscar la mascota de una posición: **O(n)**, porque la lista no tiene índices como un vector. Hay que empezar desde el primer nodo e ir avanzando hasta llegar (en un vector sería O(1)).
- Obtener un dato de una mascota (por ejemplo `getNombre()`): **O(1)**, porque solo regresa un atributo que ya está guardado.
- La lista usa memoria dinámica: cada nodo se crea con `new` y, al terminar, el destructor los borra todos con `delete`.

## Algoritmo de ordenamiento

Se utiliza Merge Sort para ordenar las mascotas,lo eligí porque divide la lista en partes más pequeñas, las ordena y después las une otra vez de forma ordenada. 

La complejidad de Merge Sort es:

- Mejor caso: **O(n log n)**
- Caso promedio: **O(n log n)**
- Peor caso: **O(n log n)**

También es estable: si dos mascotas tienen el mismo valor, se quedan en el mismo orden que tenían. Por ejemplo, al ordenar por edad, las mascotas de la misma edad conservan su orden anterior.

En el programa se usa para ordenar por nombre, edad, especie y raza. Las cuatro opciones usan el mismo algoritmo y solo cambia lo que se compara (1 = nombre, 2 = edad, 3 = especie, 4 = raza).

## Lectura y escritura de archivos

Los datos están en el archivo `mascotas.csv`. Al iniciar el programa se usa `ifstream` para leer el archivo y agregar cada mascota a la lista.

También se usa `ofstream` para guardar las mascotas, en el orden en que estén en ese momento, en el archivo `mascotas_ordenado.csv` cuando se elige la opción de guardar.

## Complejidad

Las operaciones principales del programa tienen estas complejidades:

| Operación | Complejidad |
|---|---|
| Agregar una mascota al final de la lista | O(1) |
| Cargar mascotas desde el archivo | O(n) |
| Mostrar mascotas (en cualquier orden) | O(n) |
| Guardar mascotas en el archivo | O(n) |
| Buscar la mascota de una posición | O(n) |
| Obtener un dato de una mascota | O(1) |
| Ordenar con Merge Sort | O(n log n) |
| Vaciar la lista (al recargar) | O(n) |

**Complejidad final del programa:** cargar, mostrar, guardar y recargar son O(n), y ordenar es O(n log n). Como ordenar es lo más costoso, cada acción del menú es, en el peor caso, **O(n log n)**. En memoria, el programa guarda las n mascotas (O(n)) y usa O(log n) extra mientras ordena.


## Autora

Gabriela Estrada Guerrero

## Cómo compilar y ejecutar

```
g++ -std=c++11 -o programa main.cpp mascota.cpp lista.cpp ordenamiento.cpp
./programa
```

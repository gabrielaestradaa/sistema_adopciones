# sistema_adopciones

# Proyecto: Sistema de Ordenamiento de Mascotas en Refugio

## Descripción

Este proyecto es un programa en C++ para organizar la información de mascotas de un refugio. El programa permite cargar los datos desde un archivo, guardarlos en una **lista doblemente ligada**, mostrar las mascotas, ordenarlas por diferentes características con **Merge Sort** y guardar el resultado.

## Problema que resuelve

Un refugio puede tener información de varias mascotas y puede ser difícil organizarla o encontrarla de diferentes formas. El programa permite mantener estos datos organizados y ordenarlos por nombre, edad, especie o raza para facilitar su consulta.

## Estructura de datos utilizada

Para guardar las mascotas se utiliza una **lista doblemente ligada** (una estructura lineal). Cada nodo guarda un objeto `Mascota` y dos apuntadores: `anterior` y `siguiente`. La lista conserva además apuntadores al primer nodo (`inicio`) y al último (`fin`).

Se eligió porque el refugio recibe mascotas nuevas constantemente y la lista permite agregarlas al final sin mover las demás, y porque Merge Sort funciona de forma natural sobre ella: reacomoda los enlaces de los nodos sin necesidad de acceso por índice ni de copiar datos.

También se utiliza la clase `Mascota`, que contiene los datos de cada mascota: ID, nombre, especie, raza, edad y tamaño.

Complejidad de la estructura:

- Agregar una mascota al final: **O(1)**, porque se conserva el apuntador `fin`.
- Obtener el tamaño de la lista: **O(1)**.
- Recorrer toda la lista: **O(n)**.
- Acceder a la mascota de una posición concreta: **O(n)**, porque la lista no tiene índices y hay que recorrer los nodos (a diferencia de un vector, donde sería O(1)).
- Obtener un dato de una mascota (por ejemplo `getNombre()`): **O(1)**.
- La lista usa memoria dinámica (`new`) y su destructor libera todos los nodos con `delete`.

## Algoritmo de ordenamiento

Se utiliza **Merge Sort** sobre los nodos de la lista. Se eligió porque permite dividir la información en partes más pequeñas, ordenarlas y después unirlas nuevamente de forma ordenada:

1. Si la lista tiene 0 o 1 nodos, ya está ordenada.
2. Se divide en dos mitades con un apuntador lento y uno rápido.
3. Se ordena cada mitad de forma recursiva.
4. Se mezclan las dos mitades cambiando los enlaces de los nodos.

La complejidad de Merge Sort es:

- Mejor caso: **O(n log n)**
- Caso promedio: **O(n log n)**
- Peor caso: **O(n log n)**

Esto se debe a que la lista se divide a la mitad en cada paso (hay log n niveles) y en cada nivel la mezcla recorre los n nodos una vez: T(n) = 2T(n/2) + O(n).

Merge Sort utiliza **O(log n)** de espacio extra, solo por la pila de recursión, porque en una lista no se copian los datos a estructuras temporales (en un vector sería O(n)).

Es un ordenamiento **estable**: mascotas con el mismo valor conservan su orden relativo. Por ejemplo, al ordenar por edad, las mascotas de la misma edad quedan en el orden en que estaban.

Se eligió sobre otros algoritmos porque garantiza O(n log n) incluso en el peor caso (Bubble, Insertion y Selection Sort son O(n²)) y no depende del acceso por índice (Quick Sort puede llegar a O(n²) y funciona mejor con acceso aleatorio).

En el programa se utiliza para ordenar las mascotas por nombre, edad, especie y raza. Las cuatro funciones usan el mismo algoritmo y solo cambia el criterio de comparación (1 = nombre, 2 = edad, 3 = especie, 4 = raza).

## Lectura y escritura de archivos

Los datos se encuentran en el archivo `mascotas.csv`. Al iniciar el programa, se utiliza `ifstream` para leer la información y agregar cada mascota a la lista.

También se utiliza `ofstream` para guardar los datos en el orden actual en el archivo `mascotas_ordenado.csv` cuando se selecciona la opción de guardar.

## Complejidad

Las principales operaciones del programa tienen estas complejidades:

| Operación | Complejidad |
|---|---|
| Agregar una mascota al final de la lista | O(1) |
| Cargar mascotas desde el archivo | O(n) |
| Mostrar mascotas (en cualquier orden) | O(n) |
| Guardar mascotas en el archivo | O(n) |
| Acceder a la mascota de una posición | O(n) |
| Obtener un dato de una mascota | O(1) |
| Ordenar con Merge Sort | O(n log n) |
| Vaciar la lista (recargar) | O(n) |

**Complejidad final del programa:** cargar, mostrar, guardar y recargar son O(n), y cada ordenamiento es O(n log n). Como el ordenamiento es la operación más costosa, la complejidad de cada acción del menú es, en el peor caso, **O(n log n)**. El espacio que usa el programa es O(n) para guardar las n mascotas, más O(log n) extra durante el ordenamiento.

## Cómo se cumplen las competencias de este avance

**SICT0301 (análisis de complejidad):** se analiza Merge Sort en sus tres casos, su espacio extra y su estabilidad, además de la estructura de datos y de todas las demás operaciones del programa, con la complejidad final.

**SICT0302 (selección del algoritmo):** se eligió Merge Sort por ser el ordenamiento más adecuado para listas ligadas, por garantizar O(n log n) en el peor caso y por ser estable. El ordenamiento se usa de forma útil: permite consultar las mascotas por cuatro criterios distintos (nombre, edad, especie y raza), mantener ese orden para volver a mostrarlo cuando se necesite y guardarlo en un archivo.

**SICT0303 (implementación):** el programa está separado en archivos (`mascota`, `lista`, `ordenamiento`, `main`), usa lista propia con memoria dinámica (`new` y `delete`), lectura y escritura de archivos, y está documentado con comentarios en el código. Se amplió `mascotas.csv` a 24 mascotas, con nombres y edades repetidos para probar la estabilidad del ordenamiento.

**SEG0701 (cultura digital):** se utiliza Git y GitHub para el control de versiones, se documenta el proyecto en Markdown y el código está organizado y comentado para que otras personas puedan entenderlo y mantenerlo.

## Menú

1. Ordenar por Nombre
2. Ordenar por Edad
3. Ordenar por Especie
4. Ordenar por Raza
5. Mostrar sin ordenar (recargar desde archivo)
6. Guardar orden actual en `mascotas_ordenado.csv`
7. Mostrar con el orden actual
0. Salir

## Autor

Gabriela Guerrero

## Cómo compilar y ejecutar

```
g++ -std=c++11 -o programa main.cpp mascota.cpp lista.cpp ordenamiento.cpp
./programa
```

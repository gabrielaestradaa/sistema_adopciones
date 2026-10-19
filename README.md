# sistema-adopciones

# Proyecto: Sistema de Ordenamiento de Mascotas en Refugio

## Descripción

Este proyecto es un programa en C++ para organizar la información de las mascotas de un refugio. El programa lee los datos desde un archivo, los guarda en una **lista doblemente ligada**, muestra las mascotas, las ordena por diferentes características con **Merge Sort** y guarda el resultado en otro archivo.

## Problema que resuelve

Un refugio puede tener información de muchas mascotas y a veces es difícil organizarla o encontrar lo que se busca. El programa mantiene los datos ordenados por nombre, edad, especie o raza para que sea más fácil consultarlos.

## Estructura de datos utilizada

Para guardar las mascotas se utiliza una **lista doblemente ligada**. Es una estructura lineal: las mascotas están una después de otra, y cada nodo guarda una mascota y dos apuntadores, uno al nodo anterior y otro al siguiente. La lista también guarda cuál es el primer nodo (`inicio`) y cuál es el último (`fin`).

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

Se utiliza **Merge Sort** para ordenar las mascotas. Se eligió porque divide la lista en partes más pequeñas, las ordena y después las une otra vez de forma ordenada. Funciona así:

1. Si la lista tiene 0 o 1 mascotas, ya está ordenada.
2. Si no, se parte en dos mitades (con un apuntador lento y uno rápido para encontrar la mitad).
3. Se ordena cada mitad de la misma forma.
4. Se unen las dos mitades ya ordenadas, cambiando los enlaces de los nodos.

La complejidad de Merge Sort es:

- Mejor caso: **O(n log n)**
- Caso promedio: **O(n log n)**
- Peor caso: **O(n log n)**

Siempre es O(n log n) porque la lista se parte a la mitad en cada paso (son log n pasos) y en cada paso se unen las n mascotas una vez.

Usa muy poca memoria extra, **O(log n)**, solo la de las llamadas recursivas. No necesita copiar las mascotas a otras estructuras, porque solo cambia los enlaces (con un vector sí necesitaría O(n) de espacio extra).

También es **estable**: si dos mascotas tienen el mismo valor, se quedan en el mismo orden que tenían. Por ejemplo, al ordenar por edad, las mascotas de la misma edad conservan su orden anterior.

Se eligió sobre otros algoritmos porque siempre es O(n log n), incluso en el peor caso (Bubble, Insertion y Selection Sort son O(n²)), y porque no necesita acceder a posiciones por índice (Quick Sort puede llegar a O(n²) y funciona mejor con vectores).

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

## Cómo se cumplen las competencias de este avance

**SICT0301 (análisis de complejidad):** se analiza Merge Sort en sus tres casos, su memoria extra y su estabilidad. También se analiza la lista y todas las demás operaciones del programa, y se indica la complejidad final.

**SICT0302 (selección del algoritmo):** se eligió Merge Sort porque es muy adecuado para listas ligadas, siempre es O(n log n) y es estable. El ordenamiento sirve para consultar las mascotas de cuatro formas distintas (nombre, edad, especie y raza), mantener ese orden para volver a mostrarlo y guardarlo en un archivo.

**SICT0303 (implementación):** el programa está separado en archivos (`mascota`, `lista`, `ordenamiento` y `main`), tiene su propia lista con memoria dinámica (`new` y `delete`), lee y escribe archivos y tiene comentarios en el código. Se amplió `mascotas.csv` a 24 mascotas, con nombres y edades repetidos para probar que el ordenamiento es estable.

**SEG0701 (cultura digital):** se usa Git y GitHub para guardar las versiones del proyecto, se documenta en Markdown y el código está organizado y comentado para que otras personas lo entiendan.

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

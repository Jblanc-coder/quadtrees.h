# quadtrees.h
# Implementación de Árboles Cuadráticos (Quadtrees) en C++

## Descripción
Este repositorio contiene el diseño e implementación algorítmica desde cero de una estructura de datos **Quadtree** (Árbol Cuadrático) en C++. 

Los Quadtrees son estructuras de árbol donde cada nodo interno tiene exactamente cuatro hijos. Son especialmente eficientes para la partición del espacio bidimensional y la compresión de datos, siendo ampliamente utilizados en computación gráfica, procesamiento de imágenes (representación de píxeles) y sistemas de información geográfica.

Este proyecto fue desarrollado como parte de mi especialización en Ciencias de la Computación, uniendo el rigor matemático con buenas prácticas de programación y análisis de complejidad espacial y temporal.

## Características Principales

* **Compresión de Datos:** Implementación de la función `plantar`, que evalúa y fusiona automáticamente los nodos hijos si todos comparten el mismo estado (Blanco o Negro), optimizando la memoria y logrando una compresión efectiva de la información en tiempo constante `O(1)`.
* **Transformación Matriz-a-Árbol:** Algoritmo recursivo `matriztoArb` capaz de tomar una matriz booleana 2D de tamaño 2^n x 2^n y transformarla en su correspondiente Quadtree jerárquico.
* **Procesamiento de Imágenes (Negativo):** Algoritmo de inversión de valores (`negativo()`) que recorre la estructura del árbol devolviendo una nueva instancia con los valores invertidos, simulando el efecto de un negativo fotográfico.
* **Gestión de Memoria:** Uso cuidadoso de punteros y referencias en C++ para evitar fugas de memoria y copias innecesarias de datos pesados.

## Especificación Técnica y Operaciones

El árbol maneja tres estados de color para los nodos:
* `B` (Blanco): Nodo hoja monocromático.
* `N` (Negro): Nodo hoja monocromático.
* `I` (Intermedio): Nodo interno que se ramifica en 4 hijos.

**Complejidad de las operaciones clave:**
* Consultas de estado (`esBlanco`, `esNegro`, `esVacio`): `O(1)`
* Navegación (`hijo(n)`): `O(1)`
* Fusión y creación de subárboles (`plantar`): `O(1)`
* Transformación desde matriz (`matriztoArb`): `O(n²)` (donde `n` es la dimensión de la matriz).

## Tecnologías
* **Lenguaje:** C++ (Estándar orientado a objetos).
* **Estructuras de datos:** Árboles n-arios, Vectores STL 2D.

## Estructura del Código
* `arbquad.h`: Contiene la especificación formal del TAD (Tipo Abstracto de Datos), la definición de las clases `TNodoQuad` y `TArbQuad`, y la implementación detallada de los métodos.

## Contacto
Estudiante de último año de Matemáticas y Ciencias de la Computación en la Universidad Complutense de Madrid. 
* **LinkedIn:** www.linkedin.com/in/juan-blanco-guillén 

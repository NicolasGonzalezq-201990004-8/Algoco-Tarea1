## Análisis algoritmos Dividir y Conquistar
Nicolás González

201990004-8



## Resumen del trabajo

En el presente repositorio se encuentran los códigos utilizados para la elaboración del informe correspondiente al análisis de distintos algoritmos 
Dividir y conquistar.

* Ordenamiento: InsertionSort, QuickSort, MergeSort y std:Sort.
* Multiplicación de matrices: Solución cúbica, Solución cúbica optimizada y Algoritmo de Strassen.

Los códigos correspondientes a ordenamiento fueron realizados en C++, mientras que
los códigos relacionados con Multiplicación de matrices fueron escritos en Python.

### Requisitos adicionales

Debido a lo anterior, es necesario que esté instalada la última versión de numpy, esto se puede hacer escribiendo 
en la terminal de python lo siguiente:
* numpy
  ```sh
  pip install numpy
  ```

## Uso de los programas

En el repositorio hay presentes 2 carpetas; Matrices y Ordenamiento

#### Matrices

* Dentro de esta carpeta encontrarán el archivo Strassen.py el cual posee la implementación de los 3 algoritmos de multiplicación, en la línea 71 del código es importante que se modifique el valor de la variable N, esta variable indica hasta que valor de NxN se hará la multiplicación. Este valor está por defecto en 1024. Simplemente ejecute el programa de la forma que más le acomode y este imprimirá los tiempos de ejecución en [ms] de cada uno de los algoritmos:
  ```sh
  i = 2
  Tiempo de ejecución de la multiplicación normal: 0.000000 s
  Tiempo de ejecución del algoritmo de Strassen: 0.000000 s
  Tiempo de ejecución del algoritmo optimizado: 0.000000 s
  i = 4
  Tiempo de ejecución de la multiplicación normal: 0.000000 s
  Tiempo de ejecución del algoritmo de Strassen: 0.000000 s
  Tiempo de ejecución del algoritmo optimizado: 0.000000 s
  i = 8
  Tiempo de ejecución de la multiplicación normal: 0.000000 s
  Tiempo de ejecución del algoritmo de Strassen: 2.030273 s
  Tiempo de ejecución del algoritmo optimizado: 1.002686 s
  .
  .
  .
  Hasta 1024 o un i más pequeño si se modifica el valor de N.
  ```

### Ordenamiento

En esta carpeta encontrará 3 archivos: genrand.cpp, genord.cpp y Sorting.cpp.
  
* genrand.cpp: Este archivo genera un txt llamado num_rand con una cantidad (input de usuario) de enteros (1 a 9) aleatorios, los cuales son escritos
  linea por linea en el archivo. Ejemplo de uso:
  ```sh
  g++ genrand.cpp -o random
  ./random
  ```
  ```sh
  Ingrese la cantidad de numeros aleatorios a generar: 
  ```
  
* genord.cpp: Este archivo genera un txt llamado num_ord, el cual contiene una cantidad (input de usuario) de enteros (1 a 9) ordenados, el porcentaje de
  ordenamiento (descendente) del output es pedido por input de usuario. Ejemplo de uso:
  ```sh
  g++ genord.cpp -o ordenados
  ./ordenados
  ```
  ```sh
  Ingrese la cantidad de numeros aleatorios a generar: 
  Ingrese el porcentaje de números ordenados descendientemente (0-100): 
  ```
  
* Sorting.cpp: Con los archivos de texto ya generados editar la linea 192 del archivo, la cual contiene el nombre del archivo de texto, del cual se 
  extraerán los números. Esta es la linea en cuestión: 

  ```sh
  // Abrir archivo de texto en modo de lectura.
    std::ifstream infile("archivo_de_texto.txt");
    if (!infile.is_open()) {
        std::perror("Error al abrir el archivo");
        return 1;
    }
  
  Reemplazar "archivo_de_texto.txt" por "num_rand.txt" o "num_ord.txt", dependiendo de lo que se quiera hacer
  ```
  Finalmente compilar y ejecutar el archivo:
  
  ```sh
  g++ Sorting.cpp -o Sort
  ./Sort
  ```
  Lo anterior va a imprimir los tiempos de ejecución (en microsegundos) de los algoritmos MergeSort, QuickSort, std::Sort e InsertionSort con el siguiente formato:
  
  ```sh
  Tiempo del mergeSort: 266516 μs.
  Tiempo del QuickSort: 128401 μs.
  Tiempo del sort ( header <algorithm> ): 165725 μs.
  Tiempo del InsertionSort: 1058718869 μs.
  ```
  

#include <iostream>
#include <vector> 
#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>

using namespace std::chrono;
using namespace std; 

/*
NombreFuncion: selectionSort

Parametro 1: vector<int>& arreglo - Vector a ordenar
Parametro 2: int n - Tamaño del vector

Retorno: void
*/
void selectionSort(vector<int>& arreglo, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arreglo[j] < arreglo[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
            swap(arreglo[min_idx], arreglo[i]);
    }
}

/*
NombreFuncion: Merge

Parametro 1: vector<int>& arreglo - Vector a ordenar
Parametro 2: int inicio - Índice inicial de la parte del vector
Parametro 3: int medio - Índice medio del vector
Parametro 4: int fin - Índice final de la parte del vector

Retorno: void
*/
void Merge(vector<int>& arreglo, int inicio, int medio, int fin)
{
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;
    vector<int> izquierda(n1), derecha(n2);

    for (int i = 0; i < n1; i++)
        izquierda[i] = arreglo[inicio + i];
    for (int j = 0; j < n2; j++)
        derecha[j] = arreglo[medio + 1 + j];

    int i = 0, j = 0;
    int k = inicio;

    for (; i < n1 && j < n2; k++) {
        if (izquierda[i] <= derecha[j]) {
            arreglo[k] = izquierda[i];
            i++;
        }
        else {
            arreglo[k] = derecha[j];
            j++;
        }
    }


    for (; i < n1; i++, k++) {
        arreglo[k] = izquierda[i];
    }

    for (; j < n2; j++, k++) {
        arreglo[k] = derecha[j];
    }
}

/*
NombreFuncion: MergeSort

Parametro 1: vector<int>& arreglo - Vector a ordenar
Parametro 2: int inicio - Índice inicial del vector
Parametro 3: int fin - Índice final del vector

Retorno: void
*/
void MergeSort(vector<int>& arreglo, int inicio, int fin)
{
    if (inicio >= fin)
        return;

    int medio = inicio + (fin - inicio) / 2;
    MergeSort(arreglo, inicio, medio);
    MergeSort(arreglo, medio + 1, fin);
    Merge(arreglo, inicio, medio, fin);
}

/*
NombreFuncion: insertion_sort

Parametro 1: vector<int>& arreglo - Vector a ordenar
Parametro 2: int n - Tamaño del vector

Retorno: void
*/
void insertion_sort(vector<int>& arreglo, int n) {
    for (int i = 1; i < n; i++) {
        int aux = arreglo[i]; 
        int aux2 = i - 1; 

      
        for (; aux2 >= 0 && arreglo[aux2] > aux; aux2--) {
            arreglo[aux2 + 1] = arreglo[aux2]; 
        }

        arreglo[aux2 + 1] = aux; 
    }
}

/*
NombreFuncion: HoaresPart

Parametro 1: vector<int>& arreglo - Vector a particionar
Parametro 2: int bajo - Índice inferior
Parametro 3: int alto - Índice superior

Retorno: int - Pivote
*/
int Partition(vector<int>& arreglo, int bajo, int alto) {
    int pivote = arreglo[bajo];
    int i = bajo - 1, j = alto + 1;

    for (;;) {
    
        for (i++; arreglo[i] < pivote; i++);
        for (j--; arreglo[j] > pivote; j--);

        if (i >= j)
            return j;

        swap(arreglo[i], arreglo[j]);
    }
}

/*
NombreFuncion: QuickSort\

Parametro 1: vector<int>& arreglo - Vector a ordenar
Parametro 2: int bajo - Índice inferior
Parametro 3: int alto - Índice superior

Retorno: void
*/
void QuickSort(vector<int>& arreglo, int bajo, int alto) {

    if (bajo < alto) {
        int pi = Partition(arreglo, bajo, alto);

        QuickSort(arreglo, bajo, pi);
        QuickSort(arreglo, pi + 1, alto);
    }
}


int main() {
    // Pedir al usuario el largo del arreglo
    int n;
    std::cout << "Ingrese el largo del vector a ordenar: ";
    std::cin >> n;

    // Verificación de errores.
    if (n <= 0) {
        std::cerr << "El tamaño del arreglo debe ser mayor que 0." << std::endl;
        return 1;
    }

    // Crear vectores para almacenar los arreglos a ordenar.
    std::vector<int> arreglo;
    arreglo.reserve(n); 

    std::vector<int> arreglo2;
    arreglo2.reserve(n);

    std::vector<int> arreglo3;
    arreglo3.reserve(n);

    std::vector<int> arreglo4;
    arreglo4.reserve(n);

    // Abrir archivo de texto en modo de lectura.
    std::ifstream infile("num_ord.txt");
    if (!infile.is_open()) {
        std::perror("Error al abrir el archivo");
        return 1;
    }

    // Lectura de numeros de archivos de texto.
    int num;
    int count = 0;
    while (infile >> num && count < n) {
        arreglo.push_back(num);
        arreglo2.push_back(num);
        arreglo3.push_back(num);
        arreglo4.push_back(num);
        count++;
    }

    if (count < n) {
        std::cerr << "El archivo no contiene suficientes números." << std::endl;
        return 1;
    }

    infile.close();

	high_resolution_clock::time_point start1 = high_resolution_clock::now();
	MergeSort(arreglo, 0, n - 1);
	high_resolution_clock::time_point end1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(end1 - start1).count();
	std::cout << "Tiempo del mergeSort: " << duration1 << " μs.\n";

    high_resolution_clock::time_point start3 = high_resolution_clock::now();
	QuickSort(arreglo3, 0, n - 1);
	high_resolution_clock::time_point end3 = high_resolution_clock::now();
	auto duration3 = duration_cast<microseconds>(end3 - start3).count();
	std::cout << "Tiempo del QuickSort: " << duration3 << " μs.\n";

    high_resolution_clock::time_point start4 = high_resolution_clock::now();
	sort(arreglo4.begin(), arreglo4.end());
	high_resolution_clock::time_point end4 = high_resolution_clock::now();
	auto duration4 = duration_cast<microseconds>(end4 - start4).count();
	std::cout << "Tiempo del sort ( header <algorithm> ): " << duration4 << " μs.\n";

    high_resolution_clock::time_point start2 = high_resolution_clock::now();
	selectionSort(arreglo2, n);
	high_resolution_clock::time_point end2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(end2 - start2).count();
	std::cout << "Tiempo del InsertionSort: " << duration2 << " μs.\n";

    return 0;
}
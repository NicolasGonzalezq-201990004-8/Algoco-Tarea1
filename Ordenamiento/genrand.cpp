#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>

int main() {
    int n;
    std::cout << "Ingrese la cantidad de numeros aleatorios a generar: ";
    std::cin >> n;

    std::ofstream outfile("num_rand.txt");
    if (!outfile.is_open()) {
        std::perror("Error al abrir el archivo");
        return 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 9);

    auto start = std::chrono::high_resolution_clock::now();

    std::string buffer;
    buffer.reserve(n * 8); 

    for (int i = 0; i < n; ++i) {
        buffer += std::to_string(distrib(gen)) + '\n';
    }
 
    outfile << buffer;
    outfile.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tiempo de ejecución: " << duration.count() << " segundos" << std::endl;

    return 0;
}

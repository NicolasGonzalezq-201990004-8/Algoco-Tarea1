#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm> 

int main() {
    int n;
    std::cout << "Ingrese la cantidad de numeros aleatorios a generar: ";
    std::cin >> n;

    double desc_percent;
    std::cout << "Ingrese el porcentaje de números ordenados descendientemente (0-100): ";
    std::cin >> desc_percent;

    if (desc_percent < 0 || desc_percent > 100) {
        std::cerr << "El porcentaje debe estar entre 0 y 100." << std::endl;
        return 1;
    }

    std::ofstream outfile("num_ord.txt");
    if (!outfile.is_open()) {
        std::perror("Error al abrir el archivo");
        return 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 9);

    int desc_count = static_cast<int>(n * (desc_percent / 100.0));

    std::vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        numbers[i] = distrib(gen);
    }

    std::sort(numbers.begin(), numbers.begin() + desc_count, std::greater<int>());

    auto start = std::chrono::high_resolution_clock::now();

    std::string buffer;
    buffer.reserve(n * 8); 

    for (int i = 0; i < n; ++i) {
        buffer += std::to_string(numbers[i]) + '\n';
    }

    outfile << buffer;
    outfile.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tiempo de ejecución: " << duration.count() << " segundos" << std::endl;

    return 0;
}
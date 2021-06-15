// Para compilar: $g++ -O3 exemplo1.cpp -o exemplo1 -fopenmp

#include <omp.h>
#include <iostream>

int main() {
    #pragma omp parallel for
    for (int i = 0; i < 16; i++) {
        std::cout << i << " Eu rodei na thread: " << omp_get_thread_num() << "\n";
    }
    return 0;
}

// Não é possível predizer o resultado do código acima
// No caso acima o loop foi dividido igualmente entre as threads, mas isso é uma decisão do compilador e não temos controle sobre qual será seu comportamento. Isso pode variar de compilador para compilador.
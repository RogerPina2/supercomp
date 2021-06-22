// Para compilar: $g++ -O3 exemplo1.cpp -o exemplo1 -fopenmp
// Para rodar alterando o número de threads: $OMP_NUM_THREADS=2 ./exemplo1

#include <iostream>
#include <omp.h>

int main() {
    // cria regiões paralelas e roda OMP_NUM_THREADS threads que rodam o bloco de código de maneira independente
    #pragma omp parallel 
    {
        std::cout << "ID:" << omp_get_thread_num() << "/" << 
                           omp_get_num_threads() << "\n";
    }
    std::cout << "Join implicito no fim do bloco!" << "\n";
    return 0;
}
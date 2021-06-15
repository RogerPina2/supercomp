// Para compilar: $g++ -O3 exemplo3.cpp -o exemplo3 -fopenmp

#include <omp.h>
#include <iostream>

int main() {

    // static: menos trabalho em tempo de execução, escalonamento feito em tempo de compilação
    #pragma omp parallel for schedule(static, 1)

    for (int i = 0; i < 16  ; i++) {
        std::cout << i << " Eu rodei na thread: " << omp_get_thread_num() << "\n";
    }
    return 0;
}

// QUESTÕES

// 1. Quantos cores, no máximo, serão usados?
// Serão usados 4 cores, no máximo

// 2. Você consegue dizer em qual thread cada iteração rodará?
// Sim, como a alocação é estática, as iterações rodam sequencialmente nas threads

// 3. Você consegue dizer quantas iterações cada thread rodará?
// Sim, cada thread rodará 4 iterações (são 16 iterações para 4 threads)

// 4. As alocações mudam a cada execução do programa?
// Não, as alocações são estáticas, sendo definidas na compilação do programa
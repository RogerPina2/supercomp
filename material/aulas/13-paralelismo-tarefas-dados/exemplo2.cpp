// Para compilar: $g++ -O3 exemplo2.cpp -o exemplo2 -fopenmp

#include <omp.h>
#include <iostream>

int main() {

    // dynamic: mais trabalho em tempo de execução, lógica de escalonamento mais complexa, consumindo tempo de execução
    #pragma omp parallel for schedule(dynamic, 4)

    for (int i = 0; i < 16  ; i++) {
        std::cout << i << " Eu rodei na thread: " << omp_get_thread_num() << "\n";
    }
    return 0;
}

// QUESTÕES

// 1. Quantos cores, no máximo, serão usados?
// Serão usados no máximo 4 cores

// 2. Você consegue dizer em qual thread cada iteração rodará?
// Não, elas são alocadas dinamicamente nas threads disponíveis

// 3. Você consegue dizer quantas iterações cada thread rodará?
// Sim, cada thread rodará 4 iterações

// 4. Suponha que a thread 4 iniciou a iteração i=4. Ela processará somente essa iteração isoladamente?
// Se sim, explique por que. Se não, diga até qual valor de i ela executará.
// Não, ela processará as threads 4, 5, 6 e 7

// 5. As alocações mudam a cada execução do programa?
// Sim, o compilador é quem faz a alocação
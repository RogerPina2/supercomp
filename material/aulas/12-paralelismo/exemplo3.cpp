#include <iostream>
#include <omp.h>

int main() {
    // cria regiões paralelas
    #pragma omp parallel
    {
        // cria uma tarefa
        #pragma omp task
        {
            std::cout << "Estou rodando na tarefa " << omp_get_thread_num() << "\n";
        }
    }
    std::cout << "eu só rodo quando TODAS tarefas acabarem.\n";

    return 0;
}

// como cada thread roda o código da região paralela, cada uma cria exatamente uma tarefa
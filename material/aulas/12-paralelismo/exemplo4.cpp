#include <iostream>
#include <omp.h>

int main() {
    // cria regiões paralelas
    #pragma omp parallel 
    {
        // controlar a criação de tarefas
        // executa somente na thread de índice 0
        #pragma omp master 
        {
            std::cout << "só roda uma vez na thread:" << omp_get_thread_num() << "\n";
            // cria somente uma tarefa
            #pragma omp task 
            {
                std::cout << "Estou rodando na thread:" << omp_get_thread_num() << "\n";
            }
        }
    }

    return 0;
}
#include <iostream>
#include <chrono>

static long num_steps = 1000000000;
double step;

int main() {
    double pi, sum = 0.0;
    step = 1.0 / (double)num_steps;

    auto start_time = std::chrono::high_resolution_clock::now();

    #pragma omp parallel
    {
        #pragma omp master
        {
            #pragma omp parallel for reduction(+:sum)
            for (int i = 0; i < num_steps; i++) {
                double x = (i + 0.5) * step;
                sum = sum + 4.0 / (1.0 + x * x);
            }
        }
    }


    pi = step * sum;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::seconds> (end_time - start_time);
    
    std::cout << "O valor de pi calculado com " << num_steps << " passos levou ";
    std::cout << runtime.count() << " segundo(s) e chegou no valor : ";
    std::cout.precision(17);
    std::cout << pi << std::endl;
}

// poderíamos dividir o for na metade e fazer cada metade em uma tarefa
// 1. a primeira tarefa deverá guardar seu resultado na variável res_parte1
// 2. a segunda tarefa deverá guardar seu resultado na variável res_parte2
// 3. você deverá somar os dois resultados após as tarefas acabarem
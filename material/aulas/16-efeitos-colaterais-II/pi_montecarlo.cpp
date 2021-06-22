// Para compilar: $g++ -O3 -fopenmp pi_montecarlo.cpp -o pi_montecarlo

#include <iostream>
#include <random>

int main() {
    std::default_random_engine gen;
    std::uniform_real_distribution<double> dist;

    int N = 100000;
    long sum = 0;

    #pragma omp parallel for reduction(+:sum) default(none) firstprivate(N) shared(dist, gen)
    for (int i = 0; i < N; i++) {
        double x, y;
        #pragma omp critical
        {
            x = dist(gen);
            y = dist(gen);
        }

        if (x*x + y*y <= 1) {
            sum++;
        }
    }

    double pi = 4.0 * sum / N;

    std::cout << "PI: " << pi << "\n";
    std::cout << sum << "\n";
}

// A variável dist (sorteio de pontos) é um processo sequencial que depende dos números anteriormente 
// sorteados, e, portanto, gera efeitos colaterais.
// Para evitar problemas ao compartilhar o gerador de números aleatórios, 
// usamos omp critical no sorteio de pontos x e y
// Desde que os pares x, y sorteados sejam os mesmos, o for pode rodar em qualquer ordem 
// que os resultados não irão sofrer alterações
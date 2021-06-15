// Para compilar: $g++ -O3 -fopenmp pi_montecarlo_1.cpp -o pi_montecarlo_1

#include <iostream>
#include <random>

int main() {
    int N = 100000;
    long sum = 0;

    #pragma omp parallel for reduction(+:sum) default(none) firstprivate(N)
    for (int i = 0; i < N; i++) {

        std::default_random_engine gen(13 * i);
        std::uniform_real_distribution<double> dist;
        
        double x = dist(gen);
        double y = dist(gen);

        if (x*x + y*y <= 1) {
            sum++;
        }
    }

    double pi = 4.0 * sum / N;

    std::cout << "PI: " << pi << "\n";
    std::cout << sum << "\n";
}
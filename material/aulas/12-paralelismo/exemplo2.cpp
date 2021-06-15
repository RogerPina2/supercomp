// Para compilar: $g++ -O3 exemplo2.cpp -o exemplo2 -fopenmp
// Para rodar alterando o número de threads: $OMP_NUM_THREADS=2 ./exemplo2

#include <iostream>
#include <omp.h>

int main() {
    // declara a variável fora da região paralela, e, portanto, só existe uma variável res
    int res = 1;
    #pragma omp parallel 
    {
        for (int i = 0; i < 1000; i++) {
            res += 1;
        }
    }
    std::cout << res << "\n";
    return 0;

}

// cada thread possui uma dependência em relação a res
// se duas threads tem uma dependência de escrita na mesma variável coisas ruins acontecerão
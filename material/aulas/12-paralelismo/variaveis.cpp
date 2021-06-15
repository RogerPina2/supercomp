#include <omp.h>
#include <iostream>

int main() {
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
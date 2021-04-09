#include <iostream>
#include <vector>

int valor(std::vector<bool> usados, std::vector<int> valores) {
    int total;

    for (int i=0; i<usados.size(); i++) {
        if (usados[i]) {
            total += valores[i];
        }
    }

    return total;
}

int mochila(std::vector<int> p, std::vector<int> v, int N, int c, int i, std::vector<bool> &usados, std::vector<bool> &melhor) {

    if (i == N) {
        if (valor(usados, v) > valor(melhor, v)) {
            melhor = usados
        }
    }
    return 0;
}

struct solucao {
    
};

int main() {


    return 0;
}
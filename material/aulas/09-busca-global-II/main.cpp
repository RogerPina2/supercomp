#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

struct objeto {
    int id;
    int peso;
    int valor;
};

struct solucao {
    std::vector<bool> usado;
    int valor;
    int peso;

    solucao (int N) {
        usado.resize(N, false);
        valor = peso = 0;
    }
};

long num_copy = 0;

void busca_exaustiva(std::vector<objeto> &obj, int C, solucao &melhor, solucao &atual, int i = 0) {
    if (i == obj.size()) {
        if (atual.valor > melhor.valor) {
            melhor = atual;
            num_copy++;
        }
        return;
    }

    if (obj[i].peso <= C) {
        atual.usado[i] = true;
        atual.valor += obj[i].valor;
        atual.peso += obj[i].peso;
        busca_exaustiva(obj, C - obj[i].peso, melhor, atual, i+1);

        atual.usado[i] = false;
        atual.valor -= obj[i].valor;
        atual.peso -= obj[i].peso;
    }

    atual.usado[i] = false;
    busca_exaustiva(obj, C, melhor, atual, i+1);
}

int main() {
    int N, W;
    std::cin >> N >> W;
    std::vector<objeto> objetos(N);

    for (int i=0; i<N; i++) {
        objetos[i].id = i;
        std::cin >> objetos[i].peso >> objetos[i].valor;
    }
    
    solucao melhor(N);
    solucao atual(N);
    busca_exaustiva(objetos, W, melhor, atual);

    std::cout << melhor.peso << " " << melhor.valor << " 1\n";
    for (int i = 0; i < N; i++) {
        if (melhor.usado[i]) {
            std::cout << i << " ";
        }
    }

    std::cout << "\n";
    std::cerr << "num copy" << num_copy << "\n";

    return 0;
}
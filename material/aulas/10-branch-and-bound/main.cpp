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

long num_copy = 0, num_leafs = 0, num_bounds = 0;
std::vector<long> bound_level;

void busca_exaustiva(std::vector<objeto> &obj, int C, 
                    solucao &melhor, 
                    solucao &atual, 
                    int limite_superior_valor, int i = 0) {

    int size = obj.size();
    if (i == size) {
        num_leafs++;
        if (atual.valor > melhor.valor) {
            melhor = atual;
            num_copy++;
        }
        return;
    }

    // Vale a pena continuar?
    int incluir_todos = atual.valor + limite_superior_valor;
    if (incluir_todos <= melhor.valor) {
        num_bounds++;
        bound_level[i]++;
        return;
    }

    if (obj[i].peso <= C) {
        atual.usado[i] = true;
        atual.valor += obj[i].valor;
        atual.peso += obj[i].peso;
        busca_exaustiva(obj, C - obj[i].peso, melhor, atual, limite_superior_valor - obj[i].valor, i+1);

        atual.usado[i] = false;
        atual.valor -= obj[i].valor;
        atual.peso -= obj[i].peso;
    }

    atual.usado[i] = false;
    busca_exaustiva(obj, C, melhor, atual, limite_superior_valor - obj[i].valor, i+1);
} 

int main() {
    int N, W;
    std::cin >> N >> W;
    std::vector<objeto> objetos(N);

    int limite_superior_valor = 0;
    for (int i=0; i<N; i++) {
        objetos[i].id = i;
        std::cin >> objetos[i].peso >> objetos[i].valor;
        limite_superior_valor += objetos[i].valor;
    }
    
    bound_level.resize(N, 0);

    solucao melhor(N);
    solucao atual(N);
    busca_exaustiva(objetos, W, melhor, atual, limite_superior_valor);

    std::cout << melhor.peso << " " << melhor.valor << " 1\n";
    for (int i = 0; i < N; i++) {
        if (melhor.usado[i]) {
            std::cout << i << " ";
        }
    }

    std::cout << "\n";
    std::cerr << "num copy" << num_copy << "\n";
    std::cerr << "num leafs" << num_leafs << "\n";
    std::cerr << "num bounds" << num_bounds << "\n";

    for (int i = 0; i < N; i++) {
        std::cout << bound_level[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
#include <vector>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

double conta_complexa(int i)
{
	return 2 * i;
}

int main()
{
	int N = 32;
	std::vector<double> vec(N);
	#pragma omp parallel for shared(vec)
		for (int i = 0; i < N; i++)
		{
			vec[i] = conta_complexa(i);
		}

		for (int i = 0; i < N; i++)
		{
			std::cout << vec[i] << " ";
		}
	std::cout << "\n";
	return 0;
}

// A variável i é private para cada processo da thread
// A variável vec é shared para todos os processos
// Porém, o código paralelizável dá erro pois a operação push_back modifica o vetor! Ou seja, é equivalente às operações de escrita que fazíamos nas aulas anteriores (e que também davam errado).
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>
#include <chrono>

int main() {
    thrust::host_vector<double> host;
    // thrust::sequence(host.begin(), host.end());

    while (std::cin.good()) {
        double t;
        std::cin >> t;
        host.push_back(t);
    }
    
    thrust::device_vector<double> dev(host);
    
    // 1. O preço médio das ações nos últimos 10 anos.
    double media_gpu = thrust::reduce(dev.begin(), dev.end(), 0, thrust::plus<double>()) / dev.size();

    // 2. O preço médio das ações no último ano (365 anos atrás).
    double media_gpu_ua = thrust::reduce(dev.end()-365, dev.end(), 0, thrust::plus<double>()) / dev.size();

    // 3. O maior e o menor preço da sequência inteira e do último ano.
    double max = thrust::reduce(dev.begin(), dev.end(), 0, thrust::maximum<double>());
    double min = thrust::reduce(dev.begin(), dev.end(), 0, thrust::minimum<double>());
    double max_ua = thrust::reduce(dev.end() - 365, dev.end(), 0, thrust::minimum<double>());
    double min_ua = thrust::reduce(dev.end() - 365, dev.end(), 0, thrust::minimum<double>());

    std::cout << dev[0] << "\n";
}


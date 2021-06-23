#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>
#include <chrono>

int main() {
    thrust::host_vector<double> host;

    while (std::cin.good()) {
        double t;
        std::cin >> t;
        host.push_back(t);
    }
    
    auto start_time = std::chrono::high_resolution_clock::now();
    thrust::device_vector<double> dev(host);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::seconds> (end_time - start_time);

    std::cout << dev.size() << "\n";
    std::cout << runtime.count() << "\n";
}


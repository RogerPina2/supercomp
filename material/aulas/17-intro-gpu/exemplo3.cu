#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>

int main() {
    thrust::host_vector<double> host;

    while (std::cin.good()) {
        double t;
        std::cin >> t;
        host.push_back(t);
    }

    thrust::device_vector<double> dev(host);

    std::cout << dev.size() << "\n";
}


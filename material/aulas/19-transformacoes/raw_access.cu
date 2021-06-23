#include <thrust/device_vector.h>
#include <thrust/iterator/counting_iterator.h>
#include <iostream>

struct ponto {
    double x, y;
};

struct raw_access {
    ponto *ptr;

    raw_access (ponto *ptr) : ptr(ptr) {};

    __device__ __host__
    ponto operator()(const ponto {&x, &y}) {
        ptr[i].x += 1;
        return ptr[i];
    }
};

int main() {
    thrust::device_vector<ponto> vec(10, (ponto) {2, 3});
    thrust::device_vector<ponto> vec2(10, (ponto) {4, 3});

    thrust::counting_iterator<int> iter(0);
    raw_access ra(thrust::raw_pointer_cast(vec.data()));
    thrust::transform(vec, iter+vec2.size(), vec2.begin(), ra);

    thrust::host_vector<ponto> cpu(vec2);
    for (const auto &d : cpu) {
        std::cout << d.x << "\n";
    }

    return 0;
}

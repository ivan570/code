#include <iostream>
#include <cmath>

int main() {
    long long int n, m, a;
    std::cin >> n >> m >> a;

    std::cout << (long long int)(std::ceil((long double)n / a) * std::ceil((long double)m / a)) << std::endl;

    return 0;
}
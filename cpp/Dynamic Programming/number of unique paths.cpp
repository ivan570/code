#include <iostream>

int recu(int m, int n) {
    if (m == 1 || n == 1)
        return 1;
    return recu(m - 1, n) + recu(m, n - 1);
}

void test_case() {
    int m, n;
    std::cin >> m >> n;
    std::cout << recu(m, n) << std::endl;
}

int main() {
    int test;
    std::cin >> test;
    for (int i = 0; i < test; ++i)
        test_case();
    return 0;
}

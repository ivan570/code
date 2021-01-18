#include <iostream>

int main() {
    int test;
    std::cin >> test;
    for (int index = 0; index < test; ++index) {
        int size;
        long long int odd = 0, even = 0;
        std::cin >> size;
        int array[size];
        for (int i = 0; i < size; ++i) {
            std::cin >> array[i];
            if (i % 2)
                odd += array[i];
            else
                even += array[i];
        }

        if (odd < even) {
            for (int i = 0; i < size; ++i) {
                int print;
                if (i % 2)
                    print = 1;
                else
                    print = array[i];
                std::cout << print << " ";
            }
        } else {
            for (int i = 0; i < size; ++i) {
                int print;
                if (i % 2 == 0)
                    print = 1;
                else
                    print = array[i];
                std::cout << print << " ";
            }
        }

    }
    return 0;
}
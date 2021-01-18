#include <iostream>
#include <vector>
#define MAX 300000004.23f

int main()
{
    std::vector<int> int_arr;
    std::cout << int_arr.max_size() * sizeof(int) << std::endl;

    std::vector<double> double_arr;
    std::cout << double_arr.max_size() * sizeof(double) << std::endl;

    std::vector<float> float_arr;
    std::cout << float_arr.max_size() * sizeof(float) << std::endl;

    std::cout << sizeof(MAX) << std::endl;
    std::cout << typeid(MAX).name() << std::endl;
    std::cin.get();
    return 0;
}

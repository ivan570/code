#include <iostream>

bool cases() {
    long a, b, c;
    std::cin >> a >> b >> c;
    long k = (a + b + c);
    if (k % 9 != 0)
        return false;
    k /= 9;
    return std::min(std::min(a, b), c) >= k;
}

int main() {
    int test;
    std::cin >> test;
    for (int index = 0; index < test; ++index) {
        std::string str;
        if (cases())
            str = "YES";
        else
            str = "NO";
        std::cout << str << std::endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

long long getWinner(std::vector<int> &array, unsigned int n) {
    std::sort(array.begin(), array.end(), std::greater<>());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if ((i % 2) == 0) {
            if ((array[i] % 2) == 0)
                ans += array[i];
        }
        else {
            if ((array[i] % 2) == 1)
                ans -= array[i];
        }
    }
    return ans;
}

void cases() {
    int n;
    std::cin >> n;
    std::vector<int> array(n);
    for (int i = 0; i < n; ++i)
        std::cin >> array[i];
    long long ans = getWinner(array, n);
    if (ans > 0)
        std::cout << "Alice";
    else if (ans < 0)
        std::cout << "Bob";
    else
        std::cout << "Tie";
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        cases();
    return 0;
}
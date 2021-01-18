#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> array;

int add() {
    int n;
    std::string str;
    std::cin >> n >> str;
    if (n == 0) {
        array.push_back(str);
    }
    else {
        for (const std::string &string : array) {
            if (str.find(string) != std::string::npos)
                return 1;
        }
        return 0;
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int ans = add();
        if (ans == -1)
            continue;
        else if (ans == 0)
            std::cout << "NO" << std::endl;
        else if (ans == 1)
            std::cout << "YES" << std::endl;
    }
    return 0;
}

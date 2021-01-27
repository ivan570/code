// https://codeforces.com/problemset/problem/320/A
#include <string>
#include <iostream>
#include <algorithm>

bool valid(std::string str) {
    int pos = -1;
    while ((pos = str.find("144", pos + 1)) != std::string::npos) {
        str[pos] = 'X';
        str[pos + 1] = 'X';
        str[pos + 2] = 'X';
    }
    pos = -1;
    while ((pos = str.find("14", pos + 1)) != std::string::npos) {
        str[pos] = 'X';
        str[pos + 1] = 'X';
    }
    pos = -1;
    while ((pos = str.find('1', pos + 1)) != std::string::npos) {
        str[pos] = 'X';
    }
    return std::all_of(str.begin(), str.end(), [](unsigned char ch) { return ch == 'X'; });
}

int main() {
    std::string str;
    std::cin >> str;
    if (valid(str))
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}

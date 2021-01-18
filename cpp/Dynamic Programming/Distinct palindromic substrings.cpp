#include <iostream>
#include <unordered_set>

bool isPalindromic(const std::string &str) {
    if (str.length() < 2)
        return true;
    unsigned int i = 0, j = str.length() - 1;
    while (i <= j) {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int numberOfSubStrWhichArePalindromic(const std::string &str) {
    std::unordered_set<std::string> set;
    for (int i = 0; i < str.length(); ++i) {
        for (int j = 1; j <= str.length() - i; ++j) {
            if (isPalindromic(str.substr(i, j)))
                set.insert(str.substr(i, j));
        }
    }
    return set.size();
}

void cases() {
    std::string str;
    std::cin >> str;
    std::cout << numberOfSubStrWhichArePalindromic(str) << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        cases();
    return 0;
}
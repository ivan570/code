#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    std::string ans;
    for (char i : str) {
        if (i == 'A' || i == 'O' || i == 'U' || i == 'I' || i == 'E' || i == 'Y' || i == 'y' || i == 'a' || i == 'o' || i == 'u' || i == 'i' ||
            i == 'e') {}
        else if (i >= 'A' && i <= 'Z')
            ans += "." + std::string(1, char(i + 32));
        else
            ans += "." + std::string(1, i);
//        std::cout << i;
    }
    std::cout << ans << "\n";
    return 0;
}
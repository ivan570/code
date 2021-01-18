#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        int ans = 0;
        for (int j = 1; j < str.length(); ++j) {

            if (str[j] == str[j - 1] && str[j] != 'A' && str[j - 1] != 'A') {
                str[j] = 'A';
                ans++;
            }
            if (j - 2 >= 0 && str[j] == str[j - 2] && str[j] != 'A' && str[j - 2] != 'A') {
                str[j] = 'A';
                ans++;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
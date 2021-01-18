//String LCM

#include <iostream>

int lcm(int s, int t) {
    int result = std::max(s, t);
    while (true) {
        if (result % s == 0 && result % t == 0)
            break;
        result++;
    }
    return result;
}

std::string multiple(std::string str, int k) {
    std::string result;
    while (k >= 1) {
        if (k % 2 == 1)
            result += str;
        k = k / 2;
        str += str;
    }
    return result;
}

void cases() {
    std::string s, t;
    std::cin >> s >> t;
    int l = lcm(s.size(), t.size());
    std::string s_temp = multiple(s, (l / (int)s.size())), t_temp = multiple(t, (l/(int)t.size()));
    if (s_temp == t_temp)
        std::cout << s_temp;
    else
        std::cout << "-1";
    std::cout << std::endl;
}

int main() {
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        cases();
    }
    return 0;
}
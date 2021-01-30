#include <iostream>
#include <unordered_map>

void code() {
    int n;
    std::cin >> n;
    std::unordered_map<int, int> frq;
    for (int i= 0; i < n; ++i) {
        int temp;
        std::cin >> temp;
        frq[temp]++;
    }
    int ans = 0;
    for (auto temp : frq)
        ans = std::max(ans, temp.second);
    std::cout << ans << "\n";
}

int main() {
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i)
        code();
    return 0;
}
//Random Events
#include <iostream>
#include <vector>
#include <cstdio>

void cases() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> per(n);
    for (int &i : per) {
        std::cin >> i;
    }
    int cur = -1;
    for (int i = (int) per.size() - 1; i >= 0; --i) {
        if (per[i] == 1 + i)
            continue;
        else {
            cur = i;
            break;
        }
    }
    float ans = 1.0f;
    if (cur == -1)
        ans = 0.0f;
    for (int i = 0; i < m; ++i) {
        int r;
        float p;
        std::cin >> r >> p;
        if (r > cur)
            ans *= (1 - p);
    }
    printf("%.6f\n", (1 - ans), cur);
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        cases();
    return 0;
}

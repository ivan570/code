#include <iostream>
#include <vector>

void test_case() {
    int n, ans = 0;
    std::cin >> n;
    std::vector<int> vec(n), inc(n, 0), dec(n, 0);
    for (int i = 0; i < n; ++i)
        std::cin >> vec[i];
    for (int i = 0; i < n; ++i) {
        inc[i] = vec[i];
        for (int j = 0; j < i; ++j) {
            if (vec[i] > vec[j] && inc[i] < inc[j] + vec[i])
                inc[i] = inc[j] + vec[i];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        dec[i] = vec[i];
        for (int j = n - 1; j > i; --j) {
            if (vec[i] > vec[j] && dec[i] < dec[j] + vec[i])
                dec[i] = dec[j] + vec[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        ans = std::max(ans, inc[i] + dec[i] - vec[i]);
        std::cout << "inc " << inc[i] << " dec " << dec[i] << std::endl;
    }
    std::cout << ans << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        test_case();
    return 0;
}

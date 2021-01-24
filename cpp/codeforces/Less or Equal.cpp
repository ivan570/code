// https://codeforces.com/problemset/problem/977/C
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> array(n);
    for (int &vl : array)
        std::cin >> vl;

    std::sort(array.begin(), array.end());
    int ans;
    if (k == 0)
        ans = array[0] - 1;
    else
        ans = array[k - 1];
    int c = 0;
    for(int i : array) {
        if (i <= ans)
            c++;
        else
            break;
    }
    if (c != k || (ans < 1) || (ans > 1000 * 1000 * 1000))
        std::cout << "-1";
    else
        std::cout << ans;
    std::cout << "\n";
    return 0;
}

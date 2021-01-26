// https://codeforces.com/problemset/problem/1462/E1
#include <iostream>
#include <vector>
#include <algorithm>
 
long long int find(long long int number) {
    long long int ans = (number * (number + 1)) / 2;
    return ans;
}
 
void closeTuples() {
    int n;
    std::cin >> n;
    std::vector<int> array(n);
    for (int &value : array) {
        std::cin >> value;
    }
 
    std::sort(array.begin(), array.end());
    long long int ans = 0;
//    std::cout << "\n";
    for (int i = 0; i < n; ++i) {
        int min = array[i];
        int max = min + 2;
        int index = std::upper_bound(array.begin(), array.end(), max) - array.begin();
        index--;
        if (index >= i)
            ans += find(index - i - 1);
    }
    std::cout << ans << "\n";
}
 
int main() {
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        closeTuples();
    }
    return 0;
}

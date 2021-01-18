#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(k, 0);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        temp = temp % k;
        arr[temp]++;
    }
    int c = 0;
    if (arr[0] > 0)
        c++;
    for (int i = 1; i < k/2 + 1; ++i) {
        int j = k - i;
        if (i != j) {
            c += max(arr[i], arr[j]);
        }
        if (i == j) {
            c++;
        }
    }
    cout << c;
    return 0;
}

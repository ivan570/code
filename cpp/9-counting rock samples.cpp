#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, r;
    cin >> s >> r;
    vector<int> arr;
    for (int i = 0; i < s; ++i) {
        int temp;
        cin >> temp;
        auto it = lower_bound(arr.begin(), arr.end(), temp);
        arr.insert(it, temp);
    }
    for (int k = 0; k < r; ++k) {
        int min, max, sum = 0;
        cin >> min >> max;
        for (int i : arr) {
            if (i < min)
                continue;
            if (i >= min && i <= max) {
                    sum += 1;
            }
            else {
                break;
            }
        }
        cout << sum << " ";
    }
    return 0;
}

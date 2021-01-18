#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int value = 1, ans = 0;
    if (n >= 2 && arr[1] < arr[0])
        value = 2;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            ans = value;
        }
        else {
            if (arr[i] > arr[i - 1]) {
                value += 1;
                ans += value;
            }
            else {
                value = 1;
                for (int j = i; j < n - 1; ++j){
                    if (arr[j] > arr[j + 1]) {
                        value += 1;
                    }
                    else
                        break;
                }
                ans += value;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

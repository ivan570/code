#include <bits/stdc++.h>
using namespace std;

int toys(vector<int> arr) {
    int temp = 0, ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > arr[temp] + 4) {
            temp = i;
            ans++;
            cout << arr[i] << endl;
        } else {
            cout << arr[i] << " ";
        }

    }
    return ans + 1;
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << toys(arr) << endl;
}
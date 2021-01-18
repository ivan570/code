#include <bits/stdc++.h>
using namespace std;

void getOutput(vector<string> arr) {
    int f = 0;
    for (int i = 0; i < arr.size() - 1; ++i) {
        if (arr[i][f] > arr[i + 1][f]) {
            cout << "NO" << endl;
            return;
        }
        f++;
    }
    for (int i = 0; i < arr.size() - 1; ++i) {
        if (arr[i][f] > arr[i + 1][f]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int test;
    cin >> test;
    for (int T = 0; T < test; ++T) {
        int n;
        cin >> n;
        vector<string> arr(n);
        for (int N = 0; N < n; ++N) {
            string str;
            cin >> str;
            sort(str.begin(), str.end());
            arr[N] = str;
        }
        getOutput(arr);
    }
    return 0;
}

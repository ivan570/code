#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int T = 0; T < t; ++T) {
        int n, f = 0;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i)
            cin >> vec[i];
        for (int i = 0; i < n - 1; ++i) {
            if (vec[i] >= vec[i + 1]) {
                f = 1;
                break;
            }
        }
        if (f)
            cout << "0" << endl;
        else cout << "1" << endl;
    }
    return 0;
}

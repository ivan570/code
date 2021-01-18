#include <bits/stdc++.h>
using namespace std;

int find(vector<int> c, int key) {
    for (int i = 0; i < c.size(); ++i) {
        if (c[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        int f = find(b, a[i]);
        if (f >= 0) {
            ans++;
            b[f] = -1;
        }
    }
    if (ans == n)
    {
        cout << ans - 1;
    }
    else {
        cout << ++ans;
    }
    return 0;
}

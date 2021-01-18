#include <bits/stdc++.h>
using namespace std;

int getOutput(int n, int c, int m) {
    int ans = n/c;
    int remain = ans;
    while (remain >= m) {
        int temp = remain / m;
        ans += temp;
        remain = remain % m + temp;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, c, m;
        cin >> n >> c >> m;
        cout << getOutput(n, c, m) << endl;
    }
    return 0;
}

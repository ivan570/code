#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int k) {
    return (i + j > k && i + k > j && k + j > i);
}

void getOutput(vector<int> rev) {
    sort(rev.begin(), rev.end(), greater<int>());
    for (int i = 0; i < rev.size() - 2; ++i) {
        int first = rev[i];
        int second = rev[i + 1];
        int third = rev[i + 2];
        if (isValid(first, second, third)) {

            cout << third << " " << second << " " << first ;
            return ;
        }
    }
    cout << "-1";
}

int main() {
    int n;
    cin >> n;
    vector<int> stick(n);
    for (int i = 0; i < n; ++i)
        cin >> stick[i];
    getOutput(stick);
    return 0;
}

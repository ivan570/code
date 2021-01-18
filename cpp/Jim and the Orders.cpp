#include <bits/stdc++.h>
using namespace std;

bool sortFunction(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > order;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        order.emplace_back(i, x + y);
    }
    sort(order.begin(), order.end(), sortFunction);
    for (auto i : order) {
        cout << i.first << " ";
    }
    return 0;
}

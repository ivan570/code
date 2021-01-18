#include <bits/stdc++.h>
using namespace std;


void printSet(set<auto> arr) {
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

void getOutput(int n, int a, int b){

    set<int> stones;

    for (int i = 0; i < n; ++i) {
        int ans = a * i + b * (n - i - 1);
        stones.insert(ans);
    }

    printSet(stones);
}

int main() {

    int t;
    cin >> t;
    for (int t_time = 0; t_time < t; ++t_time) {
        int n, a, b;
        cin >> n >> a >> b;

        getOutput(n, a, b);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int commonChild(string one, string two) {
    int n = one.size();
    vector<vector<int> > common(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                common[i][j] = 0;
                continue;
            }
            if (one[i - 1] == two[j - 1]) {
                common[i][j] = common[i - 1][j - 1] + 1;
                continue;
            }
            common[i][j] = max(common[i - 1][j], common[i][j - 1]);

        }
    }
    return common[n][n];
}

int main() {
    string one, two;
    cin >> one >> two;
    cout << commonChild(one, two);
    return 0;
}

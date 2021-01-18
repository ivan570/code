#include <bits/stdc++.h>
using namespace std;

int gemstones(vector<string> arr) {
    vector<vector<int>> ch(arr.size(), vector<int>(26, 0));

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j){
            ch[i][arr[i][j] - 'a']++;
        }
    }

    for (auto i : ch){
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        int f = 1;
        for (int j = 0; j < arr.size(); ++j) {
            if (ch[j][i] == 0){
                f = 0;
                break;
            }
        }
        if (f) {
            ans++;
        }
    }
    return ans;
}

int main() {

    int n;
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = gemstones(arr);
    cout << result << endl;
    return 0;
}

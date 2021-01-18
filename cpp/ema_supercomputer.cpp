#include <bits/stdc++.h>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<string>> arr;
    for (int i = 0; i < row; ++i) {
        vector<string> temp;
        for (int j = 0; j < col; ++j) {
            char t;
            cin >> t;
            if (t == 'G')
                temp.push_back("0");
            else
                temp.push_back("-1");

        }
        arr.push_back(temp);
    }

    vector<vector<string>> temp = arr;
    int ans = 1;
    for (int _ = 0 ; _ < 2; ++_) {
        int max = 0, x = -1, y = -1;
        arr = temp;
        for (int i = 1; i < row - 1; ++i) {
            for (int j = 1; j < col - 1; ++j) {
                if (arr[i][j] == "0") {
                    int l = 1;
                    while (1) {
                        if (i - l < 0 || j - l < 0 || i + l >= row || l + j >= col)
                            break;
                        if (arr[i - l][j] == "-1" || arr[i + l][j] == "-1" || arr[i][j - l] == "-1" || arr[i][j + l] == "-1")
                            break;
                        l += 1;
                    }
                    arr[i][j] = to_string(l - 1);
                    l--;
                    if (l > max) {
                        max = l;
                        x = i;
                        y = j;
                    }
                }
            }
        }
        for (int i = 1; i <= max; ++i) {
            if (x - i < 0)
                continue;
            temp[x - i][y] = "-1";
            if (x + i >= row)
                continue;
            temp[x + i][y] = "-1";
            if (y - i < 0)
                continue;
            temp[x][y - i] = "-1";
            if (y + i >= col)
                continue;
            temp[x][y + i] = "-1";
        }
        ans = ans * ((max * 4) + 1);
    }

    cout << ans;

    return 0;
}

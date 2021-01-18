#include <bits/stdc++.h>
using namespace std;

int main() {

    int limit;
    cin >> limit;
    string ans[11] = { "" };
    for (int i = 0; i < limit; ++i) {
        int x;
        string y;
        cin >> x >> y;
        if (i < limit / 2)
            ans[x] += "- ";
        else
            ans[x] += y + " ";
    }

    for (string i : ans)
        cout << i;
    return 0;
}

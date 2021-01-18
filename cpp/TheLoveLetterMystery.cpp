#include <bits/stdc++.h>
using namespace std;

int theLoveLetterMystery(string str) {

    int ans = 0;
    int s = 0, e = str.size() - 1;
    while (s <= e) {
        ans += abs(str[s] - str[e]);
        s++;
        e--;
    }
    return ans;
}

int main()
{
    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {

        string s;
        cin >> s;
        cout << theLoveLetterMystery(s) << endl;
    }

    return 0;
}

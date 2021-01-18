#include <bits/stdc++.h>
using namespace std;

string funnyString(string s) {
    vector<int> n;
    for (int i = 0; i < s.size() - 1; ++i) {
        n.push_back(abs(s[i] - s[i + 1]));
    }
    reverse(s.begin(), s.end());
    vector<int> r;
    for (int i = 0; i < s.size() - 1; ++i) {
        r.push_back(abs(s[i] - s[i + 1]));
    }
    for (int i = 0; i < n.size(); ++i) {
        if (n[i] != r[i])
            return "Not Funny";
    }
    return "Funny";
}

int main()
{
    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);
        string result = funnyString(s);
        cout << result << "\n";
    }

    return 0;
}

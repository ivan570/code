#include <bits/stdc++.h>
using namespace std;

string getOutput(string s) {
    set<char> set_s;
    for (auto i : s) {
        set_s.insert(i);
    }
    for (auto i : set_s) {
        if (i != '_' && count(s.begin(), s.end(), i) == 1)
            return "NO";
    }
    if (count(s.begin(), s.end(), '_') == 0) {
        for (int i = 1; i < s.length() - 1; ++i) {
            int left = i - 1, right = i + 1;

            if (s[left] != s[i] && s[right] != s[i])
                return "NO";
        }
    }
    return "YES";
}

int main() {

    int g;
    cin >> g;

    for(int _ = 0; _ < g; ++_) {
        int x;
        cin >> x;
        string s;
        cin >> s;

        cout << getOutput(s) << endl;

    }
    return 0;
}

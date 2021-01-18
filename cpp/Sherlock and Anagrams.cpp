//this is my own logic

#include <bits/stdc++.h>
using namespace std;

bool is_anagram(string one, string two) {
    if (one.size() != two.size())
        return false;
    int one_alph[26] = {0};
    int two_alph[26] = {0};
    for (int i = 0; i < one.size(); ++i) {
        one_alph[one[i] - 'a'] += 1;
        two_alph[two[i] - 'a'] += 1;
    }

    for (int i = 0; i < 26; ++i) {
        if (one_alph[i] != two_alph[i])
            return false;
    }
    return true;
}

int main() {
    int q;
    cin >> q;
    for (int Q = 0; Q < q; ++Q) {
        string s;
        cin >> s;
        int count = 0;
        int length = s.size();
        for (int l = 1; l < length; ++l) {
            for (int i = 0; i < length - l; ++i) {
                string istr = s.substr(i, l);
                for (int j = i + 1; j <= length - l; ++j) {
                    string jstr = s.substr(j, l);
                    if (is_anagram(istr, jstr))
                        count ++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int makeAnagram(string one, string two) {

    vector<int> onearr(26, 0), twoarr(26, 0);
    for (auto i : one) {
        onearr[i - 'a']++;
    }

    for (auto i : two) {
        twoarr[i - 'a']++;
    }
    int maxLength = 0;
    for (int i = 0; i < 26; i++) {
        maxLength += min(onearr[i], twoarr[i]);
    }
    int ans = one.size() - maxLength;
    ans += two.size() - maxLength;

    return ans;
}

int main() {
    string one, two;
    cin >> one >> two;
    cout << makeAnagram(one, two) << endl;
    return 0;
}

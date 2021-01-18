#include <bits/stdc++.h>
#include <locale>
using namespace std;

string makeLower(string str) {
    string newStr = "";
    locale loc;
    for (int i = 0; i < str.size(); ++i)
        newStr += tolower(str[i], loc);
    return newStr;
}

int pangrams(string str) {
    int alph[26] = {0};
    str = makeLower(str);
    for (auto i : str) {
        alph[i - 'a']++;
    }
    for (auto i : alph) {
        if (i == 0)
            return 0;
    }
    return 1;
}

int main() {
    string str;
    getline(cin, str);
    if (pangrams(str))
        cout << "pangram" << endl;
    else
        cout << "not pangrams" << endl;
}

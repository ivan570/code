#include <bits/stdc++.h>
using namespace std;

int marsExploration(string s) {

    int i = 0;
    string sos = "SOS";
    int ans = 0;
    while(i < s.size() - 2) {
        string temp = s.substr(i,3);
        i += 3;
        if (temp != sos) {
            if (temp[0] != sos[0])
                ans++;
            if (temp[1] != sos[1])
                ans++;
            if (temp[2] != sos[2])
                ans++;
        }
    }
    return ans;
}

int main() {

    string s;
    getline(cin, s);
    cout << marsExploration(s) << endl;
    return 0;
}

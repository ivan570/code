#include <bits/stdc++.h>
using namespace std;

long substrCount(string str) {
    long ans = 0;
    vector<pair<char, int> > vec;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        int c = 1, j;
        for (j = i + 1; j < n; ++j) {
            if (str[i] != str[j])
                break;
            c++;
        }
        pair<char, int> temp = make_pair(str[i], c);
        i = j - 1;
        vec.push_back(temp);
    }

   for (pair<char, int> temp : vec) {
        cout << temp.first << " " << temp.second << endl;
    }

    for (pair<char, int> temp : vec) {
        ans += (temp.second * (temp.second + 1))/2;
    }

    for (int i = 1; i < vec.size() - 1; ++i) {
        if (vec[i].second == 1) {
            int left = vec[i - 1].first, l_c = vec[i - 1].second;
            int right = vec[i + 1].first, r_c = vec[i + 1].second;
            if (left == right) {
                ans += min(l_c, r_c);
            }
        }
    }

    return ans;
}

int main() {
    int x;
    string temp;
    cin >> x >> temp;
    cout << substrCount(temp) << endl;
    return 0;
}

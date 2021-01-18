#include <bits/stdc++.h>
using namespace std;

int number[27] = {0};

void weightedUniformStrings(string s, vector<int> queries){

    for (auto i : queries) {
        int c = 1;
        int f = 0;
        while (c <= 26) {
            int d = i / c;
            int r = i % c;
            if (r == 0 && d <= number[c]) {
                f = 1;
                break;
            }
            c++;
        }
        if (f)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

int main() {
    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        queries[i] = queries_item;
    }

    for (int i = 0; i < s.size(); ++i) {
        int c = 1;
        int j;
        for (j = i + 1; j < s.size(); ++j) {
            if (s[i] != s[j])
                break;
            c++;
        }
        int ch = (int)s[i];
        if (c > number[ch - 'a' + 1])
            number[ch - 'a' + 1] = c;
        i = j - 1;
    }


    weightedUniformStrings(s, queries);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        if (next_permutation(temp.begin(), temp.end()))
            cout << temp << endl;
        else
            cout << "no answer" << endl;
    }
    return 0;
}

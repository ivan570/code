#include <bits/stdc++.h>
using namespace std;

long int

int main()  {
    int q;
    cin >> q;
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        cin >> s;
        cout << separateNumbers(s) << endl;
    }
    return 0;
}

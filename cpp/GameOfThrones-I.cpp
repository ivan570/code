#include <bits/stdc++.h>
using namespace std;

string gameOfThrones(string s) {
    int arr[26] = {0};
    for (char i : s) {
        arr[i - 'a']++;
    }
    int f = 0;

    for (int i : arr) {
        if (i % 2 != 0)
            f++;
    }
    if (f > 1)
        return "NO";

    return "YES";
}

int main()
{
    string s;
    cin >> s;
    cout << gameOfThrones(s);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int anagram(string str)
{
    if (str.length() % 2 == 0)
    {
        int n = str.length();
        n /= 2;
        string first = str.substr(0, n);
        string second = str.substr(n, n);
        int f[26] = {0};
        int s[26] = {0};
        for (int i = 0; i < n; ++i)
        {
            f[first[i] - 'a']++;
            s[second[i] - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i)
        {
            ans += abs(f[i] - s[i]);
        }
        return ans / 2;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        cout << anagram(s) << endl;
    }
    return 0;
}
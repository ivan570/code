#include <bits/stdc++.h>
using namespace std;

int palindromeIndex(string s)
{
    int start = 0;
    int end = s.length() - 1;
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            int t_s = start, t_e = end;
            if (s[start] == s[end - 1])
            {
                start++;
                end--;
                end--;
                while (start <= end)
                {
                    if (s[start] != s[end])
                        return t_s;
                    start++;
                    end--;
                }
                return t_e;
            }
            if (s[start + 1] == s[end])
            {
                start += 2;
                end--;
                while (start <= end)
                {
                    if (s[start] != s[end])
                        return t_e;
                    start++;
                    end--;
                }
                return t_s;
            }
            return t_s;
        }
        start++;
        end--;
    }
    return -1;
}

int main()
{
    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        cin >> s;
        cout << palindromeIndex(s) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool ispali(string str, int i, int j)
{
    while (i <= j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int recur(string str, int i, int j)
{
    int ans = INT_MAX;
    if (i >= j || ispali(str, i, j))
        return 0;
    else
    {
        for (int k = i; k < j; ++k)
        {
            int temp = recur(str, i, k) + recur(str, k + 1, j) + 1;
            ans = min(temp, ans);
        }
    }
    return ans;
}

int memo(string str, int i, int j)
{
    static vector<vector<int>> ay(j + 1, vector<int>(j + 1, -1));
    int ans = INT_MAX;

    if (ay[i][j] != -1)
        return ay[i][j];

    if (i >= j || ispali(str, i, j))
        return ay[i][j] = 0;

    int t = INT_MAX;
    for (int k = i; k < j; ++k)
    {
        int temp = memo(str, i, k) + memo(str, k + 1, j) + 1;
        t = min(temp, t);
    }
    ay[i][j] = t;
    ans = min(t, ans);
    return ans;
}

int main()
{
    string str = "ivan vaghani ivan vaghani ivan vaghani ivan vaghani";
    // cout << recur(str, 0, str.length() - 1) << endl;
    cout << memo(str, 0, str.length() - 1) << endl;
    return 0;
}

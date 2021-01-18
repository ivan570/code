#include <bits/stdc++.h>
using namespace std;

int recursive(string one, string two, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    else if (one[n - 1] == two[m - 1])
        return 1 + recursive(one, two, n - 1, m - 1);
    else
        return max(recursive(one, two, n - 1, m), recursive(one, two, n, m - 1));
}

int memoization(string one, string two, int n, int m)
{
    static vector<vector<int>> ans(n + 1, vector<int>(m + 1, -1));
    if (n == 0 || m == 0)
        return 0;

    else if (ans[n][m] != -1)
        return ans[n][m];

    else if (one[n - 1] == two[m - 1])
        return ans[n][m] = 1 + recursive(one, two, n - 1, m - 1);
    else
        return ans[n][m] = max(recursive(one, two, n - 1, m), recursive(one, two, n, m - 1));
}

int dynamic(string one, string two)
{
    vector<vector<int>> ans(one.size() + 1, vector<int>(two.size() + 1));

    for (int i = 0; i <= one.size(); ++i)
    {
        for (int j = 0; j <= two.size(); ++j)
        {
            if (i == 0 || j == 0)
                ans[i][j] = 0;

            else if (one[i - 1] == two[j - 1])
                ans[i][j] = 1 + ans[i - 1][j - 1];

            else
                ans[i][j] = max(ans[i][j - 1], ans[i - 1][j]);
        }
    }
    return ans[one.size()][two.size()];
}

int main()
{
    string one = "ivankshu", two = "vaghani";
    int ol = one.size(), tl = two.size();

    cout << recursive(one, two, ol, tl) << endl;
    cout << memoization(one, two, ol, tl) << endl;
    cout << dynamic(one, two) << endl;

    return 0;
}
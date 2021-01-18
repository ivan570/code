#include <bits/stdc++.h>
using namespace std;

int dynamic(string one, string two)
{
    vector<vector<int>> ans(one.size() + 1, vector<int>(two.size() + 1));
    int m = -1;
    for (int i = 0; i <= one.size(); ++i)
    {
        for (int j = 0; j <= two.size(); ++j)
        {
            if (i == 0 || j == 0)
                ans[i][j] = 0;

            else if (one[i - 1] == two[j - 1])
            {
                ans[i][j] = 1 + ans[i - 1][j - 1];
                if (ans[i][j] > m)
                    m = ans[i][j];
            }

            else
                ans[i][j] = 0;
        }
    }
    return m;
}

int main()
{
    string one = "123025", two = "123as5";
    int ol = one.size(), tl = two.size();

    cout << dynamic(one, two) << endl;

    return 0;
}
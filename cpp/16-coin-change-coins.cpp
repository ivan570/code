// minium coins req. to give given number

#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int sum)
{
    vector<vector<int>> ans(sum + 1, vector<int>(coins.size() + 1));
    for (int i = 0; i <= sum; ++i)
    {
        for (int j = 0; j <= coins.size(); ++j)
        {
            if (j == 0)
                ans[i][j] = INT_MAX / 2;
            else if (i == 0 && j != 0)
                ans[i][j] = 0;
            else if (j == 1)
                if (i % coins[0] == 0)
                    ans[i][j] = i / coins[0];
                else
                    ans[i][j] = INT_MAX / 2;
            else if (coins[j - 1] <= i)
                ans[i][j] = min(ans[i][j - 1], 1 + ans[i - coins[j - 1]][j]);
            else
                ans[i][j] = ans[i][j - 1];
        }
    }
    return ans[sum][coins.size()];
}

int main()
{

    vector<int> coins = {25, 10, 5};
    int sum = 30;
    cout << coinChange(coins, sum) << endl;
    return 0;
}

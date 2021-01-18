// maximum number of ways that can form given number with given list of coins

#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int sum)
{
    vector<vector<int>> ans(sum + 1, vector<int>(coins.size()));
    for (int i = 0; i <= sum; ++i)
    {
        for (int j = 0; j <= coins.size(); ++j)
        {
            if (j == 0 && i != 0)
                ans[i][j] = 0;
            else if (i == 0)
                ans[i][j] = 1;
            else if (coins[j - 1] <= i)
                ans[i][j] = ans[i][j - 1] + ans[i - coins[j - 1]][j];
            else
                ans[i][j] = ans[i][j - 1];
        }
    }
    return ans[sum][coins.size()];
}

int main()
{
    vector<int> coins = {2, 3, 5, 10};
    int sum = 15;
    cout << coinChange(coins, sum) << endl;
    return 0;
}
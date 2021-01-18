#include <bits/stdc++.h>
using namespace std;

int UnboundedKnapsack(vector<int> profit, vector<int> weight, int cap)
{
    vector<vector<int>> ans(cap + 1, vector<int>(weight.size() + 1));

    for (int i = 0; i <= cap; ++i)
    {
        for (int j = 0; j <= weight.size(); ++j)
        {
            if (i == 0 || j == 0)
                ans[i][j] = 0;

            else if (weight[j - 1] <= i)
                ans[i][j] = max(ans[i][j - 1], ans[i - weight[j - 1]][j] + profit[j - 1]);

            else
                ans[i][j] = ans[i][j - 1];
        }
    }
    return ans[cap][profit.size()];
}

int main()
{
    vector<int> weight = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> profit = {1, 5, 8, 9, 10, 17, 17, 20};
    int capacity = 8;
    cout << UnboundedKnapsack(profit, weight, capacity) << endl;
    return 0;
}
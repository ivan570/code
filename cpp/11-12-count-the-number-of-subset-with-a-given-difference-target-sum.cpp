#include <bits/stdc++.h>
using namespace std;

int count(vector<int> arr, int value)
{
    vector<vector<int>> ans(value + 1, vector<int>(arr.size()));
    for (int i = 0; i <= value; ++i)
    {
        for (int j = 0; j <= arr.size(); ++j)
        {
            if (j == 0 && i != 0)
                ans[i][j] = 0;
            else if (i == 0)
                ans[i][j] = 1;
            else if (arr[j - 1] <= i)
                ans[i][j] = ans[i][j - 1] + ans[i - arr[j - 1]][j - 1];
            else
                ans[i][j] = ans[i][j - 1];
        }
    }
    return ans[value][arr.size()];
}

int getOutput(vector<int> arr, int total, int diff)
{
    int sum = (total + diff) / 2;
    return count(arr, sum);
}
int main()
{
    int k, total = 0, diff;
    cin >> k;
    vector<int> arr;
    for (int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        total += x;
    }

    cin >> diff;
    cout << getOutput(arr, total, diff) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x, type[3], cost[3];
		cin >> x >> type[0] >> type[1] >> type[2] >> cost[0] >> cost[1] >> cost[2];

		vector<vector<int> > dp(4, vector<int>(x + 1, INT_MAX));
		for (int i = 0; i <= 3; i++)
			dp[i][0] = 0;
		for (int i = 1; i <= 3; i++)
		{
			for (int j = 1; j <= x; j++)
			{
				if (type[i - 1] <= j)
					dp[i][j] = min(cost[i - 1] + dp[i][j - type[i - 1]], dp[i - 1][j]);
				else
					dp[i][j] = min(dp[i - 1][j], cost[i - 1]);
			}
		}
// print(dp);
		cout << dp[3][x] << endl;
	}
}
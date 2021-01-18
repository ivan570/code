#include <bits/stdc++.h>
using namespace std;

void printVector(vector<vector<int>> KS)
{
	for (int i = 0; i < KS.size(); ++i)
	{
		for (int j = 0; j < KS.at(i).size(); ++j)
		{
			cout << left << setw(8) << KS[i][j];
		}
		cout << endl;
	}
}

int knapSack(vector<int> weight, vector<int> profit, int size)
{
	int t = weight.size();
	vector<vector<int>> KS(t + 1, vector<int>(size + 1));
	for (int i = 0; i <= t; ++i)
	{
		for (int j = 0; j <= size; j++)
		{
			if (i == 0 || j == 0)
			{
				KS[i][j] = 0;
				continue;
			}
			if (j < weight[i])
			{
				KS[i][j] = KS[i - 1][j];
				continue;
			}
			KS[i][j] = max(KS[i - 1][j - weight[i]] + profit[i], KS[i - 1][j]);
		}
	}
	printVector(KS);
	return KS[t][size];
}

int main()
{
	vector<int> profit = {60, 100, 120};
	vector<int> weight = {1, 2, 3};
	int size = 5;
	cout << knapSack(weight, profit, size);
	cout << "ivan";
	return 0;
}

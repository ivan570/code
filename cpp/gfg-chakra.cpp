#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, count = 1;
	cin >> n;
	int arr[n][n] = { 0 };

	if (n % 2 == 1)
		arr[n / 2][n / 2] = n * n;

	for (int k = 0; k < n / 2; ++k)
	{
		int tj = n - k - 1;
		for (int j = k; j <= tj; ++j)
		{
			arr[k][j] = count++;
		}

		tj = n - k - 1;
		for (int j = k + 1; j < tj; ++j)
		{
			arr[j][n - 1 - k] = count++;
		}

		tj = n - k - 1;
		for (int j = tj; j >= k; --j)
		{
			arr[n - k - 1][j] = count++;
		}

		tj = n - 2 - k;
		for (int j = tj; j >= k + 1; --j)
		{
			arr[j][k] = count++;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	return 0;
}
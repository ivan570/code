#include <bits/stdc++.h>
using namespace std;

int maxele(int x, int y)
{
    if (x < y)
        return y;
    return x;
}
int minele(int x, int y)
{
    if (x < y)
        return x;
    return y;
}
int main()
{
    int t;
    cin >> t;
    for (int T = 0; T < t; ++T)
    {
        int n, max = -1, mIndex = -1;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
            if (arr[i] > max)
            {
                max = arr[i];
                mIndex = i;
            }
        }

        int total = 0;
        map<int, pair<int, int>> ans;
        for (int i = 1; i < n - 1; ++i)
        {
            if (i == 1)
            {
                ans[i] = make_pair(maxele(arr[0], arr[1]), -1);
            }

            else
            {
                int temp = ans[i - 1].first;
                ans[i] = make_pair(maxele(temp, arr[i]), -1);
            }
        }

        for (int i = n - 2; i >= 1; --i)
        {
            if (i == (n - 2))
                ans[i].second = maxele(arr[n - 1], arr[n - 2]);

            else
            {
                int temp = ans[i + 1].second;
                ans[i].second = maxele(temp, arr[i]);
            }
        }

        for (int i = 1; i < n - 1; ++i)
        {
            int cap = minele(ans[i].first, ans[i].second);
            int temp = cap - arr[i];
            if (temp > 0)
                total += temp;
        }
        cout << total << endl;
    }
    return 0;
}
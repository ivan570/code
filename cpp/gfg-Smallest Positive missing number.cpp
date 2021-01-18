#include <bits/stdc++.h>
using namespace std;

int missingNumber(int arr[], int n)
{

    int m = 1;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > m)
            m = arr[i];
    }

    vector<int> a(m + 1, 10);
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > 0)
        {
            a[arr[i]] = 11;
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        if (a[i] == 10)
            return i;
    }
    return m + 1;
}

int missingNumber(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << missingNumber(arr, n) << endl;
    }
    return 0;
}
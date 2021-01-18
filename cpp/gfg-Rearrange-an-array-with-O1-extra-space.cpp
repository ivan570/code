#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int T = 0; T < t; ++T)
    {
        int n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        for (int i : arr)
        {
            cout << arr[i] << " ";
        }
    }
    return 0;
}
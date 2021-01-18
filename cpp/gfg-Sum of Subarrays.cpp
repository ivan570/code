#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        map<int, int> m;
        int i = 0, j = n - 1;
        int past = n, cou = n - 2;

        while (i <= j)
        {
            if (i == 0)
            {
                m[arr[i]] = n;
                m[arr[j]] = n;
                past = n;
            }
            else if (i != j)
            {
                m[arr[i]] = past + cou;
                m[arr[j]] = past + cou;
                past = m[arr[i]];
                cou -= 2;
            }
            else
            {
                m[arr[i]] = past + cou;
            }
            i++;
            j--;
        }

        unsigned long long int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans += (arr[i] * m[arr[i]]);
        }
        cout << ans << endl;

        // for (auto i : m)
        // {
        // cout << i.first << " " << i.second << endl;
        // }
    }
    return 0;
}
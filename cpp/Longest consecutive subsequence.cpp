#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int e = 0; e < t; ++e) {
        int n;
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            s.insert(temp);
        }

        vector<int> arr;
        for (int i : s)
            arr.push_back(i);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int temp = i, l = 1;
            while (temp < n - 1 && arr[temp + 1] - arr[temp] == 1) {
                temp++;
                l++;
            }
            if (ans < l)
                ans = l;
            i = temp;
        }
        cout << ans << endl;
    }
    return 0;
}

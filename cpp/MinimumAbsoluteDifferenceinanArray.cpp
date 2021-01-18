#include <bits/stdc++.h>
using namespace std;

int minimumAbsoluteDifference(vector<int> arr) {

    sort(arr.begin(), arr.end());
    int m = INT_MAX;

    for (int i = 0; i < arr.size() - 1; ++i) {
        int d = abs(arr[i + 1] - arr[i]);
        if (d < m)
            m = d;
    }
    return m;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << minimumAbsoluteDifference(arr) << endl;
}

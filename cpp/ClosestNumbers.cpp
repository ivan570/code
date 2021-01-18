#include <bits/stdc++.h>
using namespace std;

void closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int m = 30000;
    for (int i = 0; i < arr.size(); ++i) {
        int j = i + 1;
        int d = arr[j] - arr[i];
        if (d < m) {
            m = d;
        }
    }
     for (int i = 0; i < arr.size(); ++i) {
        int j = i + 1;
        int d = arr[j] - arr[i];
        if (d == m) {
            cout << arr[i] << " " << arr[j] << " ";
        }
     }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    closestNumbers(arr);
    return 0;
}

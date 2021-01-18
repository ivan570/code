#include <bits/stdc++.h>
using namespace std;

void getOutput(vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end(), greater<int> ());
    long miles = 0;
    for (int i = 0; i < n; ++i) {
        miles += pow(2,i) * arr[i];
    }
    cout << miles << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    getOutput(arr);
    return 0;
}

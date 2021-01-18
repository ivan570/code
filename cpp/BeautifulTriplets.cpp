#include <bits/stdc++.h>
using namespace std;

int findFist(vector<int> arr, int d, int start) {
    int n = arr.size();
    if (start < 0 || d < 0 || start == n - 1) {
        return -1;
    }
    for (int i = start + 1; i < n; ++i) {
        int temp = arr[i] - arr[start];
        if (temp == d) {
            return i;
        }
    }
    return -1;
}

int beautifulTriplets(vector<int> arr, int d) {
    int answer = 0;
    for (int i = 0; i < arr.size() - 1; ++i) {
        int first = i;
        int second = findFist(arr, d, first);
        int third = findFist(arr, d, second);
        if (second >= 0 && third >= 0)
            answer++;
    }
    return answer;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int result = beautifulTriplets(arr, d);
    cout << result << endl;
}

#include <bits/stdc++.h>
using namespace std;

int findNext(vector<int> arr, int index) {
    for (int i = index + 1; i < arr.size(); ++i) {
        if (arr[i] == arr[index])
            return i;
    }
    return -1;
}

int minimumDistances(vector<int> arr) {
    int minDistances = 20000;
    for (int i = 0; i < arr.size(); ++i) {
        int next = findNext(arr, i);
        if (next != -1) {
            int temp = next - i;
            if (temp < minDistances) {
                minDistances = temp;
            }
        }
    }
    if (minDistances == 20000)
        return -1;
    return minDistances;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int result = minimumDistances(arr);
    cout << result;
    return 0;
}

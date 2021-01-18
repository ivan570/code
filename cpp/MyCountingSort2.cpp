#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> arr) {
    map<int, vector<int> > cou;
    for (int i : arr) {
        cou[i].push_back(i);
    }


//    final sorting

    for (auto i : cou) {
        for (int k : i.second) {
            cout << k << " ";
        }
    }
}

int main() {

    vector<int> arr(50);
    for (int i = 0; i < arr.size(); ++i) {
        cin >> arr[i];
    }

    countingSort(arr);
    return 0;
}

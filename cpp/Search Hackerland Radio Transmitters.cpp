#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vector<int> :: iterator it = lower_bound(arr.begin(), arr.end(), temp);
        arr.insert(it, temp);
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int limit = arr[i] + k;
        int mid = i;
        for (int j = i; j < n; ++j) {
            if (arr[j] > limit) {
                mid = j - 1;
                break;
            }
        }
        ans.push_back(arr[mid]);
        limit = arr[mid] + k;
        int last = mid;
//        cout << "i " << i << " mid " << mid << " limit " << limit;
        for (int j = mid; j < n; ++j) {
            if (arr[j] > limit) {
                last = j;
                break;
            }
        }
        if (last == mid)
            last = n;
//        cout << " last " << arr[last] << " " << last << endl;
        if (i != last)
            i = last - 1;
    }


//    for (int i : ans)
//        cout << i << " ";

    cout << ans.size() << endl;
    return 0;
}

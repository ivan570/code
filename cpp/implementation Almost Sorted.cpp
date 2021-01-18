#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long> arr;
    vector<long> sorted;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
        auto it = lower_bound(sorted.begin(), sorted.end(), temp);
        sorted.insert(it, temp);
    }

    int first = -1, last, count = 0;
    for (int i = 0; i < n; ++i) {
        if (sorted[i] != arr[i]) {
            if (first == -1)
                first = i;
            last = i;
            count += 1;
        }
    }

    if (count == 2) {
        cout << "yes" << endl << "swap " << first + 1 << " " << last + 1 << endl;
        return 0;
    }

    int flag = 1;
    int ans;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (i < first || i > last) {
            ans = arr[i];
        }
        else {
            ans = arr[last - j];
            j += 1;
            if (ans != sorted[i]) {
                cout << "no";
                flag = 0;
                break;

            }
        }
    }
    if (flag)
        cout << "yes\nreverse " << first + 1 << " " << last + 1;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool is_possible(vector<int> arr) {
    int len = arr.size();

    while (true) {
        int i = 0;
        for (i = 0; i < len; ++i) {
            if (i + 1 < len && arr[i] > arr[i + 1]) {
                if (i + 2 == len && arr[i - 1] < arr[i + 1]) {
                    cout << endl << i << " "<< arr[i - 1] << " " << arr[i + 1] << endl;
                    return false;
                }
//                swap element ABC to BCA
                if (i + 2 == len && arr[i - 1] >= arr[i + 1]) {
                    int one = arr[i - 1];
                    int two = arr[i];
                    int three = arr[i + 1];
                    arr[i - 1] = three;
                    arr[i] = one;
                    arr[i + 1] = two;
                }
                int one = arr[i];
                int two = arr[i + 1];
                int three = arr[i + 2];
                arr[i] = two;
                arr[i + 1] = three;
                arr[i + 2] = one;
                break;
            }
        }
        cout << endl;
        for (int i : arr) {
            cout << i << "\t";
        }
        if (i == len)
            return true;
    }
}

int main() {
    int test;
    cin >> test;
    for (int TEST = 0; TEST < test; ++TEST) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        if (is_possible(arr))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}


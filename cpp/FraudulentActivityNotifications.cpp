#include<iostream>
#include <vector>
using namespace std;

int getOutput(vector<int> arr, int d) {
    int ans = 0;
    int number[201] = {0};
    for (int i = 0; i < d; ++i)
        number[arr[i]] += 1;
    for (int i = d; i < arr.size(); ++i) {
        int acc = 0, dub, k;
        for (k = 0; k < 201; ++k) {
            acc += number[k];
            if (acc * 2 >= d)
                break;
        }
        if (acc * 2 > d || d % 2 == 1)
            dub = 2 * k;
        else {
            dub = k;
            for (int j = k + 1; j < 201; ++j)
                if (number[j]) {
                    dub += j;
                    break;
                }
        }
        if (arr[i] >= dub)
            ans += 1;
        number[arr[i - d]] -= 1;
        number[arr[i]] += 1;
    }
    return ans;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << getOutput(arr, d) << endl;
    return 0;
}

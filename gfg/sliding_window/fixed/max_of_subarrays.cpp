#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> max_of_subarrays(int *arr, int n, int k) {
        deque<int> dq;
        vector<int> ret(n - k + 1);
        int index = 0;
        int i = 0, j = 0;

        while (j < n) {
            int cur = arr[j];
            while (!dq.empty() && arr[dq.back()] <= cur)
                dq.pop_back();

            dq.push_back(j);
            if (j - i + 1 < k) {
                j++;
            } else {
                ret[index++] = arr[dq.front()];

                while (!dq.empty() && dq.front() <= i)
                    dq.pop_front();

                i++;
                j++;
            }
        }

        return ret;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

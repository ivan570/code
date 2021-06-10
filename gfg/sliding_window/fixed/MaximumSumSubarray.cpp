#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int maximumSumSubarray(int k, vector<int> &arr, int n) {
        int ret = 0;
        int sum_t = 0;
        int i = 0, j = 0;
        while (j < n) {
            sum_t += arr[j];
            if (j - i + 1 < k)
                j++;
            else {
                ret = max(ret, sum_t);
                sum_t -= arr[i];
                i++;
                j++;
            }
        }
        return ret;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> Arr;
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K, Arr, N) << endl;
    }
    return 0;
}  // } Driver Code Ends
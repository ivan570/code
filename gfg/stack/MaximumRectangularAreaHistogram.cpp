#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long getMaxArea(long long arr[], int n) {
        long long ans = 0;
        stack<int> st;

        int i = 0;
        while (i < n) {
            if (st.empty() || arr[st.top()] <= arr[i])
                st.push(i++);
            else {
                int top = st.top();
                st.pop();

                ans = max(ans, arr[top] * (st.empty() ? i : (i - st.top() - 1)));
            }
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();

            ans = max(ans, arr[top] * (st.empty() ? i : (i - st.top() - 1)));
        }

        return ans;
    }
};

int main() {
    long long t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}

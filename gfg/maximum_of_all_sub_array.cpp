#include <bits/stdc++.h>
using namespace std;

class Solution {
    static void printDeque(deque<int> de) {
        cout << "printing deque ==> ";
        while (!de.empty()) {
            cout << de.front() << " ";
            de.pop_front();
        }
        cout <<"\n";
    }
public:
    static vector<int> get_max_of_subarray(vector<int> arr, int k) {
        int n = arr.size();
        int ret_index = 0;
        vector<int> ret(n - k + 1);

        deque<int> dq;
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && arr[i] > arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }

        printDeque(dq);

        for (int i = k; i < n; ++i) {
            ret[ret_index++] = arr[dq.front()];

            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            while (!dq.empty() && arr[i] > arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);

        }

        ret[ret_index] = arr[dq.front()];

        return ret;
    }
};

int main() {

    vector<int> ret = Solution::get_max_of_subarray(vector<int> {8,5,10,7,9,4,15,12,90,13}, 4);

    for (int &i : ret) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
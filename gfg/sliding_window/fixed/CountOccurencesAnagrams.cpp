#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool match(const vector<int> &org, const vector<int> &pt) {
        if (org.size() != pt.size())
            return false;
        for (int i = 0; i < pt.size(); ++i) {
            if (org[i] != pt[i])
                return false;
        }
        return true;
    }

   public:
    int search(string pt, string str) {
        int ret = 0;
        int n = str.size();
        vector<int> org(26);
        int k = pt.size();
        for (char ch : pt) {
            org[ch - 'a']++;
        }
        vector<int> cur(26);

        int i = 0, j = 0;
        while (j < n) {
            cur[str[j] - 'a']++;
            if (j - i + 1 < k) {
                j++;
            } else {
                if (match(org, cur)) {
                    ret++;
                }
                cur[str[i] - 'a']--;
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
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
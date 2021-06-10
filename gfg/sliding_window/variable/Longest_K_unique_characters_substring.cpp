#include <bits/stdc++.h>
using namespace std;

class Solution {
    static int getUni(const vector<int> &char_count) {
        int ret = 0;
        for (const int &i : char_count) {
            if (i > 0)
                ret++;
        }
        return ret;
    }

   public:
    static int longestKSubstr(string str, int k) {
        int ret = -1;
        int i = 0, j = 0;
        int n = str.size();

        vector<int> char_count(26);

        while (j < n) {
            char_count[str[j] - 'a']++;
            int con = getUni(char_count);
            if (con < k) {
                j++;
            } else if (con == k) {
                ret = max(ret, j - i + 1);
                j++;
            } else {
                char_count[str[i] - 'a']--;
                i++;
                j++;
            }
        }
        return ret;
    }
};

int main() {
    system("cls");
    cout << Solution::longestKSubstr("aabacbebebe", 3);
    return 0;
}

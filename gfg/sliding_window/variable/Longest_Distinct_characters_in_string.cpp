#include <bits/stdc++.h>
using namespace std;

int longestSubstrDitinctChars(string S);
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        cout << longestSubstrDitinctChars(S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

bool isAllDistinct(const vector<int> &arr) {
    for (const int &i : arr) {
        if (i == 1 || i == 0)
            continue;
        else
            return false;
    }
    return true;
}

int longestSubstrDitinctChars(string str) {
    int ret = 0;
    vector<int> char_count(26);

    int i = 0, j = 0;
    int n = str.size();

    while (j < n) {
        char_count[str[j] - 'a']++;
        bool condition = isAllDistinct(char_count);
        if (condition) {
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

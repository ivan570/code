// Smallest window in a string containing all the characters of another string
#include <bits/stdc++.h>
using namespace std;

#define CHARs 256

class Solution {
   public:
    static string smallestWindow(string str, string p) {
        int pHash[CHARs] = {0};
        int sHash[CHARs] = {0};

        for (char &ch : p) pHash[ch]++;
        int start_index = -1;
        int start = 0;
        int size = INT_MAX;

        int psize = p.size();
        int n = str.size();

        int count = 0;

        for (int j = 0; j < n; ++j) {
            sHash[str[j]]++;

            if (sHash[str[j]] <= pHash[str[j]])
                count++;

            if (count == psize) {
                while (pHash[str[start]] == 0 || sHash[str[start]] > pHash[str[start]]) {
                    if (sHash[str[start]] > pHash[str[start]])
                        sHash[str[start]]--;
                    start++;
                }

                int temp_len = j - start + 1;
                if (temp_len < size) {
                    size = temp_len;
                    start_index = start;
                }
            }
        }

        if (start_index == -1)
            return "-1";
        else
            return str.substr(start_index, size);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
}

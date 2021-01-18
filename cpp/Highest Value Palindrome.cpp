#include <bits/stdc++.h>
using namespace std;

bool is_pali(string str) {
    int i = 0, j = str.size() - 1;
    while (i < j) {
        if (str[i] != str[j])
            return false;
        i += 1;
        j -= 1;
    }
    return true;
}

int main() {
    int n, k, temp;
    cin >> n >> k;
    string str;
    cin >> str;
    temp = k;
    int i = 0, j = n - 1;
    while (i < j && k > 0) {
        if (str[i] == '9' && str[j] == '9') {
        }
        else if (str[i] == '9' && k > 0) {
            str[j] = '9';
            k--;
        }
        else if (str[j] == '9' && k > 0) {
            str[i] = '9';
            k--;
        }
        else if (str[i] != '9' && str[j] != '9' && k > 0) {
            if (k >= 2) {
                str[i] = '9';
                str[j] = '9';

                k -= 2;
            }
            else if (str[i] != str[j]) {
                int m = max(str[i], str[j]);
                str[i] = char(m);
                str[j] = char(m);
                k -= 1;
            }
        }
        i++;
        j--;
    }
    if (i == j && k > 0) {
        str[i] = '9';
    }
    if (temp >= 1 && str.length() == 1)
        cout << "9";
    else if (temp >= 2 && str.length() == 2)
        cout << "99";
    else if (is_pali(str))
        cout << str;
    else
        cout << "-1";
    return 0;
}

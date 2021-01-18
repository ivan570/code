#include <bits/stdc++.h>
using namespace std;

string timeInWord(int h, int m) {
    vector<string> numbers = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine"
    };

    string ans = numbers[h];
    if (m == 0) {
        ans += " ";
        ans += "o' clock";
        return ans;
    }
    if (m == 30) {
        ans = "half past " + ans;
        return ans;
    }
    if (m == 15) {
        ans = "quarter past " + ans;
        return ans;
    }
    if (m == 45) {
        string temp = "quarter to ";
        h++;
        h = h%13;
        temp += numbers[h];
        return temp;
    }
    if (m < 30) {
        string m_str = numbers[m];
        m_str = m_str + " " + "minute";
        if (m != 1) {
            m_str += "s";
        }
        m_str += " ";
        m_str += "past ";
        m_str += numbers[h];
        return m_str;
    }
    if (m > 30) {
        int t_m = (60 - m);
        string m_str = numbers[t_m];
        m_str += " minute";
        if (t_m != 1) {
            m_str += "s";
        }
        m_str += " to ";
        h++;
        h = h % 13;
        m_str += numbers[h];
        return m_str;
    }
    return " ";
}

int main() {
    int h, m;
    cin >> h >> m;

    string result = timeInWord(h, m);
    cout << result;
    return 0;
}

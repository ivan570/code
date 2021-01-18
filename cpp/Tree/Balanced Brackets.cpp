#include <bits/stdc++.h>

using namespace std;

bool ans(string str) {
    stack<int> st;
    for (char i : str) {
        if (i == '(' || i == '[' || i == '{')
            st.push(i);
        if (i == ')') {
            if (st.empty() || st.top() != '(')
                return false;
            cout << i << endl;
            st.pop();
        }
        if (i == '}') {
            if (st.empty() || st.top() != '{')
                return false;
            cout << i << endl;
            st.pop();
        }
        if (i == ']') {
            if (st.empty() || st.top() != '[')
                return false;
            cout << i << endl;
            st.pop();
        }
    }
    return true;
}

void test_case() {
    string str;
    cin >> str;
    if (ans(str))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        test_case();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int getNext(vector<int> m_arr, int index){
    for (int i = 0; i < m_arr.size(); ++i) {
        if (m_arr[i] < index)
            continue;
        if (m_arr[i] == index)
            return 0;
        int temp = i - 1;
        if (temp >= 0)
            return min(index - m_arr[temp], m_arr[i] - index);
        return m_arr[i] - index;
    }
    return index - m_arr[m_arr.size() - 1];
}

int getOutput(int n, vector<int> m_arr) {
    vector<int> normal_arr = m_arr;
    sort(m_arr.begin(), m_arr.end());
    int m = 0;
    for (int i = 0; i < n; ++i){
        int temp = getNext(m_arr, i);
        if (temp > m) {
            m = temp;
        }
    }
    return m;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> m_arr(m, 0);

    for(int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        m_arr[i] = temp;
    }

    cout << getOutput(n, m_arr) << endl;

    return 0;
}

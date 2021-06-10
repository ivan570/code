#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> printFirstNegativeInteger(ll arr[], ll n, ll k) {
    vector<ll> ret(n - k + 1);
    int i = 0, j = 0;
    int index = 0;
    deque<int> dq;

    while (j < n) {
        if (arr[j] < 0)
            dq.push_back(j);
        if (j - i + 1 < k) {
            j++;
        } else {
            if (dq.empty())
                ret[index++] = 0;
            else
                ret[index++] = arr[dq.front()];
            while (!dq.empty() && dq.front() <= i)
                dq.pop_front();
            i++;
            j++;
        }
    }
    return ret;
}

int main() {
    ll a[] = {-8, 2, 3, -6, 10};

    for (int i : printFirstNegativeInteger(a, 5, 2))
        cout << i << " ";
}
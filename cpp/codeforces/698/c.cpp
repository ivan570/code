#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
inline void ten() {
#ifndef ONLINE_JUDGE
	freopen("D:\\Sub\\input.txt", "r", stdin);
	freopen("D:\\Sub\\output.txt", "w", stdout);
#endif
}
int main() {
	ten();
	ll t;
	cin >> t;
	while (t--) {
		ll n, i, temp = 0;
		cin >> n;
		ll a[2 * n];
		ll b[n];
		for (i = 0; i < 2 * n; i++) {
			cin >> a[i];
		}
		sort(a, a + 2 * n);
		set<ll> s;
		for (i = 1; i < 2 * n; i++) {
			if (a[i] % 2 == 1 || a[i] != a[i - 1]) {
				temp = 1;
				break;
			} else
				i++;
		}
		for (i = 0; i < 2 * n; i++) {
			s.insert(a[i]);
		}
		if (temp == 1 || s.size() != n)
			cout << "NO" << endl;
		else {
			ll j = (2 * n) - 1;
			for (i = 0; i < n; i++) {
				b[i] = a[j];
				j = j - 2;
			}
			j = n;
			for (i = 0; i < n; i++) {
				if ((b[i] - temp) % (2 * j) == 0 && b[i] > temp) {
					temp = temp + (b[i] - temp) / j;
					j--;

				} else {
					cout << "NO" << endl;
					break;
				}
			}
			if (i == n)
				cout << "YES" << endl;
		}

	}


}
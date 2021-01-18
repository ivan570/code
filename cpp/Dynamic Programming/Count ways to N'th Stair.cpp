#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int nthStair(int n) {
		std::vector<int> arr(n + 1, 0);
		arr[0] = 1;
		for (int i = 1; i <= n; ++i)
			arr[i] += arr[i - 1];
		for (int i = 2; i <= n; ++i)
			arr[i] += arr[i - 2];
		return arr[n];
	}
};

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans << "\n";
	}
	return 0;
}
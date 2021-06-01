// Maximise Function
#include <iostream>
#include <vector>
#include <algorithm>

inline void ten() {
#ifndef ONLINE_JUDGE
	freopen("D:\\Sub\\input.txt", "r", stdin);
	freopen("D:\\Sub\\output.txt", "w", stdout);
#endif
}

long long int max(long long int m, long long int b) {
	if (m > b)
		return m;
	return b;
}

void code() {
	int n;
	std::cin >> n;
	std::vector<long long int> array(n);
	for (long long int &value : array)
		std::cin >> value;
	std::sort(array.rbegin(), array.rend());
	long long int x = array[n - 1];
	long long int z = array[0];
	long long int ans = -1;
	if (n % 2) {
		long long int y = array[n / 2];
		ans = abs(x - y) + abs(y - z) + abs(z - x);
	}
	else {
		long long int y = array[n / 2];
		ans = abs(x - y) + abs(y - z) + abs(z - x);
		y = array[n / 2 + 1];
		ans = max(ans, abs(x - y) + abs(y - z) + abs(z - x));
	}
	std::cout << ans << "\n";
}

int main() {
	ten();
	long long int test;
	std::cin >> test;
	for (long long int i = 0; i < test; ++i)
		code();
	return 0;
}
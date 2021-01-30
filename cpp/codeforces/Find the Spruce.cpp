// https://codeforces.com/problemset/problem/1461/B

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

inline void ubuntu() {
#ifndef ONLINE_JUDGE
	freopen("/home/ivan/dev/input.txt", "r", stdin);
#endif
}

void code() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> array(n);

	long long int ans = 0;
	for (std::string &str : array) {
		std::cin >> str;
	}
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

	for (int x = n; x >= 0; --x) {
		for (int y = 0; y <= m; ++y) {
			if (x == n || y == m) {
				dp[x][y] = 0;
				continue;
			}

			if (array[x][y] == '.') {
				dp[x][y] = 0;
				continue;
			}
			int min_value;
			if (x + 1 > n || y - 1 < 0 || x + 1 < 0 || y + 1 > m)
				min_value = 0;
			else
				min_value = std::min(dp[x + 1][y - 1], std::min(dp[x + 1][y + 1], dp[x + 1][y]));
			ans++;
			ans += min_value;
			dp[x][y] = min_value + 1;
		}
	}

	for (const std::vector<int> &vec : dp) {
		for (const int & value : vec)
			std::cout << value << " ";
		std::cout << "\n";
	}

	std::cout << ans << std::endl;
}

int main() {
	ubuntu();
	int count;
	std::cin >> count;
	for (int i = 0; i < count; ++i) {
		code();
	}
	return 0;
}

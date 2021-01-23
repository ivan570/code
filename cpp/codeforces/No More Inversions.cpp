#include <iostream>
// https://codeforces.com/problemset/problem/1473/C

inline void run() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void code(int n, int k) {
	int m = n - k;
	for (int i = 1; i < k - m; ++i)
		std::cout << i << " ";
	// std::cout << " ";
	for (int i = k; i >= k - m; --i)
		std::cout << i << " ";
}

void code() {
	int n, k;
	std::cin >> n >> k;
	code(n, k);
	std::cout << "\n";
}

int main() {
	run();
	int count;
	std::cin >> count;
	for (int i = 0; i < count; ++i)
	{
		code();
	}
	return 0;
}
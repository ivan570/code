// https://codeforces.com/problemset/problem/977/C

#include <iostream>
#include <algorithm>
#include <vector>

inline void sublime_text_windows() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void code() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> array(n);
	for (int &value : array)
		std::cin >> value;
	std::sort(array.begin(), array.end());
	if (k == 0) {
		if (array[0] > 1)
			std::cout << 1;
		else
			std::cout << -1;

		return;
	}

	if (n <= k) {
		std::cout << array[n - 1] + 1;
		return;
	}
	int temp = array[k - 1] + 1;
	if (array[k] <= temp) {
		std::cout << -1;
		return;
	}
	else {
		std::cout << temp;
	}
}

int main() {
	sublime_text_windows();
	code();

	return 0;
}
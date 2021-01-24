// https://codeforces.com/problemset/problem/977/C
#include <iostream>
#include <vector>
#include <algorithm>

inline void ten() {
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
	int ans = -1;
	if (k == 0)
		ans = array[0] - 1;
	else
		ans = array[k - 1];
	int count = 0;
	for (int i : array) {
		if (i <= ans)
			count++;
		else
			break;
	}
	if (count != k || ans < 1 || ans > 1000 * 1000 * 1000)
		ans = -1;
	std::cout << ans << "\n";
}

int main() {
	ten();
	code();

	return 0;
}
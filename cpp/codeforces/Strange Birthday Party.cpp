// https://codeforces.com/problemset/problem/1470/A
// incomplete yet

#include <iostream>
#include <vector>

inline void sublime_text_windows() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void code() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> array(n);
	std::vector<int> c(m);
		
	for (int &value : array)
		std::cin >> value;

	for (int &value : c) 
		std::cin >> value;

	std::sort(array.rbegin(), array.rend());
	long long int ans = 0;
	for (int i = 0; i < n; ++i) {
		int ki = array[i];

	}
	std::cout << ans << "\n";
}

int main() {
	sublime_text_windows();
	int count;
	std::cin >> count;
	for (int i = 0; i < count; ++i)
		code();

	return 0;
}
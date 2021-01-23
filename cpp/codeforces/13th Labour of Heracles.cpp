// https://codeforces.com/problemset/problem/1466/D
#include <iostream>
#include <vector>
#include <algorithm>

inline void run() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void code() {
	int vertex, edge;
	std::cin >> vertex;

	edge = vertex - 1;
	std::vector<int> array(vertex), degree(vertex);
	long long int ans = 0;

	for (int &value : array) {
		std::cin >> value;
		ans += value;
	}

	for (int i = 0; i < edge; ++i) {
		int u, v;
		std::cin >> u >> v;
		degree[u - 1]++;
		degree[v - 1]++;
	}

	std::vector<int> to_sort;
	for (int i = 0; i < vertex; ++i) {
		for (int j = 0; j < degree[i] - 1; ++j)
			to_sort.push_back(array[i]);
	}

	std::sort(to_sort.rbegin(), to_sort.rend());

	for (int &value : to_sort) {
		std::cout << ans << " ";
		ans += value;
	}

	std::cout << ans << "\n";
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
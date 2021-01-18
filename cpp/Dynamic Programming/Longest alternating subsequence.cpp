// https://www.geeksforgeeks.org/longest-alternating-subsequence/
#include <iostream>
#include <vector>

void cases() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];
	std::vector<std::vector<int>> dyna(n, std::vector<int>(2, 1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j])
				dyna[i][0] = std::max(dyna[i][0], (dyna[j][1] + 1));
			else if (arr[i] < arr[j])
				dyna[i][1] = std::max(dyna[i][1], (dyna[j][0] + 1));
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = std::max(ans, std::max(dyna[i][0] , dyna[i][1]));
	std::cout << ans << "\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		cases();
	return 0;
}
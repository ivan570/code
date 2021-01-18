#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
int LCS(std::string one, std::string two) {
	std::vector<std::vector<int>> arr(one.size() + 1, std::vector<int>(two.size() + 1, 0));
	for (int i = 0; i <= one.length(); ++i) {
		for (int j = 0; j <= two.length(); ++j) {
			if (i == 0 || j == 0)
				arr[i][j] = 0;
			else if (one[i - 1] == two[j - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = std::max(arr[i][j - 1], arr[i - 1][j]);
		}
	}
	return arr[one.length()][two.length()];
}

void test_case() {
	std::string str;
	std::cin >> str;
	std::string ori = str;
	std::reverse(std::begin(str), std::end(str));
	std::cout << str.size() - LCS(ori, str) << std::endl;
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		test_case();
	return 0;
}
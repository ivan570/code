#include <iostream>
#include <vector>

class Solution {
public:
	static int lcs(const std::string &one, const std::string &two) {
		std::vector<std::vector<int>> dyna(one.size() + 1, std::vector<int>(two.size() + 1));
		for (int i = 0; i <= one.size(); ++i) {
			for (int j = 0; j <= two.size(); ++j) {
				if (i == 0 || j == 0)
					dyna[i][j] = 0;
				else if (one[i - 1] == two[j - 1])
					dyna[i][j] = dyna[i - 1][j - 1] + 1;
				else
					dyna[i][j] = std::max(dyna[i - 1][j], dyna[i][j - 1]);
			}
		}
		return dyna[one.length()][two.length()];
	}
	static int findMinCost(std::string X, std::string Y, int costX, int costY)
	{
		int l = lcs(X, Y);
		int x = (X.length() - l) * costX;
		int y = (Y.length() - l) * costY;
		return x + y;
	}
};

int main() {
	std::string one, two;
	std::cin >> one >> two;
	std::cout << Solution.findMinCost(one, two);
	return 0;
}
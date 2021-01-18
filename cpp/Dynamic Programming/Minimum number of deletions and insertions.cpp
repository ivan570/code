#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
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
	int minOperations(std::string one, std::string two) {
		return one.size() + two.size() - 2 * LCS(one, two);
	}
};

int main() {


	int t;
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;

		Solution ob;
		cout << ob.minOperations(s1, s2) << "\n";

	}
	return 0;
}

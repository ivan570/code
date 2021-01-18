#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

void printVector(vector<vector<auto> > KS) {
	for (int i = 0; i < KS.size(); ++i) {
		for (int j = 0; j < KS.at(i).size(); ++j) {
			cout << left << setw(8) << KS[i][j];
		}
		cout << endl;
	}
}

bool sum_set_posible(vector<int> f_set, int sum) {
	vector<vector<bool> > ans(f_set.size() + 1, vector<bool>(sum + 1));

	if (sum == 0)
		return true;

	for (int i = 0; i <= f_set.size(); ++i) {
		for (int j = 0; j <= sum; ++j) {
			if (j == 0) {
				ans[i][j] = true;
				continue;
			}
			if (i == 0) {
				ans[i][j] = false;
				continue;
			}
			if (j < f_set[i]) {
				ans[i][j] = ans[i - 1][j];
				continue;
			}
			ans[i][j] = max(ans[i - 1][j - f_set[i]] , ans[i - 1][j]);
		}
	}

	printVector(ans);

	return ans[f_set.size()][sum];
}

int main() {
	vector<int> f_set = { 6, 2, 3, 1 };
	int sum = 5;
	if (sum_set_posible(f_set, sum))
		cout << endl << "true";
	else
		cout << endl << "false";
}

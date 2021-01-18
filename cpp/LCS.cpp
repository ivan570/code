#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	string A;
	string B;
	getline(cin, A);
	getline(cin, B);

	int LSC[A.size() + 1][B.size() + 1] = {0};

	for (int i = 0; i <= A.size(); ++i) {
		for (int j = 0; j <= B.size(); ++j) {
			if ( i == 0 || j == 0) {
				LSC[i][j] = 0;
				continue;
			}
			if (A[i - 1] == B[j - 1]) {
				LSC[i][j] = LSC[i - 1][j - 1] + 1;
			}
			else {
				LSC[i][j] = max(LSC[i][j - 1], LSC[i - 1][j]);
			}
		}
	}

	for (int i = 1; i <= A.size(); ++i) {
		for (int j = 1; j <= B.size(); ++j) {
			cout << LSC[i][j] << " ";
		}
		cout << endl;
	}
	cout << LSC[A.size()][B.size()];
	return 0;
}
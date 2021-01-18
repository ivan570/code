#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<vector<auto> > KS) {
	for (int i = 1; i < KS.size(); ++i) {
		for (int j = i; j < KS.at(i).size(); ++j) {
			cout << left << setw(8) << KS[i][j];
		}
		cout << endl;
	}
}


void matrix_chain(vector<int> arr) {
	int n = arr.size() - 1;
	vector<vector<int> > matrix(n + 1, vector<int> (n + 1));
	for (int l = 1; l <= n; ++l) {
        matrix[l][l] = 0;
	}

	for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            matrix[i][j] = 30000;
            for (int k = i; k < j; k++) {
                int q = matrix[i][k] + matrix[k + 1][j] + arr[i-1]*arr[k]*arr[j];
                if (q < matrix[i][j]) {
                    matrix[i][j] = q;
                }
            }
        }
	}

	printVector(matrix);
}

int main() {
	vector<int> arr = { 1, 2, 3, 4 };
	matrix_chain(arr);
	return 0;
}

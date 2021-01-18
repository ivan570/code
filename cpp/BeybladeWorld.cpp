#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int max_win(vector<int> our, vector<int> your) {
	sort(our.begin(), our.end());
	sort(your.begin(), your.end());
	int n = our.size();
	for (int i = 0; i < n; ++i) {

	}
}

int main() {
	int n;
	cin >> n;
	vector<int> our;
	vector<int> your;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		our.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		your.push_back(temp);
	}
	cout << max_win(our, your);
	return 0;
}

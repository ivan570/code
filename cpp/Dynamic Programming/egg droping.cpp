#include <bits/stdc++.h>
using namespace std;

int eggDrop(int eggs, int floors) {
	static vector<vector<int>> store(eggs + 1, vector<int>(floors + 1, -1));
	if (eggs == 0)
		return 0;

	if (eggs == 1 || floors < 2)
		return floors;

	if (store[eggs][floors] != -1)
		return store[eggs][floors];

	int min_value = INT_MAX;

	for (int k = 1; k < floors; ++k) {
		int temp = max(eggDrop(eggs - 1, k - 1), eggDrop(eggs, floors - k));
		min_value = min(min_value, temp + 1);
	}

	return store[eggs][floors] = min_value;
}

int main() {

	cout << eggDrop(3, 5);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int getRound(double x) {
	return int(x) + 1;
}

void test_case() {
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> temp;
	int value = getRound(log10(n) / log10(2));
	cout << value - 1 << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) 
		test_case();
	return 0;
}
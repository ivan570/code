#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long int k;
	cin >> n;
	cin >> k;
	vector<long long int> arr;
	for(int i = 0; i < n; ++i) {
		long long temp;
		cin >> temp;
		arr.push_back(temp);
	}

	make_heap(arr.begin(), arr.end());

	sort_heap(arr.begin(), arr.end());

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (k >= arr[i]) {
			count++;
			k -= arr[i];
		}
	}

	cout << count;
	return 0;
}

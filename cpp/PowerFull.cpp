#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	vector<long int> req;
	vector<long int> ava;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		long int temp;
		cin >> temp;
 		req.push_back(temp);
	}

	for (int i = 0; i < n; ++i) {
		long int temp;
		cin >> temp;
 		ava.push_back(temp);
	}

	for (int i = 0; i < n; ++i) {
		ava.at(i) = ( ava.at(i) / req.at(i) );
	}

	long minValue = *min_element(ava.begin(), ava.end());

	cout << minValue << endl;

	return 0;
}

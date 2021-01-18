#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int test;
	cin >> test;
	for(int i = 0; i < test; i++){
		int n;
		cin >> n;
		vector<int> arr;
		for(int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
	}
}

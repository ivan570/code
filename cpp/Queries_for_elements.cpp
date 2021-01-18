#include <iostream>
using namespace std;
int main() {
	int n;
	cout << endl << "enter the n ";
	cin >> n;
	cout << "n % 6 " << n%6;
	int arr[n];
	cout << endl << "enter the arr ";
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	cout << endl << "enter the A, B ";
	int A, B;
	cin >> A >> B;
	cout << endl << "enter the subarray ";
	int p, q, c = 0;
	cin >> p >> q;

	cout << endl << "arr is";
	for(int i = p; i <= q; i++) {
		cout << " " << arr[i];
		if(arr[i] >= A && arr[i] <= B)
			c++;
	}
	cout << endl << "count " << c;
	return 0;
}

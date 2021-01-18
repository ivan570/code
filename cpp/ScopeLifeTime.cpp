#include <iostream>
using namespace std;

int *getArray() {
	static int arr[5];
	for (int i = 0; i < 5; ++i)
		arr[i] = i + 1;
	return arr;
}

int main()
{
	int *arr = getArray();
	for (int i = 0; i < 5; ++i)
		cout << arr[i] << " ";
	return 0;
}
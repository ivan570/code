#include <iostream>
using namespace std;

int main() {

	int arr[5];
	for (int i = 0; i < 5; ++i) 
		arr[i] = i;
	int *arr_ptr = arr;
	for (int i = 0; i < 5; ++i)
		cout << arr_ptr[i] << " ";
	return 0;
}
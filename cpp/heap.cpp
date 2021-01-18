#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void isHeap(vector<int> arr, int size) {
    int limit = size / 2;
    for (int i = 0; i < limit; ++i) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (arr[i] >= arr[left] && arr[i] >= arr[right]) {
            continue;
        }
        else {
            cout << "it is not heap. \nmax size which create heap. " << i << endl;
            return;
        }
    }
    cout << "this is heap" << endl;
}

void printHeap(vector<int> arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[n - 1] << endl;
}

vector<int> heapify(vector<int> arr, int size, int index) {
    int left = index*2 + 1;
    int right = index*2 + 2;
    int large = index;

    if (left < size && arr[left] > arr[index])
        large = left;

    if (right < size && arr[right] > arr[large])
        large = right;

    if (large != index) {
        swap(arr[large], arr[index]);
        arr = heapify(arr, size, large);
    }
    return arr;
}

vector<int> del(vector<int> arr, int size) {
	if (size >= 0) {
		int max = arr.at(0);
		arr.at(0) = arr.at(size - 1);
		arr.at(size - 1) = max;
		size--;
		arr = heapify(arr, size, 0);
	}
	return arr;
}

vector<int> create(vector<int> arr) {
    for (int i = arr.size() / 2 ; i >= 0 ; --i) {
        arr = heapify(arr, arr.size(), i);
    }
    return arr;
}

vector<int> heapSort(vector<int> arr) {
	for(int i = 0; i < arr.size(); i++ )
		arr = del(arr, arr.size() - i);

	return arr;
}

vector<int> increaseKey(vector<int> arr, int index, int value) {
	if (arr.at(index) < value) {
		arr.at(index) = value;
		while ((index - 1)/2 >= 0 && arr.at(index) > arr.at((index - 1)/2)) {
			swap(arr.at(index), arr.at((index - 1)/2));
			index = (index - 1)/2;
		}
	}
	return arr;
}

vector<int> decreaseKey(vector<int> arr, int index, int value) {
	if (arr.at(index) > value) {
		arr.at(index) = value;
		arr = heapify(arr, arr.size(), index);
	}
	return arr;
}

vector<int> insertHeap(vector<int> arr, int value) {
	arr.push_back(INT_MIN);
	arr = increaseKey(arr, arr.size() - 1, value);
	return arr;
}

int maxHeap(vector<int> arr) {
	if (arr.size() < 1)
		return INT_MIN;
	return arr.at(0);
}

int main() {
    vector<int> arr = { 8, 10, 12, 13, 14, 18, 19 };
    arr = create(arr);
    printHeap(arr, arr.size());
    arr = insertHeap(arr, 100);
    printHeap(arr, arr.size());
    return 0;
}

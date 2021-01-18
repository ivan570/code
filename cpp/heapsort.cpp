#include <iostream>
#include <vector>
using namespace std;

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
    arr = create(arr);
    for(int i = 0; i < arr.size(); i++ )
        arr = del(arr, arr.size() - i);

    return arr;
}


int main() {
    vector<int> arr = { 8, 10, 12, 13, 14, 18, 19 };
    arr = heapSort(arr);
    printHeap(arr, arr.size());
    return 0;
}
#include <iostream>
using namespace std;

void swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void ArrayPrint(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int Partition(int arr[], int p, int r) {
    int key = arr[r];
    int i = p - 1;
    int j = p;
    for (j; j < r; j++) {
        if (arr[j] < key) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}

void QuickSort(int arr[], int p, int r) {
    if( p > r)
        return;
    int mid = Partition(arr, p, r);
    QuickSort(arr, p, mid - 1);
    QuickSort(arr, mid + 1, r);
}

int main() {
    cout << "Quick sort" << endl;
    cout << "=================================================" << endl;
    int arr[] = { 13, 19, 5, 12, 8, 7, 7, 4, 21, 2, 6, 11, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, size - 1);
    ArrayPrint(arr, size);
    return 0;
}
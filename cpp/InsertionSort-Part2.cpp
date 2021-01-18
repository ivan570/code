#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

void insertionSort(vector<int> arr) {

    for (int i = 1; i < arr.size(); ++i) {
        int val = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > val) {
            f++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[++j] = val;
        printVector(arr);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    insertionSort(arr);
    return 0;
}

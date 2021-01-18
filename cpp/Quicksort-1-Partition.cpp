#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

void Partition(vector<int> arr)
{
    int p = arr[0];
    int n = arr.size();
    int i = n;
    int j = n - 1;
    while (j >= 0) {
        if (arr[j] > p) {
            i--;
            swap(arr[i], arr[j]);
        }
        j--;
    }
    swap(arr[--i], arr[0]);
    printVector(arr);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    Partition(arr);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> arr) {
    int number[100] = {0};
    for (int i : arr) {
        number[i]++;
    }
    for (int i : number) {
        cout << i << " ";
    }

}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    countingSort(arr);
    return 0;
}

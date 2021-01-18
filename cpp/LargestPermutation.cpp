#include <bits/stdc++.h>

using namespace std;

int round(float a) {
    float temp = a - int(a);
    if (temp >= 0.5)
        return a + 1;
    else
        return a;
}


vector<int> largestPermutation(vector<int> arr, int k) {

    int n = arr.size();
    int temp = round((float) n / 2.0);
    if (k >= temp) {
        cout << "ivan vaghani";
        sort(arr.begin(), arr.begin(), greater<int>());
        return arr;
    } else {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end(), greater<int>());

        int pointer = 0;
        for (int i = 0; i < k; ++i) {
            if (i >= temp)
                return sorted;

            else {
                int max = sorted[pointer];
                if (arr[i] != max) {
                    int f = find(arr.begin(), arr.end(), max) - arr.begin();
                    int temp = arr[f];
                    arr[f] = arr[i];
                    arr[i] = temp;
                } else {
                    k++;
                }
            }
            pointer += 1;
        }
        return arr;
    }

}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    vector<int> result = largestPermutation(vec, k);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}

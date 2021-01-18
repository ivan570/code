#include <bits/stdc++.h>
using namespace std;

void preToPost(int pre[], int in[], int size, int inS, int inE, int preS, int preE) {
    if (inS > inE)
        return;
    int temp_data = pre[preS];
    int index = -1;

    for (int i = inS; i <= inE; ++i) {
        if (in[i] == temp_data) {
            index = i;
            break;
        }
    }

    int leftInS = inS, leftInE = index - 1, rightInE = inE, rightInS = index + 1;
    int leftPreS = preS + 1, leftPreE = leftInE - leftInS + leftPreS, rightPreS = leftPreE + 1, rightPreE = preE;

    preToPost(pre, in, size, leftInS, leftInE, leftPreS, leftPreE);
    preToPost(pre, in, size, rightInS, rightInE, rightPreS, rightPreE);
    cout << pre[preS] << " ";
}

void test_case() {
    int n;
    cin >> n;
    int arr[n], in[n];
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        arr[i] = t;
        in[i] = t;
    }

    sort(arr, arr + n);

    preToPost(in, arr, n, 0, n - 1, 0, n - 1);
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        test_case();
    return 0;
}
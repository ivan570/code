#include <bits/stdc++.h>
using namespace std;

void printAllStringWithNBit(string str, int low, int high) {
    if (low == high) {
        cout << str << " ";
        return;
    }
    else {
        str[low] = '0';
        printAllStringWithNBit(str, low + 1, high);
        str[low] = '1';
        printAllStringWithNBit(str, low + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    string str = "";
    for (int i = 0; i < n; ++i)
        str += ' ';
    printAllStringWithNBit(str, 0, n);
    return 0;
}
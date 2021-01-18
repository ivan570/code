#include <bits/stdc++.h>
using namespace std;

int beautifulBinaryString(string b) {

    int ans = 0;
    string o = "010";
    int f = b.find(o);

    while (f >= 0) {
        ans++;
        int index = f;
        index += 2;
        b[index] = '2';
        f = b.find(o);
    }

    return ans;
}

int main() {

    int n;
    string b;
    cin >> n >> b;
    int result = beautifulBinaryString(b);
    cout << result << endl;
    return 0;
}

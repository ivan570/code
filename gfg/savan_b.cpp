#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int req = 4 - n % 4;
    if (req == 4)
        cout << "0";
    else {

        if (req == 1)
            cout << a;

        else if (req == 2)
            cout << min(a * 2, b);

        else if (req == 3)
            cout << min(min(a * 3, b + a), c);

    }
    cout << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

unsigned int pow(int x, int y, int p)
{
    unsigned int res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << pow(a, b, c) << endl;
    }
    return 0;
}
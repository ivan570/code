#include <bits/stdc++.h>
using namespace std;

void getOutput(int n, int k)
{
    int temp = k;

    if (k == 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << i << " ";
        }
        return;
    }
    else if ((n % (2 * k)) == 0)
    {

        for (int i = 1; i <= n; ++i)
        {
            cout << temp + i << " ";
            if (i % k == 0)
            {
                temp *= -1;
            }
        }
    }
    else
    {
        cout << "-1";
    }
}

int main()
{

    int t;
    cin >> t;
    for (int T = 0; T < t; ++T)
    {

        int n, k;
        cin >> n >> k;
        getOutput(n, k);
        cout << endl;
    }
    return 0;
}

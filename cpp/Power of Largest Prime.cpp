#include <bits/stdc++.h>
using namespace std;

bool isprime(long long int n)
{
    long long int s = sqrt(n);
    if (n == 2 || n == 3)
        return true;
    if (n < 2 || n % 2 == 0 || n % 3 == 0)
        return false;
    for (long long int i = 3; i <= s; ++i)
        if (n % i == 0)
            return false;
    return true;
}

bool largest(long long int n)
{
    long long int s = sqrt(n), large = 0, ans = -1;
    for (long long int i = 2; i <= s; ++i)
    {
        if (n % i == 0 && isprime(i))
            large = i;
        if (n % i == 0)
        {
            long long int k = n / i;
            if (isprime(k))
            {
                ans = k;
                break;
            }
        }
    }

    if (ans != -1)
        return n % (ans * ans) == 0;
    else if (large != 0)
        return n % (large * large) == 0;
    else
        return false;
}

int main()
{
    int test;
    cin >> test;
    for (int t = 0; t < test; ++t)
    {
        long long int n;
        cin >> n;
        if (largest(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

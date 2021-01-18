#include <bits/stdc++.h>
using namespace std;

void prime(int n)
{
    map<int, int> prime;
    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            prime[i]++;
            n /= i;
        }
    }
    if (n > 2)
        prime[n]++;
    for (auto i : prime)
    {
        cout << i.first << " " << i.second << " ";
    }
    cout << endl;
}

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; ++i)
    {
        int n;
        cin >> n;
        prime(n);
    }
    return 0;
}
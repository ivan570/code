#include <stdio.h>
unsigned long long int combinations(unsigned long long int n, unsigned long long int r)
{
    unsigned long long int itr;
    unsigned long long int numerator = 1, denominator = 1, result;
    for (itr = 1; itr <= r; itr++)
    {
        denominator = denominator * itr;
        numerator = numerator * (n - (itr - 1));
    }
    result = numerator / denominator;
    return result;
}
unsigned long long int calcgcd(unsigned long long int n1, unsigned long long int n2)
{
    unsigned long long int rem;
    while (1)
    {
        rem = n1 % n2;
        if (rem == 0)
            return n2;
        if (rem != 0)
        {
            n1 = n2;
            n2 = rem;
        }
    }
}
unsigned long long int mulInv(unsigned long long int a)
{
    unsigned long long int m = 1000000007, itr, b;
    for (itr = 1; itr < m; itr++)
    {
        if ((itr * m + 1) % a == 0)
        {
            b = (itr * m + 1) / a;
            break;
        }
    }
    return b;
}
int main()
{
    int t, itr;
    scanf("%d", &t);
    for (itr = 1; itr <= t; itr++)
    {
        unsigned long long int qu, l, c, u;
        unsigned long long int wc, wf, p, q, gcd, result;
        scanf("%llu %llu %llu", &qu, &l, &c);
        u = qu - l;
        wc = combinations(qu, c);
        wf = combinations(u, c);
        p = wc - wf;
        q = wc;
        gcd = calcgcd(p, q);
        if (gcd != 1)
        {
            p = p / gcd;
            q = q / gcd;
        }
        result = (p * mulInv(q)) % 1000000007;
        printf("%llu\n", result);
    }

    return 0;
}
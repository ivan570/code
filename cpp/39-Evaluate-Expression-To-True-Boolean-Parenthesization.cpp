#include <bits/stdc++.h>
#define true T
#define false F
using namespace std;

int _rec(string exp, int i, int j, bool bval)
{
    int ans = 0;
    if (i < j)
        return F;

    else if (i == j)
        return exp[i] == bval;

    for (int k = i + 1; k < j; ++k)
    {
        int ltrue = _rec(exp, i, k - 1, T);
        int lfalse = _rec(exp, i, k - 1, F);
        int rtrue = _rec(exp, k + 1, j, T);
        int rfalse = _rec(exp, k + 1, j, F);

        if (exp[k] == '&')
        {
            if (bval)
                ans += (ltrue * rtrue);

            else
                ans += (ltrue * rfalse) + (lfalse * rfalse) + (lfalse * rtrue);
        }
        else if (exp[k] == '|')
        {
            if (bval)
                ans += (lfalse * rtrue) + (ltrue * rtrue) + (ltrue * rfalse);
            else
                ans += (lfalse * lfalse);
        }
        else if (exp[k] == '^')
        {
            if (bval)
                ans += (lfalse * rtrue) + (ltrue * rfalse);

            else
                ans += (ltrue * rtrue) + (lfalse * rfalse);
        }
    }
    return ans;
}

int main()
{
    string exp = "&";
    cout << _rec(exp, 0, exp.length() - 1, T);
    return 0;
}
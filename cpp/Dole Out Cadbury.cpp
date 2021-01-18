#include <stdlib.h>
#include <stdio.h>

int candy(int x, int y)
{
    int ret = 0;
    while (x != y)
    {
        if (x > y)
            x -= y;
        else
            y -= x;
        ret += 1;
    }
    return ret + 1;
}

int main()
{
    int minl, maxl, minw, maxw;
    int ans = 0;
    scanf("%d%d%d%d", &minl, &maxl, &minw, &maxw);
    for (int i = minl; i <= maxl; ++i)
    {
        for (int j = minw; j <= maxw; ++j)
        {
            ans += candy(i, j);
        }
    }
    printf("%d", ans);
    return 0;
}

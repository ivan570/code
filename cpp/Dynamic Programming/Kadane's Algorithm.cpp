#include <iostream>

int maxSubarraySum(int arr[], int n)
{

    int ans = INT_MIN, cur = 0;
    for (int i = 0; i < n; ++i)
    {
        cur += arr[i];
        ans = std::max(ans, cur);
        cur = std::max(cur, 0);
    }
    return ans;
}

int main()
{
    int t, n;

    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            std::cin >> a[i];
        std::cout << maxSubarraySum(a, n) << std::endl;
    }
}

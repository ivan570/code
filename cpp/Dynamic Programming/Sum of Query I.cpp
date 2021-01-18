//Sum of Query I
#include <iostream>
#include <vector>
#include <utility>

void sumOfQuery(const std::vector<int> &vec, const std::vector<std::pair<int, int>> &query)
{
    for (const std::pair<int, int> &pair : query)
    {
        int ans = 0;
        for (int i = pair.first; i <= pair.second; ++i)
        {
            ans += ((i - pair.first + 1) * (i - pair.first + 1) * vec[i]);
        }
        std::cout << ans << " ";
    }
}

void test_case()
{
    int n;
    std::cin >> n;
    std::vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> vec[i];
    std::cin >> n;
    std::vector<std::pair<int, int>> query(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> query[i].first;
        std::cin >> query[i].second;
    }
    sumOfQuery(vec, query);
    std::cout << "\n";
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        test_case();
    return 0;
}
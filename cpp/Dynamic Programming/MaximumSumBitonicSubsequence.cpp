#include <iostream>
#include <algorithm>
#include <vector>

int getMaxBitonic(const std::vector<int> &vec)
{
    std::vector<int> inc(vec.size());
    std::vector<int> dec(vec.size());

    inc[0] = vec[0];
    for (int i = 1; i < vec.size(); ++i)
    {
        int ans = 0;
        for (int j = i - 1; j >= 0; --j)
        {
            if (vec[i] > vec[j])
                ans = std::max(ans, inc[j]);
        }
        inc[i] = ans + vec[i];
    }
    for (int i : inc)
        std::cout << i << " ";
    std::cout << std::endl;

    dec[dec.size() - 1] = vec[vec.size() - 1];
    for (int i = vec.size() - 2; i >= 0; --i)
    {
        int ans = 0;
        for (int j = vec.size() - 1; j > i; --j)
        {
            if (vec[i] > vec[j])
                ans = std::max(ans, dec[j]);
        }
        dec[i] = ans + vec[i];
    }
    for (int i : dec)
        std::cout << i << " ";
    std::cout << std::endl;

    int temp = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        int ans = 0;
        for (int j = i + 1; j < vec.size(); ++j)
            ans = std::max(ans, dec[j]);

        ans = std::max(ans, dec[i] - vec[i]);
        temp = std::max(temp, ans + inc[i]);
    }
    return temp;
}

void test_case()
{
    int size;
    std::cin >> size;
    std::vector<int> vec;
    for (int i = 0; i < size; ++i)
    {
        int temp;
        std::cin >> temp;
        vec.push_back(temp);
    }

    std::cout << getMaxBitonic(vec);
}

int main()
{
    int test;
    std::cin >> test;
    for (int i = 0; i < test; ++i)
        test_case();
    return 0;
}
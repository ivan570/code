// https://www.geeksforgeeks.org/painters-partition-problem/

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#define INT_MAX 99999999

std::unordered_map<std::string, int> map;
int timeToPaint(const std::vector<int> &arr, const int size, const int painter) {
    if (painter == 1)
        return std::accumulate(arr.begin(), arr.begin() + size, 0);
    else if (size == 1)
        return arr[0];
    else if (painter >= size)
        return *std::max_element(arr.begin(), arr.begin() + size);
    std::string str = std::to_string(size) + " " + std::to_string(painter);
    if (map.find(str) != map.end())
        return map[str];
    int value = INT_MAX;
    for (int i = 1; i < size; ++i) {
        int temp = std::max(timeToPaint(arr, i, painter - 1),
                            std::accumulate(arr.begin() + i, arr.begin() + size, 0));
        value = std::min(value, temp);
    }
    return map[str] = value;
}

void cases() {
    int painter, numberOfBoards;
    std::cin >> painter >> numberOfBoards;
    std::vector<int> arr(numberOfBoards);
    for (int i = 0; i < numberOfBoards; ++i)
        std::cin >> arr[i];
    map.clear();
    std::cout << timeToPaint(arr, numberOfBoards, painter) << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        cases();
    return 0;
}
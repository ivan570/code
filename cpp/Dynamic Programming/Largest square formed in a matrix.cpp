// https://www.geeksforgeeks.org/largest-square-in-a-binary-matrix-with-at-most-k-1s-for-multiple-queries/
#include <iostream>
#include <vector>

int getSquare(const std::vector<std::vector<int>> &arr, const int &rows, const int &columns) {
    std::vector<std::vector<int>> result(rows, std::vector<int>(columns));
    int max_value = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i == 0 || j == 0)
                result[i][j] = arr[i][j];
            else if (arr[i][j] == 0)
                result[i][j] = 0;
            else
                result[i][j] = std::min(result[i - 1][j], std::min(result[i][j - 1], result[i - 1][j - 1])) + 1;
            max_value = std::max(result[i][j], max_value);
        }
    }
    return max_value;
}

void cases() {
    int rows, columns;
    std::cin >> rows >> columns;
    std::vector<std::vector<int>> arr(rows, std::vector<int>(columns));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            std::cin >> arr[i][j];
    std::cout << getSquare(arr, rows, columns) << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        cases();
    return 0;
}
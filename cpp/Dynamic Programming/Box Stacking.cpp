// https://www.geeksforgeeks.org/box-stacking-problem-dp-22/
#include <vector>
#include <algorithm>
#include <iostream>

struct Box {
	int height, width, length;
};

bool fun(const Box& a, const Box& b) {
	return (a.length * a.width) < (b.length * b.width);
}

int maxHeight(int height[], int width[], int length[], int n)
{
	std::vector<Box> total;
	for (int i = 0; i < n; ++i) {
		total.emplace_back(Box{ height[i], std::max(width[i], length[i]), std::min(width[i], length[i]) });
		total.emplace_back(Box{ length[i], std::max(width[i], height[i]), std::min(width[i], height[i]) });
		total.emplace_back(Box{ width[i], std::max(height[i], length[i]), std::min(height[i], length[i]) });
	}
	std::sort(total.begin(), total.end(), fun);

	std::vector<int> answer(total.size());
	int max_value = -1;
	for (int i = 0; i < total.size(); ++i) {
		int ans = 0;
		for (int j = 0; j < i; ++j) {
			if ((total[i].width > total[j].width) && (total[i].length > total[j].length)) {
				ans = std::max(ans, answer[j]);
			}
 		}
		answer[i] = ans + total[i].height;
		max_value = std::max(answer[i], max_value);
	}
	return max_value;
}

int main() {
	Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
	int n = 4;
	int height[] = { 4, 1, 4, 10 };
	int width[] = { 6, 2, 5, 12 };
	int length[] = { 7, 3, 6, 32 };
	std::cout << std::endl << std::endl <<maxHeight(height, width, length, n) << std::endl;
	std::cin.get();
	return 0;
}

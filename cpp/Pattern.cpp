#include <iostream>

inline void ten() {
#ifndef ONLINE_JUDGE
	freopen("D:\\Sub\\input.txt", "r", stdin);
	freopen("D:\\Sub\\output.txt", "w", stdout);
#endif
}

inline void printPattern(int number) {
	int half = number / 2;
	for (int i = 0; i <= half; ++i) {
		for (int j = 0; j < half - i; ++j)
			std::cout << " ";
		for (int j = 0; j < 2 * i + 1; ++j) {
			if (j % 2 == 0)
				std::cout << "*";
			else
				std::cout << " ";
		}
		std::cout << "\n";
	}
}

void code() {
	int number;
	std::cin >> number;
	printPattern(number * 2 - 1);
	// std::cout << "\n";
}

int main() {
	ten();
	int count;
	std::cin >> count;
	for (int i = 0; i < count; ++i)
		code();

	return 0;
}
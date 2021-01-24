// https://codeforces.com/problemset/problem/112/A
#include <iostream>
#include <string>

inline void sublime_text_windows() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int compare(std::string &first, std::string &second) {
	for (int i = 0; i < (int) first.size(); ++i) {
		if (std::tolower(first[i]) > std::tolower(second[i])) 
			return 1;
		if (std::tolower(first[i]) < std::tolower(second[i])) 
			return -1;
	}
	return 0;
}

void code() {
	std::string first, second;
	std::cin >> first >> second;
	std::cout << compare(first, second) << std::endl;
}

int main() {
	sublime_text_windows();
	int count = 1;
	// std::cin >> count;
	for (int i = 0; i < count; ++i)
		code();

	return 0;
}
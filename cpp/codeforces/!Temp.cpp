#include <iostream>

inline void ten() {
#ifndef ONLINE_JUDGE
	freopen("D:\\Sub\\input.txt", "r", stdin);
	freopen("D:\\Sub\\output.txt", "w", stdout);
#endif
}

void code() {

}

int main() {
	ten();
	int count;
	std::cin >> count;
	for (int i = 0; i < count; ++i)
		code();

	return 0;
}
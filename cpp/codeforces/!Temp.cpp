#include <iostream>

inline void run() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void code() {

}

int main() {
	run();
	int count;
	std::cin >> count;
	for (int i = 0; i < count; ++i)
	{
		code();
	}
	return 0;
}
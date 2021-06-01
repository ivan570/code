#include <iostream>
#include <vector>

inline void ten() {
#ifndef ONLINE_JUDGE
	freopen("D:\\Sub\\input.txt", "r", stdin);
	freopen("D:\\Sub\\output.txt", "w", stdout);
#endif
}


int main() {
	ten();
	int n;
	std::cin >> n;
	int ans = -1;
	for (int i = 10; i >= 1; --i) {
		if (n % i == 0) {
			ans = i;
			break;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
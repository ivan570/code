// https://codeforces.com/contest/1476/problem/A

#include <iostream>
#include <cmath>

inline void ubuntu() {
#ifndef ONLINE_JUDGE
	freopen("/home/ivan/dev/input.txt", "r", stdin);
#endif
}

void code() {
	long long int n, k;
	std::cin >> n >> k;
	long double temp = k - (n % k);
	if (!(n % k))
		temp = 0;
	long long int max_number = std::ceil((temp/(long double)n));
	std::cout << 1 + max_number << std::endl;

}

int main() {
	ubuntu();

	int count;
	std::cin >> count;
	for (int i = 0; i < count; ++i)
		code();
	return 0;
}

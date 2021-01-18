#include <iostream>

void cases() {
	int x, y, s;
	std::cin >> x >> y;
	s = x + y;
	if (abs(x - y) > 1)
		s += (abs(x - y) - 1);
	std::cout << s << "\n";
}

int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		cases();
	return 0;
}
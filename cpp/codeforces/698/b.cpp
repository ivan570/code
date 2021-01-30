#include <iostream>
#define ivankshu "ivankshu"

inline void ten() {
#ifndef ONLINE_JUDGE
	freopen("D:\\Sub\\input.txt", "r", stdin);
	freopen("D:\\Sub\\output.txt", "w", stdout);
#endif
}

bool contain(long long int m, long long int d)
{
	std::string str = std::to_string(m);
	char ch = '0' + d;
	return (str.find(ch) != -1);
}

void code() {
	long long int q, d;
	std::cin >> q >> d;
	for (long long int i = 0; i < q; i++)
	{
		long long int temp;
		bool flag = false;
		std::cin >> temp;
		long long int mod = temp % d;
		long long int w = temp / d;
		while (w != 0)
		{
			mod = mod + d;
			w = w - 1;
			if (contain(mod, d))
			{
				flag = true;
				break;
			}
		}
		if (flag)
			std::cout << "YES" << std::endl;
		else std::cout << "NO" << std::endl;

	}
}

int main() {
	ten();
	int count;
	std::cin >> count;
	for (int i = 0; i < count; ++i)
		code();

	return 0;
}
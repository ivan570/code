// https://codeforces.com/problemset/problem/1470/A
<<<<<<< HEAD
// incomplete yet

#include <iostream>
#include <vector>

inline void sublime_text_windows() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void code() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> array(n);
	std::vector<int> c(m);
		
	for (int &value : array)
		std::cin >> value;

	for (int &value : c) 
		std::cin >> value;

	std::sort(array.rbegin(), array.rend());
	long long int ans = 0;
	for (int i = 0; i < n; ++i) {
		int ki = array[i];

	}
	std::cout << ans << "\n";
}

int main() {
	sublime_text_windows();
	int count;
	std::cin >> count;
	for (int i = 0; i < count; ++i)
		code();

	return 0;
}
=======
#include <iostream>
#include <vector>
#include <algorithm>
 
void party()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> k(n + 1), c(m + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> k[i];
 
    for (int i = 1; i <= m; ++i)
        std::cin >> c[i];
 
    int last = 1;
    long long int ans = 0;
    std::sort(k.rbegin(), k.rend());
    // for (int value : k)
    //     std::cout << value << " ";
    std::cout << "\n";
    for (int i = 0; i < n; ++i)
    {
        if (c[last] >= c[k[i]])
        {
            ans += c[k[i]];
            // std::cout << "i" << ans << " ";
        }
        else
        {
            ans += c[last];
            last++;
            // std::cout << "e" << ans << " ";
        }
    }
 
    std::cout << ans << "\n";
}
 
int main()
{
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i)
        party();
    return 0;
}
>>>>>>> 4d5e2325873a62d96d56368757deee5acf54bcba

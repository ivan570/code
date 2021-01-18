#include <bits/stdc++.h>

void whatTODO(int value) {
	std::cout << "value is " << value << " and it's hash table entry is " << value % 10 << std::endl;
}

void functionPointer(const std::vector<int> &v, void(*func)(int)) {
	for (int i : v)
		whatTODO(i);
}

int main() {
	std::vector<int> v = {1, 2, 3, 4, 5};

	functionPointer(v, whatTODO);

	return 0;
}
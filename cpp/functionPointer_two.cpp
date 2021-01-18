#include <bits/stdc++.h>
#include <functional>
using namespace std;

void whatTODO(int value) {
	std::cout << "value is " << value << " and it's hash table entry is " << value % 10 << std::endl;
}

void functionPointer(const std::vector<int> &vector, const std::function<void(int)> &func) {
	for (int i : vector)
		whatTODO((int)abs(i * rand() * 23000));
}

int main() {

	std::vector<int> v = {1, 2, 3, 4, 5};
	functionPointer(v, [](int value) {
		std::cout << "value is " << value << " and it's hash table entry is " << value % 10 << std::endl;
	});

	std::cout << "__Hello_World__" << std::endl;
	functionPointer(v, whatTODO);

	return 0;
}
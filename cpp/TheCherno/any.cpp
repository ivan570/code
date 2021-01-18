#include <iostream>
#include <any>


int main() {
	
	std::any type;
	type = 209;
	std::cout << std::any_cast<int> (type) << std::endl;

	std::cin.get();
	return 0;
}
#include <iostream>
#include <tuple>

int main() {

	std::tuple<int, int, int> tuple3 = std::make_tuple(23, 34, 45);
	std::cout << "tuple value " << std::endl;
	
	std::cout << "tuple value is" << std::endl;
	std::cout << std::get<0>(tuple3) << " " << std::get<1>(tuple3) << " " << std::get<2>(tuple3) << std::endl;

	return 0;
}
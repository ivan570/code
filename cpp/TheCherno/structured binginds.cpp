// structured binginds in c++17 and above
// to return multiple data value in function.
#include <iostream>
#include <tuple>
#include <string>

std::tuple<std::string, int> getData()
{
	return { "ivankshu", 20 };
}

int main() {

	auto [name, age] = getData();

	std::cout << name << " " << age << std::endl;

	return 0;
}
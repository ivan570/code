// multi typs of data in single variable in c++17

#include <iostream>
#include <variant>

int main() {
	std::variant<std::string, int> str_int;
	str_int = 90;

	std::cout << "get int value from variant " << std::get<int>(str_int) << std::endl;

	str_int = "ivankshu";
	std::cout << "get string value from vriant " << std::get<std::string>(str_int) << std::endl;

	std::cout << "trying to get wrong type value from variant " << std::endl;
	if (auto isvalid = std::get_if<std::string>(&str_int)) {
		std::cout << "the value is in the variant is " << *isvalid << std::endl;
	}
	else {
		std::cout << "the value is not type of 'int' " << std::endl;
	}

	std::cout << "size in variant " << std::endl;
	std::cout << "\tint size =><= " << sizeof(int) << std::endl;
	std::cout << "\tstring size =><= " << sizeof(std::string) << std::endl;
	std::cout << "\tvariant size =><= " << sizeof(str_int) << std::endl;
	std::cin.get();
	return 0;
}